#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

/********************************************************************************************

Name: Alex Chaban
Z#: 23513043
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 3/03/2021
Due Time: 11:59PM
Total Points: 25
Assignment 5: String Stacks + Linked List Program (Module 7)

Description:
This program is to combine current knowledge of singly linked lists
and to experiment, manipulate, and learn how to work with stacks of strings.
*********************************************************************************************/

int main()
{
	stack S;
	string userPostfix;
	string userResponse = "y";

	while (userResponse == "y" || userResponse == "Y")
	{
		cout << "Please enter a postfix expression formatted like so: a b + c d - *: ";
		getline(cin, userPostfix);
		S.conversion(userPostfix);
		S.~stack();
		cout << endl;

		cout << "Would you like to input another postfix? (y/n): ";
		getline(cin, userResponse);
		cout << endl;
	}
}