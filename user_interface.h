#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include<iostream>

class UserInterface
{
    public:
        const std::string COLOR_RESET = "\033[0m";
        const std::string COLOR_BOLD = "\033[1m";
        const std::string COLOR_UNDERLINE = "\033[4m";
        const std::string COLOR_RED = "\033[31m";
        const std::string COLOR_GREEN = "\033[32m";
        const std::string COLOR_YELLOW = "\033[33m";
        const std::string COLOR_BLUE = "\033[34m";
        
        void print(std::string text){std::cout<<text;}
        void print(std::string text, std::string color){ std::cout<<color<<text<<COLOR_RESET; }
        void printLine(){std::cout<<COLOR_BOLD<<"-----------"<<COLOR_RESET<<std::endl;}
};
#endif