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

    
    //Fill List
    int s=5;
    for(int i=0;i<s;i++){
        while(s>0)list.push_back(s--);
    }
    list.push_back(999);
    list.push_front(67);
    list.push_front(69);
    list.push_back(66);
  
    //Print
    list.printList();cout<<"\n\n";
    
    //sort
    cout<<"Sorting the Linked List: \n";
    list.sort();
    list.printList();
    
    //Get number of nodes
    int n=list.getNumNodes();
    cout<<"Number of Nodes was: "<<n<<".\n\n";



    
    
    //Exit Program
    return 0;
}

