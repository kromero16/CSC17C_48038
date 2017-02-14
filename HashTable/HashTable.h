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
const int TABLE_SIZE=8;

//Create Hash Table Object
class HashTable{
private:
    Node **table;
    
public:
    //Constructor
    HashTable(){
        table=new Node*[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++){
            table[i]=NULL;
        }
    }
    
    //sequentially search
    void sequential_search(string key){
        int index=hash(key);
        
        //Traverse until empty cell
        while(table[index]!=NULL){
            if(table[index]->key==key)
                cout<<"Key Found: "<<table[index]->data<<"\n";
            else if(table[index]->key!=key)
                cout<<"Key Not Found.\n";
           // ++index;
           // index%=TABLE_SIZE;
        }
       
             
    }
    //Get data at given key
    string get(string key){
        int index=hash(key);
        
        while(table[index]!=NULL&&table[index]->key!=key){
            index=(index+1)%TABLE_SIZE;
        }
        if(table[index]==NULL)
            return "-1";
        return table[index]->data;
    }
    
    //Push paired data to table
    void push(string key,string data){
        //Hash key to find index
        int index=hash(key);
        
        while(table[index]!=NULL&&table[index]->key!=key){
            index=(index+1)%TABLE_SIZE;
        }
        if(table[index]!=NULL){
            delete table[index];
        }
        table[index]=fillNode(key,data);
        
    }
    
    //return filled node
    Node *fillNode(string k,string d){
        Node *nNode=new Node;
        nNode->data=d;
        nNode->key=k;
        nNode->next=NULL;
        return nNode;
    }
    
    //string to int hash
    int hash(string key){
        int v=0;
        for(int i=0;i<key.length();i++){
            v+=key[i];
        }
        return (v%TABLE_SIZE);
    }
    
    //Deconstructor
    ~HashTable(){
        for(int i=0;i<TABLE_SIZE;i++){
            Node *tmp=table[i];
            Node *prev=NULL;
            
            while(tmp!=NULL){
                prev=tmp;
                tmp=tmp->next;
                delete prev;
            }
        }
        delete []table;
    }
    
    
    
    
};



#endif