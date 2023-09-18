#include "fifo.h"

FIFO::FIFO(const std::string& inputfile){
    hd = HandleData(inputfile);
    avgWaitTime = 0;
    avgTurnaroundTime = 0;
    avgResponseTime = 0;
}

void FIFO::calculateResponseTime(){

    

}

void FIFO::calculateTurnaroundTime(){

}

void FIFO::calculateWaitTime(){

    std::deque<int> burstTime = hd.burstTime;
    std::deque<int> processId = hd.processId;

    int waitTime = 0;

    for (int i = 0; i < burstTime.size()-1; i++){
        waitTime += burstTime[i];
    }

    avgWaitTime = waitTime / burstTime.size();

}