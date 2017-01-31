/* 
 * File:   Array.h
 * Author: Kevin Romero
 * Purpose: Array Class
 * Created on January 30, 2017, 1:47 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

class Array{
private:
    int SIZE;
    int maxSize;
    int *array;
    
    //Private member functions
    int *push(int);                 //Defined in Array.cpp
    
public:
    
    //Binary search
    int binary_search(int n){
        int min=0;
        int max=SIZE-1;
        int mid=(max+min)/2;
        
        while(min<=max){
            if(array[mid]<n){
                min=mid+1;
            }
            else if(array[mid]==n){
                return mid+1;
                break;
            }
            else{
                max=mid-1;
            }
            mid=(max+min)/2;
    }
        if(min>max)
            return -1;
    }
    
    //sequentially search and return index
    int sequential_search(int n){
        int indx;
        bool found=false;
        
        while((!found)&&(indx<SIZE)){
            if(n==array[indx])
                found=true;
            else
                indx++;
        }
        if(found==false)
            return -1;
        else
            return indx;
    }
    
    //Selection sort
    void selection_sort(){
        int minElem,tmp;
        
        for(int i=0;i<SIZE-1;i++){
            //Set starting element a[0]
            minElem=i;
            
            for(int j=i+1;j<SIZE;j++)
                if(array[j]<array[minElem])
                    minElem=j;
            
            if(minElem!=i){
                swap(array[i],array[minElem]);
            }
           
        }
        
    }
    
    //Swap function 
    void swap(int &v1,int &v2){
        int tmp;
        tmp=v1;
        v1=v2;
        v2=tmp;
    }
    
    //Push data
    void push_back(int n){
        array=push(n);
    }
    
    //Print array contents
    void print(){
        for(int i=0;i<SIZE;i++){
            cout<<"Index "<<i+1<<": "<<array[i]<<" \n";
        }cout<<"\n\n";
    }
    
    //Fill array with random numbers
    void fill(){
        for(int i=0;i<SIZE;i++){
            array[i]=rand()%999+1;  //1-999
        }
    }
    
    //Default Constructor
    Array(int s){
        SIZE=s;
        maxSize=SIZE;
        array=new int[SIZE];
    }
    
    //Destructor
    ~Array(){
        delete []array;
    }
};



#endif /* ARRAY_H */

