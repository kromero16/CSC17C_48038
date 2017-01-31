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
    HashTable<string> table;
    
    string myString="Kevin";
    string myString2="kevin";
    string mString="keviN";
    
    cout<<"Hashing String: "<<myString<<"\n";
    int hash=table.nHash(myString);
    cout<<"Hashed Index: "<<hash<<"\n\n";
    
    
    //table.push(myString);
    
    cout<<"Printing contents in table: \n";
    for(int i=0;i<TABLE_SIZE;i++){
        cout<<table.getIndx(i)<<"\n";
    }
    
    
    
    //Exit Program 
    return 0;
}