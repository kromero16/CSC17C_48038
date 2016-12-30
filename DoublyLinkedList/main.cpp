/* 
 * File:   main.cpp
 * Author: Kevin Romero
 *
 * Created on December 26, 2016, 12:08 PM
 */
//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "DoublyLinkedList.h"

//Begin Execution
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    DoublyLinkedList<int> list;
  
    cout<<"Pushing to Front: \n\n";
    list.push_front(99);
    list.push_front(95);
    
    cout<<"Pushing to Back: \n\n";
    list.push_back(89);
    list.push_back(85);
 
    cout<<"Printing the Doubly Linked List in Order. \n\n";
    list.print_list();
    list.printList_reverse();
    
    cout<<"REVERSING LIST. \n\n";
  list.reverse_List();
    
  list.print_list();
  list.printList_reverse();
    
    cout<<"Pushing Data : 1313, At Position: 3. \n\n";
    list.push_At(1313,3);
    
    list.deleteNthNode(3);
    
    list.print_list();
    list.printList_reverse();
    
     int n=list.numNodes();
    cout<<"\n\nThe Number of Nodes was: "<<n<<".\n\n";
    

    //Exit Program
    return 0;
}

