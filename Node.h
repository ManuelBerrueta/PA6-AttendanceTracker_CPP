#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"
#include "LinkedList.h"

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node
{
public:
	//Needs mod
	Node(); //Constructor for Node with Data
	Node(Node &newNode); //Constructor  of New Node copying data from a Node
	~Node();

	Node * getNextPtr(); //getter for the next pointer
	void setNextPtr(Node * newNextPtr);

private:
	//string mPrintJob;
	Node *mpNext;
	//int serviceTime = 0;

	/* Student info goes here */
	int recordNum; //(max 3 digits)
	int id_Num;    //(max 9 digits)
	string name;   // (last, first)
	string email;
	int units;	    // (number of credits for class or AU for audit)
	string program; //(major)
	string level;   // (freshman, sophomore, junior, senior, graduate)
};