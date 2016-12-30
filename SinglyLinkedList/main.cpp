/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Main Implementation of a Singly Linked List
 * Created on December 21, 2016, 5:18 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//User Libraries
#include "LinkedList.h"

//Begin Execution
int main(int argc, char** argv){
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Create Linked list
    LinkedList<int> list;

    //Fill
    cout<<"Pushing Data: \n\n";
    int s=5;
    for(int i=0;i<s;i++){
        while(s>0)list.push_back(s--);
    }
    
    list.push_back(999);
    list.push_front(67);
    list.push_front(69);
    list.push_back(66);
    
    int n=list.getNumNodes();
    cout<<"Number of Nodes was: "<<n<<".\n\n";
    
    list.printList();
    
    list.removeNthNode(0);
    list.removeNthNode(4);
    list.pushAt(13,6);
  
    //Print
    list.printList();
    
    list.reverseList();
    list.printList();


    
    
    //Exit Program
    return 0;
}

