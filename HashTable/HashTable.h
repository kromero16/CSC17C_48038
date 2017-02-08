/*
 * Name: Kevin Romero
 * Purpose: Hash Table using Linked List Chaining
 * Date: January 27, 2017 
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "Node.h"

//Global Variables
const int TABLE_SIZE=128;

//Create Table Class
class HashTable{
private:
    Node **table;
    
public:
    /*int binary_search(string n){
        int l=0;
        int r=TABLE_SIZE-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(table[mid]>n)
                r=mid+1;
            else if(table[mid]<n)
                l=mid+1;
            else
                return mid;
        }
        return -1;
    }*/
    
    
    //Get data at key
    string get(string k){
        int index=nHash(k);
        while(table[index]!=NULL&&table[index]->key!=k){
            index=(index+1)%TABLE_SIZE;
        }
        if(table[index]==NULL){
            return "-1";
        }
        else{
            return table[index]->data;
        }
    }

    
    //push data to table
    void push(string k,string n){
        //Hash string to find key index
        int index=nHash(k);
        
        while(table[index]!=NULL&&table[index]->key!=k){
            index=(index+1)%TABLE_SIZE;
        }
        if(table[index]!=NULL){
            delete table[index];
        }
        table[index]=fillNode(k,n);
    }
    
    //String hash
    int nHash(string k){
        int val=0;
        for(int i=0;i<k.length();i++){
            val+=k[i];
        }
        return (val%TABLE_SIZE);
    }
    
    //fill a node
    Node *fillNode(string k,string n){
        Node *nNode=new Node;
        nNode->key=k;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Constructor
    HashTable(){
        table=new Node *[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++){
            table[i]=NULL;
        }
    }
    
    //Destructor
    ~HashTable(){
        for(int i=0;i<TABLE_SIZE;i++){
            if(table[i]!=NULL){
                Node *tmp=table[i];
                Node *prev=NULL;
                
                while(tmp!=NULL){
                    prev=tmp;
                    tmp=tmp->next;
                    delete prev;
                }
            }
        }
        delete []table;       
   }
  
    
};


#endif