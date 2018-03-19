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
bool LinkedList::insertAtFront(Node newData)     // inserts newData at the beginning or front of the list
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
	
	while ( fileHandle.good() )
	{
		getline(fileHandle, tempStr, ',');
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

void LinkedList::isAbsent()
{

}

Node * LinkedList::makeNode(Node newData)
{
	Node tempNode(newData);
	return &tempNode;
}

void LinkedList::destroyList(Node * pMem)
{
	if (pMem != nullptr)
	{
		destroyList(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}
