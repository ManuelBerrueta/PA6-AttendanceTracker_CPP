#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

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
	Node();					//Constructor
	Node(Node &newNode);	//Constructor  of New Node copying data from a Node
	~Node();

	Node * getNextPtr();	//getter for the next pointer
	void setNextPtr(Node * newNextPtr); //setter for the mpNext (Next Pointer)

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

private:
	Node *mpNext;
};

//fstream & operator >> (fstream &lhs, Node &rhs)
//{
//	lhs >> rhs.recordNum >> rhs.id_Num >> nrhs.getDate() << endl << endl;
//	//cout << "Plan Name: " << dPlanDisplay.getName << "Goal: " << dPlanDisplay.getName << "Date: " << dPlanDisplay.getDate << endl;
//
//	return lhs;
//}
