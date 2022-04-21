#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <cstring>
#include <exception>

class ExceptionBase : public std::exception{
    protected:
        std::string exceptionInfo;
    public:
        ExceptionBase(std::string filename, std::string classname, std::string methodname, int line){
            exceptionInfo = "In file " + filename +
            "\nIn class " + classname +
            "\nIn method " + methodname +
            "\nOn line " + std::to_string(line) + "\n";
        }

        virtual const char *what() const noexcept override{
            std::string message = "RECIEVED AN EXCEPTION:\n" + exceptionInfo;
            char *cmes = new char[message.size() + 1];
            std::strcpy(cmes, message.c_str());
            return cmes;
        }
};

class FileOpenException : ExceptionBase{
    public:
        FileOpenException(std::string filename, std::string classname, std::string methodname, int line) :
            ExceptionBase(filename, classname, methodname, line) {};

        virtual const char *what() const noexcept override{
            std::string message = "RAN INTO EXCEPTION WHEN OPENING FILE:\n" + exceptionInfo;
            char *cmes = new char[message.size() + 1];
            std::strcpy(cmes, message.c_str());
            return cmes;
        }
};

#endif