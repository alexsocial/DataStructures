#pragma once
class bqnode
{
public:
	int data; //data
	bqnode* prev, *next; //Nodes for previous and next set of data.

};

class bqueue
{
public:
	bqueue(); //Default constructor
	~bqueue(); //Destructor
	bqueue(const bqueue& org); //Copy Constructor
	void enqueue(int x); //Queue Up Function
	void dequeue(); //Queue removal function
	void print(); //Queue print function
	bool Empty() { return front == 0; } //Is it empty?

private:
	bqnode* front; //use ONE pointer.
};