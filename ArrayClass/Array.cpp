/*
 * File: Array.cpp
 * Name: Kevin Romero
 * Purpose: Implementation of Array.h
 * Date: January 30, 2017
 */

//User Libraries
#include "Array.h"

//Implement private merge sort helper function
void Array::mergeSort(int p, int r){
        int q;
        if(p<r){
            q=(p+r)/2;
            mergeSort(p,q);
            mergeSort(q+1,r);
            merge(p,q,r);
        }
}

//Implement private push function
int *Array::push(int n){
    if(maxSize==SIZE){
            //Double the size
            maxSize*=2;
            
            //Create new array and fill
            int *bArr=new int[maxSize];
            
            //copy array contents
            for(int i=0;i<SIZE;i++){
                bArr[i]=array[i];
            }
            
            //push data
            bArr[SIZE++]=n;
            
            //Return new array and deallocate memory
            return bArr;
            delete []bArr;
            
        }
        else{
            //Create new array one element larger
            int *bArr=new int[SIZE+1];
            
            //Copy array contents
            for(int i=0;i<SIZE;i++){
                bArr[i]=array[i];
            }
            
            //Add element to end
            bArr[SIZE++]=n;
            
            //Return array and deallocate memory
            return bArr;
            delete []bArr;
        }
}