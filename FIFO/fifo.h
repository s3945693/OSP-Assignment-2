#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

#ifndef FIFO_H
#define FIFO_H

class FIFO{

    public:

        double avgWaitTime;
        double avgTurnaroundTime;
        double avgResponseTime;
        static std::ifstream in;
        static std::vector<int> processId;
        static std::vector<int> burstTime;
        static std::vector<int> waitTime;

      
        FIFO(const std::string& inputfile);
        void calculateWaitTime();
        void calculateTurnaroundTime();
        void calculateResponseTime();
        void printResults();

};

#endif