#include "stack.h"
#include <iostream>
#include <string>
#include <iomanip> //Unsure if these last two are necessary, but are nice to have.
#include <algorithm>

using namespace std;

//*************************************************************************************
//Name:	Default Constructor
//Precondition: N/A
//Postcondition: Linked List and Stack is initialized.
//Description: Sets top to 0.
//*************************************************************************************
stack::stack()
{
	cout << "\nDefault constructor called." << endl;
	top = 0;
}
//*************************************************************************************
//Name:	Copy Constructor
//Precondition: Requires an existing stack.
//Postcondition: Linked List and Stack is copied into org.
//Description: Copies a stack into another stack.
//*************************************************************************************
stack::stack(const stack& org)
{
	cout << "\nCopy constructor called." << endl;
	top = org.top;
}
//*************************************************************************************
//Name:	Destructor
//Precondition: Requires an existing stack.
//Postcondition: Stack is deleted.
//Description: Removes a currently existing stack.
//*************************************************************************************
stack::~stack()
{
	cout << "\nDestructor called." << endl;
	while (top != 0)
	{
		pop();
	}
}
//*************************************************************************************
//Name:	Pop function
//Precondition: Requires an existing stack with at least one variable.
//Postcondition: Variable is deleted from stack.
//Description: Removes a currently existing variable from a stack.
//*************************************************************************************
string stack::pop()
{
	//newStack is meant to be the resulted string, removing an element from linked list,
	//while cur is meant to be the position of the node.
	node* cur;
	string oldValue;
	//Sets cur to top, and removes it by setting it to the next one.
	if (top != 0)
	{
		cur = top;
		oldValue = cur->stack_element;
		top = top->next;
		delete cur;
		return oldValue;
	}
	return "\0";

	
}
//*************************************************************************************
//Name:	Push function
//Precondition: Requires an existing stack.
//Postcondition: Variable is added to stack.
//Description: Pushes a new variable to the front.
//*************************************************************************************
void stack::push(const string& s)
{
	node* cur = new node;
	cur->stack_element = s;
	cur->next = top;
	top = cur;
}
//*************************************************************************************
//Name:	Print function
//Precondition: Requires an existing stack with at least one variable.
//Postcondition: Stack (infix) is printed.
//Description: Prints the stack.
//*************************************************************************************
void stack::print()
{
	node* cur;
	cur = top;
	while (cur->next != nullptr)
	{
		cout << cur->stack_element;
		cur = cur->next;
	}
	cout << cur->stack_element;
}
//*************************************************************************************
//Name:	Conversion function
//Precondition: Requires an existing stack with at least one variable.
//Postcondition: Postfix is converted to infix.
//Description: Converts the postfix to an infix.
//*************************************************************************************
void stack::conversion(string post)
{
	
	string tempElement1 = ""; //elements to be operated
	string tempElement2 = "";
	string oper = ""; //operator
	string temp = "";
	char space = ' '; //checks for spaces
	int len = post.length(); //length of postfix
	int operandCount = 0; //count of operands
	int operatorCount = 0; //count of operators
	string result = ""; //infix result

	for (int i = 0; i < len; i++) //part 1: gets the counts of everything, and follows through with errors.
	{
		if (post[i] != space) //converts char to string, then pushes it in.
		{
			temp += post[i];
			if (i == 0 && (temp == "+" || temp == "-" || temp == "*" || temp == "/"))
			{
				cout << "Error! Cannot start with an operator." << endl;
				break;
			}
			if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
			{
				operatorCount++;
				if (operandCount == 1 && operandCount == operatorCount)
				{
					cout << "Error! Cannot start with an operator in between first two operands." << endl;
					return;
				}
			}
			else
			{
				operandCount++;
			}
			temp = "";
		}
	}
	if (operatorCount >= operandCount)
	{
		cout << "Error! Too many operators, not enough operands." << endl;
		return;
	}
	else if (operatorCount < (operandCount - 1))
	{
		cout << "Error! Too many operands, not enough operators." << endl;
		return;
	}
	
	//part 2: performs actual algorithm after error checking
	for (int i = 0; i < len; i++) 
	{
		if (post[i] != space) //converts char to string, then pushes it in.
		{
			temp += post[i];
			if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
			{
				oper = temp;
				tempElement2 = top->stack_element;
				pop();
				tempElement1 = top->stack_element;
				pop();
				result = "(" + tempElement1 + oper + tempElement2 + ")";
				push(result);
				
			}
			else
			{
				push(temp);
			}
		}
		temp = "";
	}
	print();
}