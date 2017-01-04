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
    int size;
   
    
public:
    
    //Push Front
    void push_front(T n){
        Node<T> *nNode=fillNode(n);
        
        if(front==NULL){
            front=nNode;
            back=nNode;
            front->next=back->next=NULL;
            front->prev=back->prev=NULL;
        }
        else{
            nNode->next=front;
            front->prev=nNode;
            front=nNode;
            back->next=front;
            front->prev=back;
        }
        size++;
    }
    
    //Return filled node
    Node<T> *fillNode(T n){
        Node<T> *nNode=new Node<T>;
        nNode->data=n;
        nNode->next=NULL;
        nNode->prev=NULL;
        return nNode;
    }
    //Print
    void printList(){
        Node<T> *temp=front;
        
        if(front==NULL){
            cout<<"List Empty. \n\n";
            return;
        }
            for(int i=0;i<size;i++){
                cout<<temp->data<<" <-> ";
                temp=temp->next;
                //return;
            }cout<<"\n\n";
            return;
       }
        
    
    
    //Constructor
    CircularLinkedList(){
        front=NULL;
        back=NULL;
        size=0;
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

