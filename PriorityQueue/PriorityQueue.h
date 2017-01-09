/* 
 * File:   Queue.h
 * Author: Kevin Romero
 * Purpose: Priority Queue using a Linked List
 * Created on January 7, 2017, 9:04 AM
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Node.h"

//Create Class 
template<class T>
class PriorityQueue{
private:
    Node<T> *front;
    
public:
    
    //Constructor
    PriorityQueue(){
        front=NULL;
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
            }
            cout<<"\n\n";
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
    void enqueue(T n, int p){
        Node<T> *newNode=fillNode(n,p);
        if(front==NULL||p<front->priority){
            newNode->next=front;
            front=newNode;
        }
        else{
            Node<T> *tmp=front;
            while(tmp->next!=NULL&&tmp->next->priority<=p){
                tmp=tmp->next;
            }
            newNode->next=tmp->next;
            tmp->next=newNode;
        }
    }
    
    //Return Filled Node
    Node<T> *fillNode(T n,int p){
        Node<T> *nNode=new Node<T>;
        nNode->priority=p;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Destructor
    ~PriorityQueue(){
        if(front==NULL)return;
        else{ 
            while(front!=NULL){
              Node<T> *temp=front;
              front=front->next;
                delete temp;
            }
            delete front;
        }
    }
    
};



#endif /* QUEUE_H */


