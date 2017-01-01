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
   
    
public:
    
    //Push Front
    void push_back(T n){
        //Node to push
        Node<T> *newNode=fillNode(n);
        
        //Empty Circular List
        if(front==back&&front==NULL){
            front=back=newNode;
            front->next=back->next=NULL;
            front->prev=back->prev=NULL;
        }
        else{
            back->next=newNode;
            
        }
        
        
       
        
      
    }
    
    //Return filled node
    Node<T> *fillNode(T n){
        Node<T> *nNode=new Node<T>;
        nNode->data=n;
        nNode->next=NULL;
        nNode->prev=NULL;
        return nNode;
    }
    
    /*
    //Print Reverse
    void printList_reverse(){
        Node<T> *temp=back;
        if(temp==NULL){
            cout<<"List Empty. \n";
            return;
        }
        else{
            while(temp!=NULL){
                cout<<temp->data<<"-> ";
                temp=temp->prev;
            }cout<<"NULL \n\n";
        }
    }*/
    //Print
    void printList(){
        Node<T> *temp=front;
        if(front==NULL&&front==back){
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
        back=NULL;
    }
    
    //Deconstructor
    ~CircularLinkedList(){
        while(front!=NULL){
            Node<T> *temp=front;
            front=front->next;
            delete temp;
        }
        delete front;
    }
        
        
        
        
        
    
};
        
        



#endif /* CIRCULARLINKEDLIST_H */

