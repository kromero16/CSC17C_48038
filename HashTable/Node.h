/* 
 * File:   Node.h
 * Author: Kevin Romero
 * Purpose: Node Class for Hash Table using Linked List Chaining
 * Created on January 9, 2017, 2:16 PM
 */

#ifndef NODE_H
#define NODE_H

//System Libraries
#include <cstdlib>

template<class T>
struct Node{
    int key;
    T data;
    Node<T> *next;
};
/*
//Create Node Class
template <class T>
class Node{
    private:
        int key;            
        T data;
        Node<T> *next;
        
    public:
        
        //Constructor
        Node(int key,T n){
            this->key=key;
            this->data=n;
            this->next=NULL;
        }
        
        //Accessors
        int getKey(){return key;}
        T getData(){return data;}
        Node<T> *getNext(){return next;}
        
        //Mutators
        void setKey(int k){this->key=k;}
        void setData(T n){this->data=n;}
        void setNext(Node<T> *nxt){this->next=nxt;}
 */           
//};



#endif /* NODE_H */

