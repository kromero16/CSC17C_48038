/* 
 * File:   Stack.h
 * Author: Kevin Romero
 * Purpose: Stack using a Linked List
 * Created on January 6, 2017, 12:46 PM
 */

#ifndef STACK_H
#define STACK_H

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Node.h"

//Create Object
template<class T>
class Stack{
private:
    Node<T> *top;
    
public:
    //Print
    void print_stack(){
        if(top==NULL){
            cout<<"Stack Empty.\n";
        }
        else{
            Node<T> *tmp=top;
            cout<<"TOP-> ";
            while(tmp!=NULL){
                cout<<tmp->data<<"-> ";
                tmp=tmp->next;
            }cout<<"\n";
        }
    }
    
    //Return first element w/out deleting
    T peek(){
        T n=top->data;
        return n;
    }
    
    //is Empty
    bool isEmpty(){
        if(top==NULL)return true;
        else{return false;}
    }
    
    //Pop First element
    T pop(){
        //var to hold top element
        T num;
        
        //return null if empty 
        if(top==NULL){
            cout<<"Stack Empty\n";
            return NULL;
        }
        else{
            Node<T> *tmp=top;
            num=top->data;
            
            //traverse
            top=top->next;
            
            //remove top element
            delete tmp;
        }
        
        //return element popped
        return num;
     
    }
    
    //Push Data
    void push(T n){
        Node<T> *nNode=fillNode(n);
        if(top==NULL){
            top=nNode;
        }
        else{
            nNode->next=top;
            top=nNode;
        }
    }
    
    //Fill a Node
    Node<T> *fillNode(T n){
        Node<T> *nNode=new Node<T>;
        nNode->data=n;
        nNode->next=NULL;
        return nNode;
    }
    
    //Constructor
    Stack(){top=NULL;}
    
    //Deconstructor
    ~Stack(){
        if(top==NULL)return;
        else{
            Node<T> *tmp=top;
            while(tmp!=NULL){
            tmp=tmp->next;
            delete tmp;
            }
            delete top;
           
        }
     
    }
     
};



#endif /* STACK_H */

