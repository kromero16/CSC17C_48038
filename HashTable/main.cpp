/*
 * Name: Kevin Romero
 * Purpose: Main Implementation of a Hash Table using Linked List Chaining
 * Date: January 27, 2017
 * 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//User Libraries
#include "HashTable.h"

//Begin Execution
int main(int argc, char **argv){
    //test
    HashTable table;
    
    string myString="Kevin";
    string myString2="kevin";
    string mString="keviN";
    
    table.push(myString);
    table.push(myString2);
    table.push(mString);
    
    
    //Exit Program 
    return 0;
}