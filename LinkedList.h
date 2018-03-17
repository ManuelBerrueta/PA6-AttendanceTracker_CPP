#pragma once

#include "Node.h"

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;

class LinkedList
{
public:
	LinkedList();								// default constructor; will always set mpHead to NULL
	LinkedList(LinkedList &copyList);			// copy constructor - implicitly invoked copying a List object during construction of 
												// another List object, or when a List object is passed-by-value - must perform a deep copy, 
												// which means create new memory for each node copied!
	~LinkedList();								// destructor - implicitly invoked when a List object leaves scope

	LinkedList & operator= (LinkedList &rhs);	// overloaded assignment operator - must perform a deep copy, which means
												// create new memory (from the heap) for each node copied!

												// getter
	Node * getHeadPtr() const;					// returns a copy of the address stored in mpHead

	void setHeadPtr(Node * const pNewHead);		//setter & modifies mpHead

	bool insertAtFront(const int newData);		// inserts newData at the beginning or front of the list

	bool isEmpty();								// determines if the list is empty  

	void printList();							// visits each node, print the node's data - we could also overload the stream insertion << operator to print the list

	int computeMax();
	int computeMin();
	int computeMean();

private:
	Node * mpHead;								// pointer to the start or head of the singly linked list
	fstream fileHandle;
	void destroyList(Node * pMem);		// we will use recursion to solve this problem!

};
