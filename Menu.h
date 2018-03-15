#pragma once

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

class Menu
{
public:
	Menu();



private:
	ifstream mInput;  // the file stream associated with "ExamScore.csv"
	ofstream mOutput; // the file stream associated with "ExamStats.txt"


};