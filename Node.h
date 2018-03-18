#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;

class Node
{
public:
	//Needs mod
	Node();					//Constructor
	Node(Node &newNode);	//Constructor  of New Node copying data from a Node
	~Node();

	Node * getNextPtr();	//getter for the next pointer
	void setNextPtr(Node * newNextPtr); //setter for the mpNext (Next Pointert

private:
	Node *mpNext;
	/* Student info goes here */
	int recordNum;			//(max 3 digits)
	int id_Num;				//(max 9 digits)
	string name;			// (last, first)
	string email;
	string units;			// (number of credits for class or AU for audit)
	string program;			//(major)
	string level;			// (freshman, sophomore, junior, senior, graduate)
	int absences;			//Numbers of absences
	Stack dateAbsent;		//Stack using an array of strings
};