/* 
 * File:   Node.h
 * Author: Kevin Romero
 * Purpose: Node Structure for Circular Linked List
 * Created on December 30, 2016, 12:01 PM
 */

#ifndef NODE_H
#define NODE_H

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Node Structure
template<class T>
struct Node{
    T data;
    Node *next;
    Node *prev;
};



#endif /* NODE_H */

