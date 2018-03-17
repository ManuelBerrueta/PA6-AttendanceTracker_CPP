#include "Menu.h"
#include "Node.h"

/*
Menu: At startup of the program a menu must be displayed. The menu must support six options. These include:

1.    Import course list

2.    Load master list

3.    Store master list

4.    Mark absences

5.    BONUS: Edit absences

6.    Generate report

7.    Exit

Option 1: Reads the .csv course file and overwrites the master list.

Option 2: Populates the master list with previous nodes from master.txt.

Option 3: Stores the contents of the master list’s nodes to master.txt.

Option 4: Runs through the master list, displays each student’s name, and prompts if he/she was absent for the current day. The data must be pushed to the stack that is contained within the node representative of the student.

BONUS: Option 5: Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit.

Option 6: Leads to submenu -> 1. Generate report for all students; showing only the most recent absence for each student. This is a peek () operation! 2. Generate report for students with absences that match or exceed (the number entered by the user).

Option 7: Exit the program.

*/

Menu::Menu()
{
	mInput.open("classList.csv", ios::in);
	//need to finish FIle reading functions First!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


	LinkedList List();
	Data data;
	int load_status = 0;

	int option = 0;
	while (option < 1 || option > 11)
	{
		cout << ("-=-==-===-==== Manny's Attendance Tracker ====-===-==-=-") << endl;
		cout << ("* MAIN MENU *\n") << endl;
		cout << ("(1)   Import course list") << endl;
		cout << ("(2)   Load master list") << endl;
		cout << ("(3)   Store master list") << endl;
		cout << ("(4)   Mark Absences") << endl;
		cout << ("(5)   Edit Absences") << endl;
		cout << ("(6)   Generate report") << endl;
		cout << ("(7)   Exit") << endl;
		cin >> option;
		
		system("cls");

		switch (option)
		{

		case 1:
			//Load Function
			if (load_status == 0)
			{
				load(&pList);
				load_status = 1;
			}
			else
			{
				printf("List is already loaded!\n");
				system("pause");
			}
			system("cls");
			option = 0;
			break;

		case 2:
			//Store Function
			store(pList);
			system("cls");
			option = 0;
			break;

		case 3:
			//Display Function
			display(pList);
			system("cls");
			option = 0;

			break;

		case 4:
			//Insert Function
			insert(&pList);
			system("cls");
			option = 0;
			break;

		case 5:
			//Delete Function
			del_rec(&pList);
			system("cls");
			option = 0;
			break;

		case 6:
			//Edit Function
			edit(pList);
			system("cls");
			option = 0;
			break;

		case 7:
			//Sort Function
			sort(pList);
			system("cls");
			option = 0;
			break;

		case 8:
			//Rate Function
			rate(pList);
			system("cls");
			option = 0;
			break;

		case 9:
			//Play Function
			play(pList);
			system("cls");
			option = 0;
			break;

		case 10:
			//Shuffle Function
			shuffle(pList);
			system("cls");
			option = 0;
			break;

		case 11:
			store(pList);
			exit(0);
			//Exit Function
			return 0;
			break;
		default:
			printf("Please select from options 1-13\n\n");
			system("pause");
			system("cls");
		}
	}

}
