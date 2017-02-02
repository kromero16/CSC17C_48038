/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Main implementation of a dynamic array class
 * Created on January 30, 2017, 1:46 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Array.h"

//Function Prototypes

//Begin Execution
int main(int argc, char** argv){
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //var to hold search results
    int sResult=0;
    char ch;
    int n;
    
    Array nArray(25);
    nArray.fill();  
    nArray.quicksort();
    nArray.print();
    
    /*do{
    cout<<"Enter a number to search for. \n";
    cin>>n;
   
    sResult=nArray.binary_search(n);
  
    if(sResult==-1)
        cout<<"Number was not found in array.\n\n";
    else
        cout<<"Number found in index: "<<sResult<<".\n\n";
    
    cout<<"Repeat Search? Y/N \n\n";
    cin>>ch;
    
    }while(ch!='n'&&ch!='N');*/
       
        
        
 
    
    //Exit Program
    return 0;
}

