#include <filestats.h>
#include <bits/stdc++.h>
#include <wildcards.h>

FileStats::FileStats(const std::string &filename){
    std::ifstream file(filename, std::ifstream::in);
    if (!file.is_open())
        throw FileOpenException(__FILE__, typeid(FileStats).name(), __FUNCTION__, __LINE__);
    
    std::string noPath;
    if (filename.find('/') != std::string::npos)
        noPath = filename.substr(filename.rfind('/'), filename.length() - 1);
    else
        noPath = filename;
    if (noPath.find(".") != std::string::npos)
        this->type = noPath.substr(noPath.rfind("."), noPath.length() - 1);
    else
        this->type = "No type";

    std::string line;
    this->size = 0;
    for (this->size = 0; !file.eof(); getline(file, line), this->size++);
    file.close();
}
std::string FileStats::getType() const{
    return this->type;
}
int FileStats::getSize() const{
    return this->size;
}

DirStats::DirStats(const std::string &dirname, const std::string &wildcard){
    for (const auto& entry : std::filesystem::directory_iterator(dirname)) {
        const auto filenameStr = entry.path().filename().string();
        if (entry.is_directory()) {
            DirStats dir(entry.path(), wildcard);
            *this += dir;
        }
        else if (entry.is_regular_file() && stringsMatch(wildcard, entry.path().filename())) {
            FileStats file(entry.path());
            *this += file;    
        }
    }
}
DirStats &DirStats::operator +=(const DirStats &dir){
    for (auto type : dir.fileStats)
        *this += type;
    this->folders += dir.folders;
    this->files += dir.files;
    this->sumLength += dir.sumLength;
    return *this;
}
DirStats &DirStats::operator +=(const std::pair<std::string, int> &type){
    if (this->fileStats.find(type.first) != this->fileStats.end())
        this->fileStats[type.first] += type.second;
    else
        this->fileStats[type.first] = type.second;
    return *this;
}
DirStats &DirStats::operator +=(const FileStats &file){
    if (this->fileStats.find(file.getType()) != this->fileStats.end())
        this->fileStats[file.getType()] += file.getSize();
    else
        this->fileStats[file.getType()] = file.getSize();
    this->files++;
    this->sumLength += file.getSize();
    return *this;
}
int comparePairs(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b){
    return b.second - a.second;
}

std::ostream &operator << (std::ostream &os, const DirStats &dir) noexcept{
    std::map<int, std::string> sorted;
    for (auto type : dir.fileStats)
        sorted.emplace(type.second, type.first);
    os << "Checked " << dir.folders << " directories\n";
    os << "Checked " << dir.files << " files\n";
    os << "Read " << dir.sumLength << " lines\n";
    os << "Stats by filetypes:\n";
    for (auto type : sorted)
        os << "Type: \"" << type.second << "\" Lines: "<< type.first
         << " Percentage: " << type.first * 100 / dir.sumLength << "%\n";
    return os;
}