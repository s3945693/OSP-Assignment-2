#include "fifo.h"

std::ifstream FIFO::in;

std::vector<int> FIFO::waitTime;
std::vector<int> FIFO::burstTime;
std::vector<int> FIFO::processId;

FIFO::FIFO(const std::string& inputfile){
    
    avgWaitTime = 0;
    avgTurnaroundTime = 0;
    avgResponseTime = 0;
    in.open(inputfile);
    if(!in){
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }

    while (!in.eof()){
        int id, burst;
        std::string line;
        //get the line
        while (std::getline(in,line)){
            
            //get the id
            std::string idstr = line.substr(0,line.find(","));
            id = std::stoi(idstr);
            //get the burst time
            std::string burststr = line.substr(line.find(",")+1);
            burst = std::stoi(burststr);

            //append to respective vectors 
            processId.push_back(id);
            burstTime.push_back(burst);
            waitTime.push_back(0);

        }
        
    }

}

void FIFO::calculateResponseTime(){

    int waitTimeTotal = 0;
    for( std::vector<int>::size_type i = 1; i < burstTime.size(); i++){
        waitTime[i] = burstTime[i-1]+waitTime[i-1];
    }
    for(std::vector<int>::size_type i = 0; i < waitTime.size(); i++){
        waitTimeTotal += waitTime[i];
    }

    avgResponseTime = (double)waitTimeTotal/waitTime.size();


}

void FIFO::calculateTurnaroundTime(){

    int totalTurnaroundTime = 0;

    for (std::vector<int>::size_type i = 0; i < burstTime.size(); i++){
        totalTurnaroundTime += (burstTime[i]+waitTime[i]);
    }

    avgTurnaroundTime = (double)totalTurnaroundTime/burstTime.size();


}

void FIFO::calculateWaitTime(){


    int waitTimeTotal = 0;
    for( std::vector<int>::size_type i = 1; i < burstTime.size(); i++){
        waitTime[i] = burstTime[i-1]+waitTime[i-1];
    }
    for(std::vector<int>::size_type i = 0; i < waitTime.size(); i++){
        waitTimeTotal += waitTime[i];
    }


    avgWaitTime = (double)waitTimeTotal/waitTime.size();

}

void FIFO::printResults(){

    std::cout << "FIFO" << std::endl;
    std::cout << "Average Wait Time: " << avgWaitTime << std::endl;
    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;

}