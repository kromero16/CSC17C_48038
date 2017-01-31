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
template<class T>
class HashTable{
private:
    Node<T> **table;
    
public:
    
    //get index
    T getIndx(T n){
        //Hash string 
        int index=nHash(n);
        
        //If empty return
        if(table[index]==NULL){
            return "-1";
        }
        else{
            //Create new node with hashed table index
            Node<T> *tmp=table[index];
            
            //Traverse if not empty and wrong index
            while(tmp!=NULL&&tmp->data!=n){
                tmp=tmp->next;
            }
            
            //Check if index empty
            if(tmp==NULL){
                return "-1";
            }
            else{
                //return data if not empty
                return tmp->data;
            }
        }
    }
 
    //String hash function
    int nHash(string n){
        int val=0;
        for(int i=0;i<n.length();i++){
            val+=n[i];
        }
        return (val%TABLE_SIZE);
    }
    
    //int hash function
    int intHash(T n){
        return (n%TABLE_SIZE);
    }
    
    //push data to table
    void push(T n){
        //Hash string to find key index
        int index=nHash(n);
        
        //If array index empty then add
        if(table[index]==NULL){
            table[index]=fillNode(n);
        }
        //else table index not empty
        else{
            //Create new node with given hashed index
            Node<T> *nNode=table[index];
            
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
    
    //fill a node
    Node<T> *fillNode(T n){
        Node<T> *nNode=new Node<T>;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Constructor
    HashTable(){
        table=new Node<T> *[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++){
            table[i]=NULL;
        }
    }
    
    //Destructor
    ~HashTable(){
        for(int i=0;i<TABLE_SIZE;i++){
            if(table[i]==NULL){
                Node<T> *tmp=table[i];
                Node<T> *prev=NULL;
                
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