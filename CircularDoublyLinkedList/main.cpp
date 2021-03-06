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
    
    list.push_front(0);
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_back(8);
    list.push_back(7);
    list.deleteAt(1);
    list.push_back(43);
    //list.reverse_List();
    list.printList();
    
   
        
    

    
    //Exit Program
    return 0;
}

