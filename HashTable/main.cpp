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
    

    table.push("ken","9515302775");
    table.push("Ken","9094561234");
    table.push("kEn","6194528548");
    table.push("keN","4895024513");
    table.push("KEN","3285412685");
    table.push("Cristal","9515302456");
    table.sequential_search("ken");
    table.sequential_search("Ken");
    cout<<table.hash("ken")<<"\n";
    cout<<table.hash("Ken")<<"\n";
    cout<<table.hash("kEn")<<"\n";
    
    
 
 
 
    
    //Exit Program 
    return 0;
}