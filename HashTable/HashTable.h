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
    
    string getIndx(string key){
        int indx=nHash(key);
        
        if(table[indx]==NULL){
            return "-1";
        }
        else{
            Node *nNode=table[indx];
            
            while(nNode!=NULL&&nNode->data!=key){
                nNode=nNode->next;
            }
            if(nNode==NULL)
                return "-1";
            else
                return nNode->data;
        }
    }
    
    //push data to table
    void push(string n){
        //Hash string to find key index
        int index=nHash(n);
        
        //If array index empty then add
        if(table[index]==NULL){
            table[index]=fillNode(n);
        }
        //else table index not empty
        else{
            //Create new node with given hashed index
            Node *nNode=table[index];
            
            //Traverse until null
            while(nNode->next!=NULL){
                nNode=nNode->next;
            }
            
            //If keys match set data
            if(nNode->data==n){
                nNode->data=n;
            }
            else{
                //Collision, set to next node
                nNode->next=fillNode(n);
            }
        } 
    }
    
    //String hash
    int nHash(string n){
        int val=0;
        for(int i=0;i<n.length();i++){
            val+=n[i];
        }
        return (val%TABLE_SIZE);
    }
    
    //fill a node
    Node *fillNode(string n){
        Node *nNode=new Node;
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