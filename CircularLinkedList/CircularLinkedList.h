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
    
public:
    
    //Push Front
    void push_back(T n){
        Node<T> *newNode=fillNode(n);
        
        if(front==NULL){
            front=fillNode(n);
        }
        else{
            Node<T> *end=front;
            while(end->next!=NULL){
                end=end->next;
            }
            end->next=newNode;
            newNode->prev=end;
            newNode=end;
        }
    }
    
    //Fill Node
    Node<T> *fillNode(T n){
        Node<T> *next=new Node<T>;
        next->data=n;
        next->next=NULL;
        next->prev=NULL;
        return next;
    }
    
    //Print Reverse
    void printList_reverse(){
        Node<T> *temp=front;
        if(front==NULL){
            cout<<"List Empty. \n";
            return;
        }
        else{
            Node<T> *end=front;
            while(end->next!=NULL){
                end=end->next;
            }
            end=temp;
            while(temp!=NULL){
                cout<<temp->data<<"-> ";
                temp=temp->prev;
            }cout<<"NULL \n\n";
        }
    }
    
    //Print
    void printList(){
        Node<T> *temp=front;
        if(front==NULL){
            cout<<"List Empty.\n";
            return;
        }
        else{
        while(temp!=NULL){
            cout<<temp->data<<"-> ";
            temp=temp->next;
        }cout<<"NULL \n\n";
       }
    }
    
    //Constructor
    CircularLinkedList(){
        front=NULL;
    }
    
    //Deconstructor
    ~CircularLinkedList(){
        while(front!=NULL){
            Node<T> *temp=front;
            temp=temp->next;
            delete temp;
        }
        delete front;
    }
        
        
        
        
        
    
};
        
        



#endif /* CIRCULARLINKEDLIST_H */

