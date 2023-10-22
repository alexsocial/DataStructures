#include <iostream> //Including many things just in case need to use
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
//*****************************************************************************
//P R O G R A M	H E A D E R
//
//	Name:	Alex Chaban

//	Z#:	25313043
//	Instructor:	Dr. Bullard
//	Class:	Data Structures
//	Term:	Spring 2021
//	Assignment #8B (Linked List Recursion)
//	Due Date:	3/29/2021
//	Due Time:	11:59PM
//	Points:	25
//
//	Description: This program accesses your C++language skills.
//	Tests the ability to use recursion within linked lists.
//******************************************************************************
class node
{
public:
	node* next;
	int data;
};

//FUNCTION PROTOTYPES
void fun(node* start);
void add_back(node*& start, node*& end, int data);

//MAIN
int main()
{
	node* front = 0;
	node* back = 0;
	for (int i = 1; i <= 6; i++)
	{
		add_back(front, back, i);
	}
	fun(front);
	return 0;
}
//FUNCTIONS
void fun(node* start) //Given by prof.
{
	if (start == NULL)
	{
		return;
	}
	cout << start->data << endl;

	if (start->next != NULL)
	{
		fun(start->next->next);
	}
	cout << start->data << endl;
}

void add_back(node*& start, node*& end, int x)
{
	node* cur = new node; //Creates new node
	cur->data = x; //Sets cur's data to x and next to NULL, thus always being the end.
	cur->next = NULL;
	if (start == end && start == nullptr) //Checks if it is a one item list. If so, creates the first item.
	{
		start = end = cur;
	}
	else //Otherwise, sets the end and next of end to be cur.
	{
		end->next = cur; 
		end = cur;
	}
	return;
}