/*
 Implementation File for BinaryTree.h
 
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries
#include "BinaryTree.h"

//Implement post order helper
void BinaryTree::postOrder(Node *ptr){
    if(ptr){
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout<<ptr->data<<" "<<endl;
    }
}

//Implement post order main
void BinaryTree::prntPostOrder(){
    postOrder(root);
}

//Implement in order helper
void BinaryTree::inOrder(Node *ptr){
    if(ptr){
        inOrder(ptr->left);
        cout<<ptr->data<<" "<<endl;
        inOrder(ptr->right);
    }
}

//Implement in order main
void BinaryTree::prntInOrder(){
    inOrder(root);
}

//Implement Pre order helper
void BinaryTree::preOrder(Node *ptr){
    if(ptr){
        cout<<ptr->data<<" "<<endl;
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

//Implement pre order main
void BinaryTree::prntPreOrder(){
    preOrder(root);
}

void BinaryTree::showText(){{
        string line;
        fstream file("initials.txt", ios::in);
        
            //        file.seekp(0L, ios::beg);
            //        file.seekg(0L, ios::beg);
        
        if (file.is_open())
        {
            while ( !file.eof())
            {
                for (int col=0; col<10; col++)
                {
                    getline (file,line);
                    if (line != "")
                    {
                        cout << "[" <<  line << "] ";
                        cout << setw(2) << "";
                        
                    }
                    
                }
                cout << endl;
            }
            file.close();
        }
}
}


//Returns true if node is found
bool BinaryTree::search(int n){
    Node *ptr=root;
    
    while(ptr!=NULL){
        if(ptr->data==n){
            break;
        }
        else if(n<ptr->data){
            ptr=ptr->left;
        }
        else if(n>ptr->data){
            ptr=ptr->right;
        }
    }
    if(ptr==NULL){
        return false;
    }
    else if(ptr->data==n){
        return true;
    }
    else{
        return false;
    }
}

//helper for remove
void BinaryTree::removeMatch(Node *&ptr){
    Node *temp=NULL;
    if(ptr==NULL){
        cout<<"Cannot Remove. Tree Is Empty."<<endl;
    }
    else if(ptr->right==NULL){
        temp=ptr;
        ptr=ptr->left;
        delete temp;         
    }
    else if(ptr->left==NULL){
        temp=ptr;
        ptr=ptr->right;
        delete temp;
    }
    else{
        temp=ptr->right;
        while(temp->left){
            temp=temp->left;
        }
        temp->left=ptr->left;
        temp=ptr;
        ptr=ptr->right;
        delete temp;
    }
}

//Takes in paramaters from removeNode
void BinaryTree::remove(int n, Node *ptr){
    if(n<ptr->data){
        remove(n,ptr->left);
    }
    else if(n>ptr->data){
        remove(n,ptr->right);
    }
    else{
        removeMatch(ptr);
    }
}

//Main remove function used in main
void BinaryTree::removeNode(int n){
    cout<<"Deleting Node Containing: "<<n<<" "<<endl<<endl;
    remove(n,root);
}
//max_val function
int BinaryTree::max_val(){
    findMax(root);
}

//Find Max Function
int BinaryTree::findMax(Node *ptr){
    if(root==NULL){
        cout<<"The Tree is Empty"<<endl;
        return -1;
    }
    else{
        if(ptr->right!=NULL){
            return findMax(ptr->right);
        }
        else{
            return ptr->data;
        }
    }
}

//Implement min_val Function
int BinaryTree::min_val(){
    findMin(root);
}

//Implement FindMin Function
int BinaryTree::findMin(Node *ptr){
    if(root==NULL){
        cout<<"The Tree is Empty"<<endl;
        return -1;
    }
    else{
        if(ptr->left!=NULL){
            return findMin(ptr->left);
        }
        else{
            return ptr->data;
        }
    }
}

//Implement main print function
void BinaryTree::print(){
    printTree(root);
}


//Print Helper Functions prints tree in-order
void BinaryTree::printTree(Node *ptr){
    //Verify root isnt empty
    if(root!=NULL){
        //If left not empty recurse
        if(ptr->left!=NULL)
            printTree(ptr->left);
        
        cout<<ptr->data<<" "<<endl;
        
        if(ptr->right!=NULL)
            printTree(ptr->right);
    }
    else{
        cout<<"The Tree is Empty"<<endl;
    }
}

//Implement InsertTo Function
void BinaryTree::insert(int n, Node *ptr){
    //Check root is null
    if(root==NULL){
        root=fillN(n);
    }
    
    //Verify left side
    else if(n<ptr->data){
        if(ptr->left!=NULL)
            insert(n,ptr->left);
        else{
            ptr->left=fillN(n);
        }
    }
    
    //Verify Right side
    else if(n>ptr->data){
        if(ptr->right!=NULL)
            insert(n,ptr->right);
        else{
            ptr->right=fillN(n);
        }
    }
    else{
        cout<<"Duplicate Found"<<endl;
    }
    
    }

//Implement Fill Node Function
Node* BinaryTree::fillN(int n){
    Node *nde=new Node;
    nde->data=n;
    nde->left=NULL;
    nde->right=NULL;
    
    //Return a Full Node
    return nde;
}
//Implement Push Function
void BinaryTree::push_back(int n){
    //Call insert function
    insert(n,root);
}

void BinaryTree::destroyTree(Node *ptr){
    if(ptr){
        if(ptr->left){
            destroyTree(ptr->left);
        }
        else if(ptr->right){
            destroyTree(ptr->right);
        }
        delete ptr;
    }
}

//Implement Destructor
BinaryTree::~BinaryTree(){
    destroyTree(root);
}
