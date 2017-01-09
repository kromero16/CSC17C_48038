/* 
 * File:   BinaryTree.h
 * Author: Kevin Romero
 * Purpose: BinaryTree Object Class
 * Created on November 30, 2016, 11:26 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

//System Libraries
#include <cstdlib>

//User Libraries
#include "Node.h"

//Create Tree object
class BinaryTree{
private:
    //Root Node
    Node *root;
    
    //Private Helper Functions
    int findMin(Node *);             //Used by min_val()
    int findMax(Node *);             //Used by max_val()
    void printTree(Node *);          //Used by print()
    void insert(int, Node *); 
    
    //Helper Functions for RemoveNode()
    void removeMatch(Node *&);   
    void remove(int,Node *);
    
    //Helper Functions for Traversals
    void inOrder(Node *);
    void postOrder(Node *);
    void preOrder(Node *);
    
    void showText();
    
   
public:
    
    //Default Constructor 
    BinaryTree(){root=NULL;}
    
    //PreOrder Traversal
    void prntPreOrder();
    
    //In order
    void prntInOrder();
    
    //Post order
    void prntPostOrder();
    
    //Search for node 
    bool search(int);
    
    //Finds Minimum Value
    int min_val();
    
    //Find Maximum Value
    int max_val();
    
    //Remove Node
    void removeNode(int);
    
    //Fill Node
    Node *fillN(int);
    
    //Push Data
    void push_back(int);
    
    //Print Tree
    void print();
  
    //Deallocates memory
    void destroyTree(Node *);
    
    //Destructor
    ~BinaryTree();
  
    
};



#endif /* BINARYTREE_H */

