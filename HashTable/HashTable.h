/* 
 * File:   HashTable.h
 * Author: Kevin Romero
 * Purpose: Class for Hash Table Using Linked List Closed Address Chaining
 * Created on January 9, 2017, 2:26 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

//System Libraries
#include <cstdlib>

//User Libraries
#include "Node.h"

//Global Variables 
const int TABLE_SIZE=128;

//Create Class
template <class T>
class HashTable{
private:
    Node<T> **table;
    
public:
    
    //Get data at key
    int pop(int key){
        int hash=(key%TABLE_SIZE);
        
        if(table[hash]==NULL){
            return -1;
        }
        else{
            Node<T> *tmp=table[hash];
            while(tmp!=NULL&&tmp->key!=key){
                tmp=tmp->next;
            }
            if(tmp==NULL){
                return -1;
            }
            else{
                return tmp->data;
            }
        }
    }
    
    Node<T> *fillNode(int k,T n){
        Node<T> *nNode=new Node<T>;
        nNode->key=k;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Push Data
    void push(int key,T n){
        int hash=(key%TABLE_SIZE);
        
        if(table[hash]==NULL){
            table[hash]=fillNode(key,n);
        }
        else{
            Node<T> *newNode=table[hash];
            
            while(newNode->next!=NULL){
                newNode=newNode->next;
            }
            if(newNode->key==key){
                newNode->data=n;
            }
            else{
                newNode->next=fillNode(key,n);
            }
        }
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
                Node<T> *prev=NULL;
                Node<T> *tmp=table[i];
                
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



#endif /* HASHTABLE_H */

