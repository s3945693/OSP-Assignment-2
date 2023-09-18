#include <iostream>
#include <fstream>
#include <string>
#include <queue>


#ifndef HANDLEDATA_H
#define HANDLEDATA_H

class HandleData{

    public:
        static std::ifstream in;

        static std::deque<int> processId;
        static std::deque<int> burstTime;

        HandleData(const std::string& inputfile);


};

#endif