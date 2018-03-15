#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"
#include "LinkedList.h"
#include "Data.h"

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
public:
	//Needs mod
	Node(Data &newData); //Constructor for Node with Data
	Node(Node &newNode); //Constructor  of New Node copying data from a Node
	~Node();

	Data getData(); //getter for Data
	Node * getNextPtr(); //getter for the next pointer

	void setData(Data &newData);
	void setNextPtr(Node * newNextPtr);

private:
	//string mPrintJob;
	Data * mpData;
	Node *mpNext;
	//int serviceTime = 0;
};