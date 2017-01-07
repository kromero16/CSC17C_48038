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
    stack.pop();
    stack.print_stack();
    
    
    //Exit Program
    return 0;
}

