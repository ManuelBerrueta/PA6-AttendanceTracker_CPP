#include "LinkedList.h"


LinkedList::LinkedList()
{
	mpHead = nullptr;
}

LinkedList::~LinkedList()
{
	destroyList(mpHead);
}

Node * LinkedList::getHeadPtr()
{
	return mpHead;
}

void LinkedList::setHeadPtr(Node * pNewHead)
{
	mpHead = pNewHead;
}


// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool LinkedList::insertAtFront(Node  newData)     // inserts newData at the beginning or front of the list
{
	Node *pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
						// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

bool LinkedList::isEmpty()
{
	return (mpHead == nullptr);
}

void LinkedList::loadInitialList()
{
	fileHandle.open("classList.csv", ios::in);
	Node tempData;
	string tempStr = "";
	getline(fileHandle, tempStr);
	
	while ( getline(fileHandle, tempStr, ',') )
	{
		//getline(fileHandle, tempStr, ',');
		tempData.recordNum = stoi(tempStr);
		getline(fileHandle, tempStr, ',');
		tempData.id_Num = stoi(tempStr);
		getline(fileHandle, tempStr, '"');
		getline(fileHandle, tempData.name, '"');
		getline(fileHandle, tempStr, ',');
		getline(fileHandle, tempData.email, ',');
		getline(fileHandle, tempData.units, ',');
		getline(fileHandle, tempData.program, ',');
		getline(fileHandle, tempData.level);

		//At the end of this loop
		this->insertAtFront(tempData);
	}


	fileHandle.close();
}

void LinkedList::loadMasterList()
{
	fileHandle.open("master.txt", ios::in);
	Node tempData;
	string tempStr = "";
	//getline(fileHandle, tempStr);
	int stackIndex = 0;

	while (getline(fileHandle, tempStr))
	{
		stackIndex = 0;
		getline(fileHandle, tempStr, ',');

		if (tempStr == "")
		{
			break;
		}


		tempData.recordNum = stoi(tempStr);
		getline(fileHandle, tempStr, ',');
		tempData.id_Num = stoi(tempStr);
		getline(fileHandle, tempStr, '"');
		getline(fileHandle, tempData.name, '"');
		getline(fileHandle, tempStr, ',');
		getline(fileHandle, tempData.email, ',');
		getline(fileHandle, tempData.units, ',');
		getline(fileHandle, tempData.program, ',');
		getline(fileHandle, tempData.level, ',');
		getline(fileHandle, tempStr, ',');
		tempData.absences = stoi(tempStr);
		//while < tempData.absences
		while (stackIndex < tempData.absences)
		{
			getline(fileHandle, tempStr, ',');
			tempData.dateAbsent.push(tempStr);
			stackIndex++;
		}

		//At the end of this loop
		this->insertAtFront(tempData);
		
		stackIndex = 0;

		while (stackIndex < tempData.absences)
		{
			tempData.dateAbsent.pop();
			stackIndex++;
		}
	}
	 fileHandle.close();
}

void LinkedList::markAbsence()
{
	Node *pCur = mpHead;
	int option = 0;
	string date = "";
	string tempYear = "";
	// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0);   // get time now

	struct tm * now = localtime(&t);

	int year = now->tm_year + 1900;
	int month = (now->tm_mon + 1);
	int day = now->tm_mday;

	tempYear = std::to_string(year);

	date = std::to_string(year) + '-' + std::to_string(month) + '-'+ std::to_string(day); //+ ',' //


	while (pCur != nullptr)
	{
		cout << "Student: " << pCur->name << endl;
		cout << "Enter 1 to add Absence, 2 for next student::> ";
		cin >> option;
		if (option == 1)
		{
			pCur->absences++;
			pCur->dateAbsent.push(date);
		}
		pCur = pCur->getNextPtr();
	}
}

void LinkedList::storeList()
{
	fileHandle.open("master.txt", ios::out);

	Node *pCur = mpHead;

	fileHandle << ",master,list," << endl;

	while (pCur != nullptr)
	{
		fileHandle << *pCur;
		pCur = pCur->getNextPtr();
	}
	fileHandle.close();
}

void LinkedList::genAbsenceReport()
{
	Node *pCur = mpHead;
	fileHandle.open("absenses.txt", ios::out);

	fileHandle << ",ID,Name,Email,Units,Program,Level,Absences, Most_Recent_Absence" << endl;

	while (pCur != nullptr)
	{
		fileHandle << pCur->id_Num << ", " << pCur->name << ", " << pCur->email <<", " << pCur->units << ", " 
			<< pCur->program << ", " << pCur->level << ", "<< pCur->absences << ", "	<< pCur->dateAbsent.peek() << endl;
		pCur = pCur->getNextPtr();
	}
	fileHandle.close();
}

void LinkedList::genThresholdReport()
{
	int threshold = 10;
	Node *pCur = mpHead;
	fileHandle.open("aboveAbTresh.txt", ios::out);
	int absenceCounter = 0;

	cout << "Specify Threshold::> ";
	cin >> threshold;

	fileHandle << ",ID,Name,Email,Units,Program,Level,Absences Dates" << endl;

	while (pCur != nullptr)
	{
		if (pCur->absences >= threshold)
		{
			fileHandle << pCur->id_Num << ", " << pCur->name << ", " << pCur->email << ", " << pCur->units << ", "
				<< pCur->program << ", " << pCur->level << ", ";
			/*Absence Dates code*/;
			absenceCounter = 0;
			while (absenceCounter < pCur->absences)
			{
				fileHandle << pCur->dateAbsent.pop() << ",";
				absenceCounter++;
			}
			fileHandle << endl;
		}
		pCur = pCur->getNextPtr();
	}
	fileHandle.close();
}

void LinkedList::isAbsent()
{

}

void LinkedList::editAbsence()
{
	int option = 0;
	int IDnum = 0;
	Node *pCur = mpHead;
	int absIndex = 0;
	int yesOrNo = 0;
	Stack tempDates;
	string tempName = "";

	while (option < 1 || option > 2)
	{
		cout << "Edit Absence SubMenu" << endl;
		cout << "Enter 1 to search by ID# or 2 to search by student name ::> " << endl;
		cin >> option;
		if (option == 1)
		{
			cout << "Enter ID number::> ";
			cin >> IDnum;
			while (pCur != nullptr)
			{
				if (pCur->id_Num == IDnum)
				{
					cout << "Here are the absence date available to edit for " << IDnum << endl;
					while (absIndex < pCur->absences)
					{
						cout << "Date: " << pCur->dateAbsent.peek() << ". Do you want to modify thise date ?" << endl;
						cout << "Enter 1 to delete, 2 to keep ::> ";
						cin >> yesOrNo;
						if (yesOrNo == 1)
						{
							pCur->dateAbsent.pop();
							pCur->absences--;
						}
						if (yesOrNo == 2)
						{
							tempDates.push(pCur->dateAbsent.pop());
							pCur->absences--;
						};
					}
					while (!tempDates.isEmpty())
					{
						pCur->dateAbsent.push(tempDates.pop());
						pCur->absences++;
					}
				}
				pCur = pCur->getNextPtr();
			}
		}
		if (option == 2)
		{
			cout << "Enter student name::> ";
			cin >> tempName;
			while (pCur != nullptr)
			{
				if (pCur->name == tempName)
				{
					cout << "Here are the absence date available to edit for " << tempName <<endl;
					while (absIndex < pCur->absences)
					{
						cout << "Date: " << pCur->dateAbsent.peek() << ". Do you want to modify thise date ?" << endl;
						cout << "Enter 1 to delete, 2 to keep ::> ";
						cin >> yesOrNo;
						if (yesOrNo == 1)
						{
							pCur->dateAbsent.pop();
							pCur->absences--;
						}
						if (yesOrNo == 2)
						{
							tempDates.push(pCur->dateAbsent.pop());
							pCur->absences--;
						};
					}
					while (!tempDates.isEmpty())
					{
						pCur->dateAbsent.push(tempDates.pop());
						pCur->absences++;
					}
				}
				pCur = pCur->getNextPtr();
			}

		}
	}
}

Node * LinkedList::makeNode(Node newData)
{
	Node * tempNode = new Node(newData); 
	return   tempNode;
}

void LinkedList::destroyList(Node * pMem)
{
	if (pMem != nullptr)
	{
		destroyList(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

fstream & operator<<(fstream & lhs, Node &rhs)
{
	// TODO: insert return statement here
	lhs << rhs.recordNum << ',' << rhs.id_Num << ',' << '"' << rhs.name << '"' << ',' << rhs.email << ',' << rhs.units << ',' << rhs.program << ','
		<< rhs.level << ',' << rhs.absences << ',';
	lhs << rhs.dateAbsent << endl;

	return lhs;
}

