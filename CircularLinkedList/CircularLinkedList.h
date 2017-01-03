/* 
 * File:   CircularLinkedList.h
 * Author: Kevin Romero
 * Purpose: Class for Circular Linked List
 * Created on December 30, 2016, 12:03 PM
 */

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Node.h"

//Create Class
template<class T>
class CircularLinkedList{
private:
    Node<T> *front;
    Node<T> *back;
    int nodeCount;
   
    
public:
    
    //Push Front
    void push_back(T n){
        Node<T> *newNode=fillNode(n);
        
        if(front==NULL&&front==back){
            front=back=newNode;
            front->next=back->next=NULL;
            front->prev=back->prev=NULL;
        }
        else{
            back->next=newNode;
            newNode->prev=back;
            back=newNode;
            front->prev=back;
            back->next=front;
        }
    }
    
    //Return filled node
    Node<T> *fillNode(T n){
        Node<T> *nNode=new Node<T>;
        nNode->data=n;
        nNode->next=NULL;
        nNode->prev=NULL;
        nodeCount++;
        return nNode;
    }
    //Print
    void printList(){
        Node<T> *temp=front;
        
        if(front==NULL&&front==back){
            cout<<"List Empty \n\n";
            return;
        }
        else if(nodeCount==1){
            cout<<temp->data<<"<-> ";
        }cout<<"\n\n";
        
       }
        
    
    
    //Constructor
    CircularLinkedList(){
        front=NULL;
        back=NULL;
    }
    
    //Deconstructor
    ~CircularLinkedList(){
        while(front!=NULL){
            Node<T> *temp=front;
            front=front->next;
            delete temp;
            back=NULL;
        }
        delete front;
    }
        
        
        
        
        
    
};
        
        



#endif /* CIRCULARLINKEDLIST_H */

