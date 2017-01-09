/* 
 * File:   Node.h
 * Author: Kevin Romero
 * Purpose: Node for Priority Queue using Linked List
 * Created on January 7, 2017, 10:24 AM
 */

#ifndef NODE_H
#define NODE_H

//System Libraries
#include <cstdlib>

template<class T>
struct Node{
    int priority;
    T data;
    Node *next;
};


#endif /* NODE_H */

