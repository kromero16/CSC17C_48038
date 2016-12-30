/* 
 * File:   Node.h
 * Author: Kevin Romero
 *
 * Created on December 26, 2016, 12:09 PM
 */

#ifndef NODE_H
#define NODE_H

template<class T>
struct Node{
    T data;
    Node *next;
    Node *prev;
};



#endif /* NODE_H */

