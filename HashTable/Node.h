/* 
 * File:   Node.h
 * Author: Kevin Romero
 * Purpose: Node Class for Hash Table using Linked List Chaining
 * Created on January 9, 2017, 2:16 PM
 */

#ifndef NODE_H
#define NODE_H

//System Libraries
#include <cstdlib>

template<class T>
struct Node{
    int key;
    T data;
    Node<T> *next;
};




#endif /* NODE_H */

