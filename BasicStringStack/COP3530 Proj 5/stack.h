#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef STACK_H
#define STACK_H

class node
{
public:
	string stack_element;
	node* next;
};
class stack
{
public:
	stack(); //Default constructor
	stack(const stack& org); //Copy constructor 
	~stack(); //Destructor: Removes a currently existing stack.
	bool isEmpty() { return top == 0; } //Checks if the stack is empty.
	string pop(); //Pop function: Removes one variable
	void push(const string& s); //Push function: Pushes a new variable to the front.
	void print(); //Print function: Prints the infix expression.
	void conversion(string post); //Conversion function: Converts the postfix expression to the infix expression

private:
	node* top;
};

#endif