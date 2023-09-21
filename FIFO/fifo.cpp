#include "fifo.h"

std::ifstream FIFO::in;

std::vector<int> FIFO::waitTime;
std::vector<int> FIFO::burstTime;
std::vector<int> FIFO::processId;
std::vector<int> FIFO::turnaroundTime;
std::vector<int> FIFO::responseTime;

FIFO::FIFO(const std::string& inputfile){
    
    avgWaitTime = 0;
    avgTurnaroundTime = 0;
    avgResponseTime = 0;
    in.open(inputfile);
    if(!in){
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }

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
        turnaroundTime.push_back(0);
        responseTime.push_back(0);

    }
        
    

}

void FIFO::calculateResponseTime(){

    int responseTimeTotal = 0;
    for( std::vector<int>::size_type i = 1; i < burstTime.size(); i++){
        responseTime[i] = burstTime[i-1]+waitTime[i-1];
    }
    for(std::vector<int>::size_type i = 0; i < waitTime.size(); i++){
        responseTimeTotal += responseTime[i];
    }

    avgResponseTime = (double)responseTimeTotal/waitTime.size();


}

void FIFO::calculateTurnaroundTime(){

    int totalTurnaroundTime = 0;

    for (std::vector<int>::size_type i = 0; i < burstTime.size(); i++){
        totalTurnaroundTime += (burstTime[i]+waitTime[i]);
        turnaroundTime[i] = burstTime[i]+waitTime[i];
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
    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Wait Time: " << avgWaitTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;

}