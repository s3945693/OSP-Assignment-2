#include "fifo.h"

int main(int argc, char** argv){

    FIFO fifo = FIFO(argv[1]);
    fifo.calculateWaitTime();
    fifo.calculateTurnaroundTime();
    fifo.calculateResponseTime();
    fifo.printResults();

    return 0;
}