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

class Data
{
public: // Member functions
	Data(int customerNewNum, int serviceNewTime, int totalNewTime);
	Data();
	~Data();

	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	void setCustomerNumber(int customerNumNew);
	void setServiceTime(int serviceTimeNew);
	void setTotalTime(int totalTimeNew);

private:
	int mCustomerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int mServiceTime;   // Random time; varies between express and normal lanes; units in minutes
	int mTotalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

};