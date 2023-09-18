#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "handledata.h" 

#ifndef FIFO_H
#define FIFO_H

class FIFO{

    public:

        static HandleData hd;
        double avgWaitTime;
        double avgTurnaroundTime;
        double avgResponseTime;

        FIFO(const std::string& inputfile);
        void calculateWaitTime();
        void calculateTurnaroundTime();
        void calculateResponseTime();
        void printResults();

};

#endif