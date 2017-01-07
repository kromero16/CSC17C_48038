/* 
 * File:   Node.h
 * Author: Kevin Romero
 * Purpose: Node Structure for Stack Using Linked List
 * Created on January 6, 2017, 12:44 PM
 */

#ifndef NODE_H
#define NODE_H

//System Libraries
#include <cstdlib>

template<class T>
struct Node{
    T data;
    Node *next;
};



#endif /* NODE_H */

