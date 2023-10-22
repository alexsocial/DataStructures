#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "vlist.h" 
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Default Constructor
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist()
{
	cout << "Default Constructor called." << endl;
	DB.resize(9); //Resizes vector to nine, and sets count to zero.
	count = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Copy Constructor
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & Org)
{
	cout << "Copy Constructor called." << endl; //Hard copy.
	count = Org.count; 
	DB = Org.DB;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Destructor
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
vlist::~vlist()
{
	cout << "Destructor called." << endl;
	DB.clear(); //Clears entire list and sets count.
	count = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Is Empty
//Precondition: Command has not been invoked.
//Postcondition: Returns if the function is empty or not.
//Description: Checks if the vector list is empty.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
bool vlist::isEmpty() 
{
	if (count == 0)
		return true;
	else
		return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Search
//Precondition: Search has not been invoked.
//Postcondition: Element is found or not found.
//Description: Finds an element in the vector.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
vector<string>::iterator vlist::search(const string& key)
{
	if (!isEmpty()) //checks if empty...
	{
		for (auto el = DB.begin(); el != DB.end(); el++) //Auto makes life a little easier, as it
			//auto sets the element to be an iterator.
		{
			if (key == *el) //Checks if the POINTER of el is the key.
			{
				cout << "Item found!" << endl;
				return el;
			}
		}
		cout << "Item not found." << endl;
		cout << key << endl;
		return DB.end();
	}
	else
	{
		cout << "Vector is empty." << endl;
		return DB.end();
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Insert
//Precondition: Insert has not been invoked.
//Postcondition: Element inserted.
//Description: Inserts an element into the vector.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
void vlist::insert(const string & key)
{
	DB.push_back(key); //using functions given in <vector>
	count++;
	sort(DB.begin(), DB.end()); //<algorithm>
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Remove
//Precondition: Remove has not been invoked.
//Postcondition: Element removed.
//Description: Removes an element from the vector.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
void vlist::remove(const string& key) 
{
	auto check = search(key); //Again, auto used for iterator
	if (check != DB.end()) //Checks if it isnt the end from search
	{
		DB.erase(check); //Erases if true, and subtracts count.
		count--;
	}
	else
	{
		cout << "Item not in vector." << endl;
		return;
	}
	
	
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Print
//Precondition: Print has not been invoked.
//Postcondition: Vector printed.
//Description: Prints the entire vector.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
void vlist::print() 
{
	cout << "Print called." << endl;
	for (auto i = DB.begin(); i != DB.end(); i++) //auto sets to iterator
	{ 
		cout << *i << "\n"; //prints the element POINTER.
	}
}

