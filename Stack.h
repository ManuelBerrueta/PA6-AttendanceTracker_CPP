#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;

class Stack
{
public:
	Stack();
	void push(string date);
	string pop();
	string peek();
	bool isEmpty();


private:
	string absenceTracker[100];
	int StackTop;
};

fstream & operator<<(fstream & lhs, Stack &rhs);