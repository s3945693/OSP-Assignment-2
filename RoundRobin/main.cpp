#include "rr.h"

int main(int argc, char** argv){

    RR rr = RR(argv[1]);
    rr.calculateRoundRobin();
    rr.printResults();

    return 0;
}