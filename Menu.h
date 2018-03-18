#pragma once

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;

class Menu
{
public:
	Menu();

	void runApp();


private:
	ifstream mInput;  // the file stream associated with "ExamScore.csv"
	ofstream mOutput; // the file stream associated with "ExamStats.txt"


};