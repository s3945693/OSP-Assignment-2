#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <iomanip>
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
        static std::vector<int> turnaroundTime;
        static std::vector<int> responseTime;

      
        FIFO(const std::string& inputfile);
        void calculateWaitTime();
        void calculateTurnaroundTime();
        void calculateResponseTime();
        void printResults();
        bool isNumber(std::string s);

};

#endif