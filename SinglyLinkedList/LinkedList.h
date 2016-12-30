/* 
 * File:   LinkedList.h
 * Author: kevin
 *
 * Created on December 21, 2016, 5:18 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Node.h"

template<class T>
class LinkedList{
private:
    Node<T> *front;         //Front of Linked List
    
public:
    //Constructor
    LinkedList(){
        front=NULL;
        cout<<endl<<"Empty Linked List Created."<<endl<<endl;
    }
    
    //Reverse a linked list using iteration
    void reverseList(){
        cout<<"\n\nReversing the Linked List using Iteration.\n\n";
        
        Node<T> *prev,*current,*next;
        current=front;
        prev=NULL;
        
        if(front==NULL){
            cout<<"The Linked List is Empty\n\n";
        }
        else{
        while(current!=NULL){
            next=current->ptr;
            current->ptr=prev;
            prev=current;
            current=next;
        } 
        front=prev;
        
        }
    }
    
    //Push Node at Position
    void pushAt(int n, int pos){
        cout<<"\nPushing Node w/ Data: "<<n<<". At Position: "<<pos<<".\n\n";
        
        Node<T> *next=fillNode(n);
        
        if(pos<=0||pos>getNumNodes()+1){
            cout<<"Position out of List Range.\n\n";
        }
        else if(pos==1){
            front=fillNode(n);
        }
        else{
            Node<T> *temp=front;
            for(int i=0;i<pos-2;i++){
                temp=temp->ptr;
            }
            next->ptr=temp->ptr;
            temp->ptr=next;
            
        }
        
    }
    //Remove given node
    void removeNthNode(int n){
        Node<T> *next=front;
        Node<T> *prev=NULL;
        
        cout<<"\n\nRemoving Node in position: "<<n<<".\n";
        if(n<=0||n>getNumNodes()){
            cout<<"The Nth Node is not Within Range.\n\n";
        } 
        else if(n==1){
            front=next->ptr;
            delete next;
        }
        else{
            for(int i=0;i<n-2;i++){
                next=next->ptr;
            }
            prev=next->ptr;
            next->ptr=prev->ptr;
            delete prev;
        }
    }
    
    //Count number of nodes
    int getNumNodes(){
        int cnt=0;
        Node<T> *tmp=front;
        while(tmp!=NULL){
            cnt++;
            tmp=tmp->ptr;
        }
        return cnt;
    }
    
    //Push to front
    void push_front(T n){
        if(front==NULL)
            front=fillNode(n);
        else{
            Node<T> *temp=fillNode(n);
            temp->ptr=front;
            front=temp;
        }
    }
    
    //Push Data
    void push_back(T n){
        //Create node with data
        Node<T> *next=fillNode(n);
        
        //Traverse list if not empty
        if(front!=NULL){
            //Find end
            Node<T> *end=front;
            while(end->ptr!=NULL){
                end=end->ptr;
            }
            //Add node to end
            end->ptr=next;
        }else{
            //If empty add to front
            front=next;
        }
    }
    
    //Returns filled node
    Node<T> *fillNode(T n){
        Node<T> *next=new Node<T>;
        next->data=n;
        next->ptr=NULL;
        return next;
    }
    
    //Print List
    void printList(){
        cout<<endl<<"Printing Linked List."<<endl<<endl;
        Node<T> *tmp=front;
        
        while(tmp!=NULL){
            cout<<tmp->data<<" ";
            tmp=tmp->ptr;
        }cout<<"\n";
    }
    
    //Destructor
    ~LinkedList(){
        while(front!=NULL){
            Node<T> *temp=front;
            front=front->ptr;
            delete temp;
        }
        delete front;
        cout<<endl<<"Memory Cleared."<<endl;
    }
    
};



#endif /* LINKEDLIST_H */

