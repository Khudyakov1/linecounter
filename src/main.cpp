#include <filestats.h>
#include <iostream>
#include <string>
#include <cstring>


void printUsage(){
    std::cout << "Usage:\n";
    std::cout << "linecounter --help  -  print this text\n";
    std::cout << "linecounter  -  scan all files in local directory\n";
    std::cout << "linecounter <dir>  -  scan all files in dir (use \".\" for local dir)\n";
    std::cout << "linecounter <dir> <wildcard>  -  scan files matching the wildcard\n";
}

int main(int argc, char *argv[]) {
    if (argc == 1)
        std::cout << DirStats(".", "*");
    else if (argc == 2 && !strcmp(argv[1], "--help"))
        printUsage();
    else if (argc == 2)
        std::cout << DirStats(std::string(argv[1]), "*");
    else if (argc == 3)
        std::cout << DirStats(std::string(argv[1]), std::string(argv[2]));
    return 0;
}