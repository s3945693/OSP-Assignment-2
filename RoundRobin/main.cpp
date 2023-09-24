#include "rr.h"

bool isNumber(std::string s);

int main(int argc, char** argv){

    if (argc != 3)
    {
        std::cout << "Usage: ./rr <time quantum> <input file>" << std::endl;
        exit(1);
    }

    if (!isNumber(argv[1]))
    {
        std::cout << "Time quantum must be a number" << std::endl;
        exit(1);
    }

    int amount = std::stoi(argv[1]);
    RR rr = RR(argv[2], amount);
    rr.calculateRoundRobin();
    rr.printResults();

    return 0;
}

bool isNumber(std::string s){
    std::string::const_iterator it = s.begin();
    char dot = '.';
    int nb_dots = 0;
    while (it != s.end()) 
    {
        if (*it == dot)
        {
            nb_dots++;
            if (nb_dots>1)
            {
                break;
            }
        }   
        else if (!isdigit(*it))
        {
            break;
        } 

        ++it;
    }
    return !s.empty() && s[0] != dot && it == s.end();
}