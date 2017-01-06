/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: main implementation of a Circular Linked List
 * Created on January 5, 2017, 9:18 AM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "CircularLinkedList.h"

//Begin Execution
int main(int argc, char** argv) {

    CircularLinkedList<int> list;
   list.push_back(1);
   list.push_back(54);
    list.push_back(33);
    list.push_back(2);
    list.push_Front(233);
    list.push_Front(13);
    list.printList();
    cout<<"# of Elements: "<<list.nodeCount()<<"\n\n";
    
    //Exit Program
    return 0;
}

