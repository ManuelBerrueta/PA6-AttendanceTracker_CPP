#include "Stack.h"

Stack::Stack()
{
	absenceTracker[0] = "0";
	mpStackHead = 0;
}

void Stack::push()
{
	//This function will push the date to the stack
	//string temp; // = << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << endl   //Did not work
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S", timeinfo);
	absenceTracker[mpStackHead] = buffer;

	//absenceTracker[mpStackHead] << (now->tm_year + 1900) << '-'	<< (now->tm_mon + 1) << '-' << now->tm_mday << endl;
}

string Stack::pop()
{
	return absenceTracker[mpStackHead];
}

void Stack::peek()
{
	cout << absenceTracker[mpStackHead];
}

bool Stack::isEmpty()
{
	bool isitEmpty = true;
	if (mpStackHead != 0)
	{
		isitEmpty = false;
	}
	return 0;
}
