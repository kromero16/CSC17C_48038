/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Main Implementation of a Circular Linked List
 * Created on December 30, 2016, 9:04 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "CircularLinkedList.h"

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    
    CircularLinkedList<int> list;
    
    list.push_back(15);
    list.push_back(48);
    list.printList();
    
   
        
    

    
    //Exit Program
    return 0;
}

