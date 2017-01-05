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
    //Delete Node
    void deleteAt(int pos){
        if(front==NULL&&front==back){
            cout<<"List Empty";
            return;
        }
        else if(size<pos){
            cout<<"Position Out of Range.";
            return;
        }
        else{
            Node<T> *curr=front;
            Node<T> *nPtr;
            
            if(pos==1){
                size--;
                back->next=curr->next;
                curr->next->prev=back;
                front=curr->next;
                delete curr;
                return;
            }
            else{
                for(int i=0;i<pos-1;i++){
                    curr=curr->next;
                    nPtr=curr->prev;
                }
                nPtr->next=curr->next;
                curr->next->prev=nPtr;
                
                if(pos==size){
                    back=nPtr;
                }
                size--;
                delete curr;
                
            }
            
        }
    }
    
    //Reverse CDLL 
    void reverse_List(){      
        if(front==NULL&&front==back){
            cout<<"List Empty.";
            return;
        }
        else{
           Node<T> *curr,*next;
           curr=front;
           next=curr->next;
           curr->next=NULL;
           curr->prev=next;
 
            while(next!=front){
                next->prev=next->next;
                next->next=curr;
                curr=next;
                next=next->prev;
            }
            back=front;
            front=curr;        
        }
    }
    
    //Push Back
    void push_back(T n){
        Node<T> *nNode=fillNode(n);
        
        if(front==NULL){
            front=nNode;
            back=nNode;
            front->next=back->next=NULL;
            front->prev=back->prev=NULL;
        }
       
        else{
            nNode->prev=back;
            back->next=nNode;
            back=nNode;
            front->prev=back;
            back->next=front;
        }
        size++;
    }
    
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
        //size++;
        return nNode;
        
    }
          /*
         * 
         * Program hangs during output because it is a 
         * circular list which keeps on printing.
         * Haven't figured if should add a loop termination
         * input deciding in future use of data structure
         * 
         */
    void printList(){
        Node<T> *temp=front;
        
        if(front==NULL){
            cout<<"List Empty. \n\n";
            return;
        }
        else{
           for(int i=0;i<size;i++){
                cout<<temp->data<<" <-> ";      
                temp=temp->next;   
            }cout<<"\n\n";
        }
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
            //back=NULL;
        }
        delete front;
    }
        
        
        
        
        
    
};
        
        



#endif /* CIRCULARLINKEDLIST_H */

