#include "bqueue.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//*************************************************************************************
//Name:	Default Constructor
//Precondition: N/A
//Postcondition: Linked List and Queue is initialized.
//Description: Sets front to 0.
//*************************************************************************************
bqueue::bqueue()
{
	front = 0;
}
//*************************************************************************************
//Name:	Destructor
//Precondition: Requires an existing queue.
//Postcondition: Linked List and Queue are destroyed.
//Description: Destroys the queue.
//*************************************************************************************
bqueue::~bqueue()
{
	cout << "Destructor called." << endl;
	if (Empty())
	{
		while (!Empty())
		{
			dequeue();
		}
	}
}
//*************************************************************************************
//Name:	Copy Constructor
//Precondition: Requires an existing queue.
//Postcondition: Linked List and Queue are copied.
//Description: Copies the current queue into another.
//*************************************************************************************
bqueue::bqueue(const bqueue& org)
{
	front = org.front;
}
//*************************************************************************************
//Name:	Queue Up Function
//Precondition: Requires an existing queue with at least one variable.
//Postcondition: Element was added into the queue.
//Description: Adds an element into the queue.
//*************************************************************************************
void bqueue::enqueue(int x)
{
	if (Empty())
	{
		front = new bqnode;
		front->next = front->prev = front;
		front->data = x;
		
	}
	else
	{
		bqnode* cur = new bqnode;
		cur->data = x;
		cur->prev = front->prev;
		cur->next = front;
		front->prev = cur;
		cur->prev->next = cur;
	}

}
//*************************************************************************************
//Name:	Queue Delete Function
//Precondition: Requires an existing queue with at least one variable.
//Postcondition: Element was deleted from the queue.
//Description: Deletes an element into the queue.
//*************************************************************************************
void bqueue::dequeue()
{
	bqnode* cur = front;
	if (Empty())
	{
		cout << "Queue is empty." << endl;
		return;
	}
	else
	{
		if(cur != front->next)
		{
			front->prev->next = cur->next;
			front->next->prev = cur->prev;
			front = front->next;		
		}
		else
		{
			front = 0;
		}
		delete cur;
	}
}
//*************************************************************************************
//Name:	Print Function
//Precondition: Requires an existing queue with at least one variable.
//Postcondition: Elements are printed.
//Description: Prints all elements of a queue.
//*************************************************************************************
void bqueue::print()
{
	bqnode* cur = front;
	if (!Empty())
	{
		while (cur->next != front)
		{
			cout << cur->data << endl;
			cur = cur->next;
		}
		cout << cur->data << endl;
	}
	else
	{
		cout << "Queue is empty." << endl;
	}
}
