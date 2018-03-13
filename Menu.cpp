#include "Menu.h"

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

