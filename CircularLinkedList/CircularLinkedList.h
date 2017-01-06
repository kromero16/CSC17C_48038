/* 
 * File:   CircularLinkedList.h
 * Author: Kevin Romero
 * Purpose: Class for Circular Linked List
 * Created on January 5, 2017, 9:22 AM
 */

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

//System Libraries
#include <cstdlib>

//User Libraries
#include "Node.h"

//Create Class
template<class T>
class CircularLinkedList{
private:
    Node<T> *front;
    
public:
    //Push Front
    void push_Front(T n){       
        //Node to Push
        Node<T> *nNode=fillNode(n);    
        
        //Add to front if empty
        if(front==NULL){
            nNode->next=nNode;
            front=nNode;
            return;
        }
        else{
            Node<T> *temp=front;
            while(temp->next!=front){
                temp=temp->next;
            }
            nNode->next=front;
            temp->next=nNode;
            front=nNode;
        }
    }
    
    //Push Back
    void push_back(T n){
        Node<T> *nNode=fillNode(n);     //Node to Push
        
        //Add to front if empty
        if(front==NULL){
            nNode->next=nNode;
            front=nNode;
            return;
        }
        else{
           Node<T> *temp=front;
           while(temp->next!=front){
               temp=temp->next;
           }
           temp->next=nNode;
           nNode->next=front;

        }
    }
    
    //count nodes
    int nodeCount(){
        int count=0;
        Node<T> *temp=front;
        
        if(front==NULL)return 0;
        else{
            count++;
            while(temp->next!=front){
                temp=temp->next;
                count++;
            }
            return count;
        }
    }
    //Return filled node
    Node<T> *fillNode(T n){
        Node<T> *temp=new Node<T>;
        temp->data=n;
        temp->next=NULL;
        return temp;
    }
    
    //Print
    void printList(){
        if(front==NULL){
            cout<<"List Empty\n";
            return;
        }
        else{
           Node<T> *temp=front;
           cout<<"Front--> ";
           while(temp->next!=front){
                cout<<temp->data;
                cout<<" --> ";
                temp=temp->next;
            }
           cout<<temp->data<<"\n\n";
        }
    }
    
    
    //Constructor
    CircularLinkedList(){front=NULL;}
    
    
    //Destructor
    ~CircularLinkedList(){      
        if(front==NULL){return;}
        else{
               Node<T> *tmp=front;
            while(tmp!=front){
                tmp=tmp->next;
                delete tmp;
            }
            delete front;
        }
    }
     
};



#endif /* CIRCULARLINKEDLIST_H */

