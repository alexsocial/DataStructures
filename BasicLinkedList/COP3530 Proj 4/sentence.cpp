#include "sentence.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

//*************************************************************************************
//Name:	Default Constructor
//Precondition: N/A
//Postcondition: Linked List is initialized.
//Description: Sets front and back to NULL.
//*************************************************************************************
sentence::sentence()
{
	front = NULL;
	back = NULL;
}
//*************************************************************************************
//Name:	Explicit Constructor
//Precondition: Requires one string pointer.
//Postcondition: Linked List is initialized with string s.
//Description: Separates the string s by words (if it has spaces) and places each word
//into it's own separate node (word in this case). 
//*************************************************************************************
sentence::sentence(const string& s)
{
	int len = s.length(); //Intializes a length, tempTerm string, space char, and x will be used to determine first space.
	string tempTerm = "";
	char space = ' ';
	int x = 0;
	if (len == 0) //Basically in case they don't want to type anything.
	{
		front = NULL;
		back = NULL;
	}
	else //Otherwise, runs this code.
	{
		while (s[x] != space) //Detects first space.
		{
			tempTerm += s[x];
			x++;
		}

		front = new word; //Intializes front as a new word, and assigns its node to the tempTerm.
		front->term = tempTerm;
		tempTerm = "";
		word* prevWord = front;
		for (int i = (x + 1); i < len; i++) //Starts at the first space plus one, loops adding until it hits a space, separating the words.
		{
			if (s[i] == space)
			{
				word* w = new word;
				w->term = tempTerm;
				prevWord->next = w;
				prevWord = w;
				tempTerm = "";
			}
			else
			{
				tempTerm += s[i];
			}
		}
		word* w = new word;
		w->term = tempTerm;
		prevWord->next = w;
	}
}
//*************************************************************************************
//Name:	Copy Constructor
//Precondition: Requires one sentence class.
//Postcondition: Sentence class org is intialized.
//Description: Copies the sentence class to org.
//*************************************************************************************
sentence::sentence(const sentence& org)
{
	front = org.front;
	back = org.back;
}
//*************************************************************************************
//Name:	Destructor
//Precondition: Requires one word class.
//Postcondition: Word class is deleted.
//Description: Removes the word class org.
//*************************************************************************************
sentence::~sentence()
{
	cout << "Destructor Called." << endl;
	front = 0;

	delete front;
}
//*************************************************************************************
//Name:	Get Length
//Precondition: Requires one word class.
//Postcondition: Length is obtained.
//Description: Gets the length of the current word object.
//*************************************************************************************
int sentence::length()
{
	
	int count = 0;
	word* cur = front;
	//Checks if front is NULL
	if (front == NULL)
	{
		return 0;
	}
	//Loops until the front = the back where it's NULL
	while (front != NULL)
	{
		count += cur->term.length() + 1; //The +1 is for spaces.
		if (cur->next == nullptr)
		{
			break;
		}
		else
		{
			cur = cur->next;
		}
			
	}
	return count;
}
//*************************************************************************************
//Name:	Add Back
//Precondition: Requires one sentence class with at least one word node.
//Postcondition: Node is added.
//Description: Adds a node to the back of the sentence.
//*************************************************************************************
void sentence::add_back(string& s)
{
	word* cur = front;
	//One node case
	if (front == back && back != NULL)
	{
		cur = cur->next;
		cur->term = s;
	}
	else
	{
		//Intializes a new word object/
		word* new_word = new word();
		//Sets the term s to the string.
		new_word->term = s;
		//Sets the next node of last to be the new word.
		back->next = new_word;
		//Since its last, the next one needs to be NULL.
		new_word->next = NULL;
	}
}
//*************************************************************************************
//Name:	<< Operator
//Precondition: Requires one sentence class with at least one word node.
//Postcondition: Sentence is printed correctly.
//Description: Prints sentence object in correct format.
//*************************************************************************************
ostream& operator<<(ostream& out, const sentence& s)
{
	word* cur = s.front;
	while (cur != NULL) //Makes sure the current position isn't null.
	{
		out << cur->term << " "; //Prints term, then moves on to next until null.
		cur = cur->next;
	}
	return out;
}
//*************************************************************************************
//Name:	= Operator
//Precondition: Requires one string.
//Postcondition: String is set.
//Description: Sets the string equal to string s.
//*************************************************************************************
void sentence::operator=(const string& s)
{
	int len = s.length(); //Intializes a length, tempTerm string, space char, and x will be used to determine first space.
	string tempTerm = "";
	char space = ' ';
	int x = 0;
	if (len == 0) //Basically in case they don't want to type anything.
	{
		front = NULL;
		back = NULL;
	}
	else //Otherwise, runs this code.
	{
		while (s[x] != space) //Detects first space.
		{
			tempTerm += s[x];
			x++;
		}

		front = new word; //Intializes front as a new word, and assigns its node to the tempTerm.
		front->term = tempTerm;
		tempTerm = "";
		word* prevWord = front;
		for (int i = (x + 1); i < len; i++) //Starts at the first space plus one, loops adding until it hits a space, separating the words.
		{
			if (s[i] == space)
			{
				word* w = new word;
				w->term = tempTerm;
				prevWord->next = w;
				prevWord = w;
				tempTerm = "";
			}
			else
			{
				tempTerm += s[i];
			}
		}
		word* w = new word;
		w->term = tempTerm;
		prevWord->next = w;
	}
	
}
//*************************************************************************************
//Name:	+ Operator
//Precondition: Requires one sentence class with at least one word node.
//Postcondition: Sentence is added correctly.
//Description: Adds two sentence objects successfully.
//*************************************************************************************
void sentence::operator+(sentence& B)
{
	if (B.length() == 0)
	{
		return;
	}
	else if (length() == 0)
	{
		*this = B;
		return;
	}
	word* checkA = new word;
	word* checkB = new word;

	checkA = back;
	checkB = B.front;

	while (checkB != NULL) //Allocates memory, moves it to the next node, and copies over terms to add (All while The front of B is not zero/NULL)
	{ 
		checkA->next = new word;
		checkA = checkA->next;
		checkA->term = checkB->term;
		checkB = checkB->next;
	}
}
//*************************************************************************************
//Name:	Is Equal Function
//Precondition: Requires one sentence class with at least one word node.
//Postcondition: Returns 1 or 0.
//Description: Checks if two sentence objects are equal.
//*************************************************************************************
bool sentence::isEqual(sentence& B)
{
	if (length() != B.length()) //checks if sizes are the same first.
	{
		return 0;
	}

	word* checkA = new word;
	word* checkB = new word;
	//Start at the fronts...
	checkA = front;
	checkB = B.front;

	while (checkA != NULL && checkB != NULL)
	{
		if (checkA->term != checkB->term) //compares the two terms 
		{
			return 0; //Returns 0 if the terms don't match
		}
		else
		{
			checkA = checkA->next;
			checkB = checkB->next;
			//Moves onto the next
		}
	}
	return 1; //If all passes, returns 1 for true.
}
//*************************************************************************************
//Name:	Remove Function
//Precondition: Requires one sentence class with at least one word node and a string.
//Postcondition: String is removed.
//Description: Removes a string from a sentence object.
//*************************************************************************************
void sentence::remove(const string& s)
{
	//checks if empty
	if (s.length() == 0)
	{
		return;
	}
	//creates a word to be deleted, starting at the front
	word* toDelete = new word;
	toDelete = front;

	while (toDelete != NULL)
	{
		string phrase = toDelete->term;
		int position = phrase.find(s);
		if (toDelete->term == s)
		{
			phrase.replace(position, s.length(), "");
			toDelete->term = phrase;
			break;
		}
		toDelete = toDelete->next;
	}
}