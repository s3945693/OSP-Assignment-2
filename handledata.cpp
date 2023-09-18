#include "handledata.h"

HandleData::HandleData(const std::string& inputfile){
    
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

            //append to respective queues
            processId.push_back(id);
            burstTime.push_back(burst);

        }
        processId.push_back(id);
        burstTime.push_back(burst);
    }
    
}