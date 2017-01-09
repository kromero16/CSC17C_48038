/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Main Implementation of a Queue using a Linked List
 * Created on January 7, 2017, 9:01 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Queue.h"

//Begin Execution
int main(int argc, char** argv) {
    
    Queue<int> queue;
    queue.enqueue(4);
    queue.enqueue(60);
    queue.enqueue(20);
    queue.dequeue();
    cout<<"\n Peeking: "<<queue.peek()<"\n";
    queue.print();
    
    
    //End Program
    return 0;
}

