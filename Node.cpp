#include "Node.h"

Node::Node()
{
	recordNum = 000;		//(max 3 digits)
	id_Num = 000000000;		//(max 9 digits)
	name = "Empty";			// (last, first)
	email = "0@empty.com";
	units = "0";			// (number of credits for class or AU for audit)
	program = "";			//(major)
	level = "";			// (freshman, sophomore, junior, senior, graduate)
	absences = 0;			//Numbers of absences
	Stack dateAbsent;		//Stack using an array of strings

	mpNext = nullptr;
}

Node::Node(Node & newNode)
{
	recordNum = newNode.recordNum;
	id_Num = newNode.id_Num;	//(max 9 digits)
	name = newNode.name;			// (last, first)
	email = newNode.email;
	units = newNode.units;			// (number of credits for class or AU for audit)
	program = newNode.program;			//(major)
	level = newNode.level;			// (freshman, sophomore, junior, senior, graduate)
	absences = newNode.absences;			//Numbers of absences
	Stack dateAbsent;					//Stack using an array of strings

	mpNext = nullptr;

}

Node::~Node()
{
}

Node * Node::getNextPtr()
{
	return mpNext;
}

void Node::setNextPtr(Node * newNextPtr)
{
	mpNext = newNextPtr;
}
