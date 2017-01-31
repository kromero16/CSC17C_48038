/*
 *  Name: Kevin Romero
 *  Purpose: Node for Hash Table using Linked List Chaining
 *  Date: January 27, 2017
 */

#ifndef NODE_H
#define NODE_H


//System Libraries
#include <cstdlib>

//Create Node Structure
template<class T>
struct Node{
    T data;
    Node<T> *next;
};


#endif
      