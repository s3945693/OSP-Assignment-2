#include "sjf.h"

int main(int argc, char** argv){

    SFJ sfj = SFJ(argv[1]);
    sfj.calculateWaitTime();
    sfj.calculateTurnaroundTime();
    sfj.calculateResponseTime();
    sfj.printResults();

    return 0;
}