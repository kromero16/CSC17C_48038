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
    
    string key="Kevin";
    string value="9515302775";
    
    table.push(key,value);
    cout<<table.get(key)<<"\n";

    
    //Exit Program 
    return 0;
}