#include "rr.h"

std::ifstream RR::in;
std::vector<int> RR::processId;
std::vector<int> RR::burstTime;
std::vector<int> RR::waitTime;
std::vector<int> RR::arrivalTime;
std::vector<int> RR::tempBurstTime;
int QUANTUMS = 1;
int timeRR = 10; //10-100
int ARRIVALTIME = 0;
int totalWaitTime = 0;
int totalTurnaroundTime = 0;
//TODO: TEST WITH DIFFERENT TIME QUANTUMS, USE A VARIABLE FOR THIS


RR::RR(const std::string& inputfile){

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
        //get the burst timeRR
        std::string burststr = line.substr(line.find(",")+1);
        burst = std::stoi(burststr);

        //append to respective vectors 
        processId.push_back(id);
        burstTime.push_back(burst);
        waitTime.push_back(0);
        arrivalTime.push_back(0);
        tempBurstTime.push_back(burst);


    }
        
    

}


void RR::calculateRoundRobin(){
    int total = 0;
    int n = processId.size();
    int i;
    bool done = true;
    while(done){
        bool empty = true;
        for(i = 0; i < n; i++){

            if (tempBurstTime[i] > 0 ){
                empty = false;
            }

            if(tempBurstTime[i] > 0){
                if(tempBurstTime[i] > timeRR){
                    total += timeRR;
                    tempBurstTime[i] -= timeRR;
                }
                else{
                    total += tempBurstTime[i];
                    waitTime[i] = total - burstTime[i];
                    tempBurstTime[i] = 0;
                }
            }
        }
        if(empty){
            done = false;
        }
    }

    for(int i = 0; i < n; i++){
        totalWaitTime += waitTime[i];
        totalTurnaroundTime += waitTime[i] + burstTime[i];
    }


}

void RR::printResults(){

    avgResponseTime = (double)totalWaitTime/processId.size();
    avgTurnaroundTime = (double)totalTurnaroundTime/processId.size();
    avgWaitTime = (double)totalWaitTime/processId.size();

    std::cout << "Round Robin" << std::endl;
    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Wait Time: " << avgWaitTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;

}