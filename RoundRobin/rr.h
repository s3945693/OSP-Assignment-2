#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <iomanip>


#ifndef RR_H
#define RR_H

class RR{

    public:

        double avgWaitTime;
        double avgTurnaroundTime;
        double avgResponseTime;
        static std::ifstream in;
        static std::vector<int> processId;
        static std::vector<int> burstTime;
        static std::vector<int> waitTime;
        static std::vector<int> arrivalTime;
        static std::vector<int> tempBurstTime;
        static std::vector<int> responseTime;
        static std::vector<int> turnaroundTime;
        static int timeRR;

      
        RR(const std::string& inputfile, int timeRR);
        void calculateRoundRobin();
        void printResults();
        bool isNumber(std::string s);
};

#endif