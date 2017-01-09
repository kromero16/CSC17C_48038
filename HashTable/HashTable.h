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
        
        //Hash Function
        int hash=(key%TABLE_SIZE);
        
        //If Empty return
        if(table[hash]==NULL){
            return -1;
        }
        else{
            
            //Create new Node with table at hash index
            Node<T> *tmp=table[hash];
            
            //Traverse if not empty and wrong index
            while(tmp!=NULL&&tmp->key!=key){
                tmp=tmp->next;
            }
            //Check If Empty
            if(tmp==NULL){
                return -1;
            }
            else{
                //If not return data
                return tmp->data;
            }
        }
    }
    
    //Return filled node with index and data
    Node<T> *fillNode(int k,T n){
        Node<T> *nNode=new Node<T>;
        nNode->key=k;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Push Data
    void push(int key,T n){
        //Hash Function
        int hash=(key%TABLE_SIZE);
        
        //If Table index empty add
        if(table[hash]==NULL){
            table[hash]=fillNode(key,n);
        }
        else{
            //Create new Node with table hash index
            Node<T> *newNode=table[hash];
            
            //Traverse until NULL
            while(newNode->next!=NULL){
                newNode=newNode->next;
            }
            
            //If keys match set data
            if(newNode->key==key){
                newNode->data=n;
            }
            else{
                //Set next node in LL as one with key/index
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

