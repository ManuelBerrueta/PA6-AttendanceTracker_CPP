#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

Stack::Stack()
{
	//absenceTracker[0] = "";
	StackTop = -1;
}

void Stack::push(string date)
{
	//This function will push the date to the stack
	//string temp; // = << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << endl   //Did not work
	absenceTracker[++StackTop] = date;

	//absenceTracker[mpStackHead] << (now->tm_year + 1900) << '-'	<< (now->tm_mon + 1) << '-' << now->tm_mday << endl;
}

string Stack::pop()
{
	return absenceTracker[StackTop--];
}

string Stack::peek()
{
	string mostCurrentAbsence = "";
	mostCurrentAbsence = absenceTracker[StackTop];
	return mostCurrentAbsence;
}

bool Stack::isEmpty()
{
	bool isitEmpty = true;
	if (StackTop != -1) //added || absenceTracker[StackTop] != ""
	{
		isitEmpty = false;
	}
	return isitEmpty;
}

fstream & operator<<(fstream & lhs, Stack &rhs)
{
	Stack tempData;
	string tempDate;
	
	//if (!rhs.isEmpty())
	//{

	//}



	while (!rhs.isEmpty()) //
	{
		tempDate = rhs.pop();
		lhs << tempDate << ',';
		tempData.push(tempDate);
	}
	while (!tempData.isEmpty()) //Start here
	{
		rhs.push(tempData.pop());
	}
	return lhs;
}

