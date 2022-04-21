#ifndef FILE_STATS_H
#define FILE_STATS_H

#include <fstream>
#include <exceptions.h>
#include <cstddef>
#include <map>
#include <filesystem>
#include <iostream>

class FileStats{
    private:
        int size = 0;
        std::string type = "";
    public:
        FileStats(const std::string &filename);
        std::string getType() const;
        int getSize() const;
};

class DirStats{
    private:
        std::map<std::string, int> fileStats;
        int files = 0;
        int folders = 1;
        int sumLength = 0;
    public:
        DirStats(const std::string &dirname, const std::string &wildcard);
        DirStats &operator +=(const DirStats &dir);
        DirStats &operator +=(const std::pair<std::string, int> &type);
        DirStats &operator +=(const FileStats &file);
        DirStats sumNoFolder(const DirStats &dir);
        friend std::ostream &operator << (std::ostream &os, const DirStats &dir) noexcept;
};


#endif