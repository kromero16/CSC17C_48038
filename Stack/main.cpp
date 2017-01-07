/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Stack Using Linked List
 * Created on January 6, 2017, 12:30 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Stack.h"

//Begin Execution
int main(int argc, char** argv) {
    Stack<int> stack;
    stack.push(3);
    stack.push(3301);
    stack.push(33);
    stack.push(233);
    stack.push(34444);
    cout<<"Element Popped: "<<stack.pop()<<"\n";
    stack.push(99);
    stack.push(366);
    cout<<"Peeking Stack: "<<stack.peek()<<"\n";
    stack.print_stack();
    
    
    //Exit Program
    return 0;
}

