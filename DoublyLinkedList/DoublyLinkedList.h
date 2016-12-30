/* 
 * File:   DoublyLinkedList.h
 * Author: Kevin Romero
 *
 * Created on December 26, 2016, 12:10 PM
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Node.h"

template<class T>
class DoublyLinkedList{
private:
    Node<T> *front;
    
public:
    //Delete nTh Node
    void deleteNthNode(int pos){
        Node<T> *temp=front;
        Node<T> *curr=NULL;
        
        //Test Position Range
        cout<<"Removing Node in Position: "<<pos<<" .\n\n";
        if(pos<=0||pos>numNodes()+1){
            cout<<"Position is out of range\n\n";
        }
        
        //Delete head is pos==1
        else if(pos==1){
            front=temp->next;
            temp->prev=NULL;
            delete temp;
        }
        else{
            //Traverse to n-1th node
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            curr=temp;                          //Point to n-1
            curr->prev->next=curr->next;       
            curr->next=curr->next->prev;
            delete curr;
      
        }
    }
    
    //Push at
    void push_At(T n,int pos){
        Node<T> *newNode=fillNode(n);
        
        if(pos<=0||pos>numNodes()+1){
            cout<<"The Position is Out of Range. \n\n";
        }
        else if(pos==1){
            front=fillNode(n);
        }
        else{
            Node<T> *temp=front;
            for(int i=0;i<pos-2;i++){
                temp=temp->next;
            }
            newNode->next=temp->next;
            newNode->next->prev=newNode;
            temp->next=newNode;
            newNode->prev=temp;
            
        }
    }
    
    //Reverse List
    void reverse_List(){
        Node<T> *temp=NULL;
        Node<T> *curr=front;
        
        //Swap next and prev for all nodes
        while(curr!=NULL){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        //Change front if not empty
        if(temp!=NULL){
            front=temp->prev;
        }
        
    }
    
    //Count Nodes
    int numNodes(){
        int count=0;
        Node<T> *tmp=front;
        while(tmp!=NULL){
            count++;
            tmp=tmp->next;
        }
        return count;
    }
    
    //Push at front
    void push_front(T n){
        //Node to Push
        Node<T> *newNode=fillNode(n);
        
        //If Front empty add
        if(front==NULL){
            front=fillNode(n);  
        }
        //Else add 
        else{
            newNode->prev=NULL;             //newNode Prev is NULL
            newNode->next=front;            //newNode Next points to old head
            front->prev=newNode;            //old Head Prev points to newNode
            front=newNode;                  //head is now newNode
        }
      
    }
    
    //Push to Back 
    void push_back(T n){
        //Node to Push to End
        Node<T> *newNode=fillNode(n);
        
        //If empty add to front
        if(front==NULL){
            front=fillNode(n);
        }
        else{
            //If not empty, Traverse to end of list
            Node<T> *end=front;
            while(end->next!=NULL){
                end=end->next;
            }
            end->next=newNode;          //Move newNode to end
            newNode->prev=end;          //newNode previous points to old end
            newNode=end;                //newNode is new end
        }
    }
    
    //Print Backwards
    void printList_reverse(){
        //Node to Traverse List
        Node<T> *tmp=front;
        
        //If List Empty Prompt
        if(tmp==NULL){
            cout<<"The Doubly Linked List is Empty!\n\n";
        }
        else{
            cout<<"Printing The Doubly Linked List in Reverse. \n\n";
            
            //Move to end of list
            Node<T> *end=front;
            while(end->next!=NULL){
                end=end->next;
            }
            
            //Point node to end
            tmp=end;
            
            //Print data moving backwards from end
            while(tmp!=NULL){
                cout<<tmp->data<<"-> ";
                tmp=tmp->prev;
            }cout<<"NULL \n\n";
            
        }
    }
    //Print List
    void print_list(){
        Node<T> *tmp=front;
        if(tmp==NULL){
            cout<<"The Doubly Linked List is Empty!\n\n";
        }
        else{    
            //cout<<"Printing the Doubly Linked List in Order. \n\n";
            while(tmp!=NULL){  
                cout<<tmp->data<<"-> ";
                tmp=tmp->next;
            }cout<<"NULL \n\n";
        }
    }
    
    //Return filled node
    Node<T> *fillNode(T n){
        Node<T> *node=new Node<T>;
        node->data=n;
        node->next=NULL;
        node->prev=NULL;
        return node;
    }
    
    //Constructor
    DoublyLinkedList(){
        cout<<"Empty Doubly Linked List Created.\n\n";
        front=NULL;  
    }
    
    //Deconstructor
    ~DoublyLinkedList(){
        while(front!=NULL){
            Node<T> *tmp=front;
            front=front->next;
            delete tmp;
        }
        delete front;
      
    }
    
};



#endif /* DOUBLYLINKEDLIST_H */

