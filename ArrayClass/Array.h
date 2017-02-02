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
    int heapSize;
    int *array;
    
    //Private member functions
    int *push(int);                
    void mergeSort(int,int);   
    
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
    
    //Main Heap Sort
    void heapSort(){
        build_heap();
        for(int i=SIZE;i>=2;i--){   //check >= or <=
            swap(array[1],array[i]);
            heapSize=heapSize-1;
            max_heapify(1);
        }
    }
    
    //Heap Sort Helper Functions
    void max_heapify(int);
    void build_heap();
    
    //merge sort
    void merge_sort(){
        mergeSort(0,SIZE-1);
    }
    
    //Merge function 
    void merge(int p,int q,int r){
        int n1=q-p+1;
        int n2=r-q;
        int L[n1+1];
        int R[n2+1];
        
        //Copy contents
        for(int i=1;i<=n1;i++){
            L[i]=array[p+i-1];
        }
        for(int j=1;j<=n2;j++){
            R[j]=array[q+j];
        }
        
        //add sentinels
        L[n1+1]=999;
        R[n2+1]=999;
        
        int i=1, j=1;
        for(int k=p;k<=r;k++){
            if(L[i]<=R[j]){
                array[k]=L[i];
                i=i+1;
            }
            else{
                array[k]=R[j];
                j=j+1;
            }
        }
    }
    
    //Insertion sort
    void insertion_sort(){
        for(int i=0;i<SIZE;i++){
            int j=i;
            while(j>0&&array[j-1]>array[j]){
                swap(array[j],array[j-1]);
                j--;
            }
        }
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
    void swap(int &a,int &b){
        int tmp;
        tmp=a;
        a=b;
        b=tmp;
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
        heapSize=SIZE;
        array=new int[SIZE];
    }
    
    //Destructor
    ~Array(){
        delete []array;
    }
};



#endif /* ARRAY_H */

