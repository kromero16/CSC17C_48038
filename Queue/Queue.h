/* 
 * File:   Queue.h
 * Author: Kevin Romero
 * Purpose: Queue using a Linked List
 * Created on January 7, 2017, 9:04 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Node.h"

//Create Class 
template<class T>
class Queue{
private:
    Node<T> *front;
    Node<T> *back;
    
public:
    
    //Constructor
    Queue(){
        front=NULL;
        back=NULL;
    }
    
    //Print Queue
    void print(){
        if(front==NULL){
            cout<<"Queue Empty.\n";
        }
        else{
            Node<T> *temp=front;
            while(temp!=NULL){
                cout<<temp->data<<"-> ";
                temp=temp->next;
            }cout<<"BACK";
            cout<<"\n";
        }
    }
    
    //Pop first element
    void dequeue(){
        if(front==NULL){
            cout<<"Queue Empty.\n";
            return;
        }
        else{
            Node<T> *tmp=front;
            front=front->next;
            delete tmp;
        }
    }
    
    //Push Element 
    void enqueue(T n){
        Node<T> *newNode=fillNode(n);
        if(front==NULL){
            front=newNode;
            back=newNode;
        }
        else{
            back->next=newNode;
            back=newNode;
            
        }
    }
    
    //Return Filled Node
    Node<T> *fillNode(T n){
        Node<T> *nNode=new Node<T>;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Destructor
    ~Queue(){
        if(front==NULL)return;
        else{
            while(front!=NULL){
                back=front;
                front=front->next;
                delete back;
            }
            delete front;
        }
    }
    
};



#endif /* QUEUE_H */

