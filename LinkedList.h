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
	~LinkedList();


												// getter
	Node * getHeadPtr() const;					// returns a copy of the address stored in mpHead

	void setHeadPtr(Node * const pNewHead);		//setter & modifies mpHead

	bool insertAtFront(Node newNode);		// inserts newData at the beginning or front of the list

	bool isEmpty();								// determines if the list is empty  

	//void printList();							// visits each node, print the node's data - we could also overload the stream insertion << operator to print the list

	void isAbsent();

private:
	Node *mpHead;								// pointer to the start or head of the singly linked list
	Node *makeNode(Node newData);			// will only call within insert functions
	fstream fileHandle;
	void destroyList(Node * pMem);				// we will use recursion to solve this problem!
};
