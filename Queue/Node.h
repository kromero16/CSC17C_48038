/* 
 * File:   Node.h
 * Author: Kevin Romero
 * Pupose: Node for Linked List to build a Queue
 * Created on January 7, 2017, 9:03 AM
 */

#ifndef NODE_H
#define NODE_H

//System Libraries
#include <cstdlib>

template<class T>
struct Node{
    T data;
    Node<T> *next;
};



#endif /* NODE_H */

