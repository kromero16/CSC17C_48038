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
    
    string name="Kevin";
    string number="9515302775";
    string name1="kevin";
    string num1="9515094562";
    table.push(name,number);
    table.push(name1,num1);
    table.push("Anthony","9094856254");
    string n="mark";
    table.sequential_search("Anthony");
    
    //Exit Program 
    return 0;
}