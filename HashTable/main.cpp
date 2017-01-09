/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Main Implementation of a Hash Table using Linked List Closed Addressing
 * Created on January 9, 2017, 2:15 PM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//User Libraries
#include "HashTable.h"

//Begin Execution
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    HashTable<int> hTable;
    int s=100000;
    for(int i=0;i<s;i++){
        int r=rand();
        hTable.push(i,r);
    }

    
    for(int i=0;i<s;i++){
        cout<<hTable.pop(i)<<"\n";
    }
    
    
    //Exit Program
    return 0;
}

