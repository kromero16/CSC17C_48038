/* 
 * File:   main.cpp
 * Author: Kevin Romero
 * Purpose: Dynamically Resize Array
 * Created on November 11, 2016, 10:53 AM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Function Prototypes
void fillAry(int *,int);
void prntAry(int *,int);
int *push_back(int *,int &,int &,int);

//Begin Execution
int main(int argc, char **argv){
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int size=22;
    int maxSize=size;
    int val=13;
    
    //Create array and Fill
    int *array=new int[size];
    fillAry(array,size);
    
    //Print array
    cout<<"Array before pushing element:"<<endl<<endl;
    prntAry(array,size);
    
    //Push element;
    array=push_back(array,size,maxSize,val);
    
    //Print
    cout<<"Array after pushing element "<<val<<" : "<<endl<<endl;
    prntAry(array,size);
    
    //Exit Program
    return 0;
}

//Push element to end of array
int *push_back(int *a,int &s,int &max,int val){
    if(max==s){
        
        //Double the size
        max*=2;
        
        //Create new array and fill
        int *b=new int[max];
        for(int i=0;i<s;i++){
            b[i]=a[i];
        }
          //Add element to end
          b[s++]=val;
              
        //Return new array
        return b;
        
        //deallocate memory
        delete []b;
    }else{
        int *b=new int[s+1];
        b[s++]=val;
            
        //Return new array
        return b;
        
        //deallocate memory
        delete []b;
    }
         
    }

//Print an Array
void prntAry(int *a,int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }cout<<endl<<endl;
}                                           

//Fill an array
void fillAry(int *a,int s){
       for(int i=0;i<s;i++){
        a[i]=rand()%90+10;
    }
}