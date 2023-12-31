#include "sjf.h"

std::ifstream SFJ::in;

std::vector<int> SFJ::waitTime;
std::vector<int> SFJ::burstTime;
std::vector<int> SFJ::processId;
std::vector<int> SFJ::turnaroundTime;
std::vector<int> SFJ::responseTime;

SFJ::SFJ(const std::string& inputfile){
    
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
        if(!isNumber(idstr)){
            std::cout << "Error: Process id must be a number" << std::endl;
            exit(1);
        }
        id = std::stoi(idstr);
        //get the burst timeRR
        std::string burststr = line.substr(line.find(",")+1);
        if(!isNumber(burststr)){
            std::cout << "Error: Burst time must be a number" << std::endl;
            exit(1);
        }
        burst = std::stoi(burststr);

        //append to respective vectors 
        processId.push_back(id);
        burstTime.push_back(burst);
        waitTime.push_back(0);
        turnaroundTime.push_back(0);
        responseTime.push_back(0);

    }
        
    //sorting the array for shortest job first
    
    int pos,temp,i,j,n;
    n=burstTime.size();
    for(i=0;i<n;i++){
        pos=i;

        for(j=i+1;j<n;j++){
            if(burstTime[j]<burstTime[pos])
                pos=j;
        }

        temp=burstTime[i];
        burstTime[i]=burstTime[pos];
        burstTime[pos]=temp;
        temp=processId[i];
        processId[i]=processId[pos];
        processId[pos]=temp;
    }

}

void SFJ::calculateResponseTime(){

    int responseTimeTotal = 0;
    for( std::vector<int>::size_type i = 1; i < burstTime.size(); i++){
        responseTime[i] = burstTime[i-1]+responseTime[i-1];
    }
    for(std::vector<int>::size_type i = 0; i < waitTime.size(); i++){
        responseTimeTotal += responseTime[i];
    }

    avgResponseTime = (double)responseTimeTotal/waitTime.size();


}

void SFJ::calculateTurnaroundTime(){

    int totalTurnaroundTime = 0;

    for (std::vector<int>::size_type i = 0; i < burstTime.size(); i++){
        totalTurnaroundTime += (burstTime[i]+waitTime[i]);
        turnaroundTime[i] = burstTime[i]+waitTime[i];
    }

    avgTurnaroundTime = (double)totalTurnaroundTime/burstTime.size();


}

void SFJ::calculateWaitTime(){


    int waitTimeTotal = 0;
    for( std::vector<int>::size_type i = 1; i < burstTime.size(); i++){
        waitTime[i] = burstTime[i-1]+waitTime[i-1];
    }
    for(std::vector<int>::size_type i = 0; i < waitTime.size(); i++){
        waitTimeTotal += waitTime[i];
    }


    avgWaitTime = (double)waitTimeTotal/waitTime.size();

}

void SFJ::printResults(){

    std::cout << "SFJ" << std::endl;

    std::cout << std::left << std::setw(15) << "Process ID" 
              << std::setw(15) << "Burst Time" 
              << std::setw(20) << "Turnaround Time" 
              << std::setw(15) << "Waiting Time" 
              << std::setw(15) << "Response Time" 
              << std::endl;

    // Iterate through the vectors and print values for each process
    for (std::vector<int>::size_type i = 0; i < processId.size(); i++) {
        std::cout << std::left << std::setw(15) << processId[i] 
                  << std::setw(15) << burstTime[i] 
                  << std::setw(20) << turnaroundTime[i]
                  << std::setw(15) << waitTime[i] 
                  << std::setw(15) << responseTime[i] 
                  << std::endl;
    }

    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Wait Time: " << avgWaitTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;

}

bool SFJ::isNumber(std::string s){
    std::string::const_iterator it = s.begin();
    char dot = '.';
    int nb_dots = 0;
    while (it != s.end()) 
    {
        if (*it == dot)
        {
            nb_dots++;
            if (nb_dots>1)
            {
                break;
            }
        }   
        else if (!isdigit(*it))
        {
            break;
        } 

        ++it;
    }
    return !s.empty() && s[0] != dot && it == s.end();
}