/*
 *  Name: Kevin Romero
 *  Purpose: Node for Hash Table using Linked List Chaining
 *  Date: January 27, 2017
 */

#ifndef NODE_H
#define NODE_H


//System Libraries
#include <cstdlib>
#include <string>

//Create Node Structure
struct Node{
    string key;
    string data;
    Node *next;
};

#endif
      