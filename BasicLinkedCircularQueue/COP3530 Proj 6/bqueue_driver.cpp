#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bqueue.h"

using namespace std;

/********************************************************************************************

Name: Alex Chaban
Z#: 23513043
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 3/12/2021
Due Time: 11:59PM
Total Points: 25
Assignment 6: Doubly Linked Lists + Queues

Description:
This program is to combine current knowledge of doubly linked lists
and to experiment, manipulate, and learn how to work with queues.
*********************************************************************************************/

int main()
{
	bqueue k;
	k.enqueue(60);
	k.print();
	k.enqueue(20);
	k.enqueue(30);
	k.print();
	k.enqueue(10);
	k.print();
	k.enqueue(50);
	k.enqueue(40);
	k.print();

	bqueue j = k;

	j.dequeue(); 
	j.print(); 
	j.dequeue(); 
	j.dequeue(); 
	j.dequeue(); 
	j.print(); 
	j.dequeue(); 
	j.dequeue(); 
	j.print(); 
	j.dequeue(); 
	j.dequeue();

	cout << "separate" << endl;
	k.print();

	return 0;
}