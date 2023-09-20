#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

#ifndef SJF_H
#define SJF_H

class SFJ{

    public:

        double avgWaitTime;
        double avgTurnaroundTime;
        double avgResponseTime;
        static std::ifstream in;
        static std::vector<int> processId;
        static std::vector<int> burstTime;
        static std::vector<int> waitTime;

      
        SFJ(const std::string& inputfile);
        void calculateWaitTime();
        void calculateTurnaroundTime();
        void calculateResponseTime();
        void printResults();

};

#endif