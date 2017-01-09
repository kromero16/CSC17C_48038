/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Main Implementation of a Priority Queue
 * Created on January 7, 2017, 10:23 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "PriorityQueue.h"

//Begin Execution
int main(int argc, char** argv) {

    PriorityQueue<int> queue;
    queue.enqueue(13,3);
    queue.enqueue(12,3);
    queue.enqueue(122,2);
    queue.enqueue(242,1);
    queue.print();
    queue.dequeue();
    queue.print();
    
    //Exit Program
    return 0;
}

