#include "string_class.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>


//*************************************************************************************
//Name:	Default Constructor
//Precondition: N/A
//Postcondition: String is initialized.
//Description: Sets current_string to "";
//*************************************************************************************
string_class::string_class()
{
	current_string = "";
}
//*************************************************************************************
//Name:	Explicit Constructor
//Precondition: Requires a string of any kind.
//Postcondition: String is initialized.
//Description: Sets current_string to whatever s is.
//*************************************************************************************
string_class::string_class(string s)
{
	current_string = s;
}
//*************************************************************************************
//Name:	Palindrome Function
//Precondition: Requires a string that has a value.
//Postcondition: Palindrome is returned as true/false.
//Description: Checks if string is a palindrome
//*************************************************************************************
bool string_class::palindrome()
{
	string reverse = "";
	bool check = false;
	//Builds the string backwards then checks if it backwards equals it forwards.
	for (int i = current_string.length() - 1; i > -1; i--)
	{
		reverse = reverse + current_string[i];
	}
	for (int i = 0; i < current_string.length(); i++)
	{
		if (tolower(current_string[i]) == tolower(reverse[i]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//*************************************************************************************
//Name:	Replace All Function 
//Precondition: Requires two strings, oldS and newS with values.
//Postcondition: Data is found and replaced.
//Description: Works similar to Ctrl+F and Replace, where it replaces instances of x with y.
//*************************************************************************************
void string_class::replace_all(string old_substring, string new_substring)
{
	//Length of strings
	int oldLength = old_substring.length();
	int newLength = new_substring.length();
	//Strings that are necessary to perform this
	string checker = "";
	string newString = "";
	//Pre-emptive conditions
	if (current_string == "" || oldLength > current_string.length())
	{
		cout << "Conditions do not match." << endl;
	}
	else
	{
		for (int i = 0; i < current_string.length(); i++) 
		{
			for (int j = i; j < oldLength + i; j++) 
			{
				if (j >= current_string.length()) 
				{
					break;
				}
				checker = checker + current_string.at(j);
			}
			if (old_substring == checker) 
			{
				newString = newString + new_substring;
				i = i + oldLength - 1;
			}
			else 
			{
				newString = newString + current_string.at(i);
			}
			checker = "";
		}
		current_string = newString;
	}
}
//*************************************************************************************
//Name:	Overload Operator <</Stream Insertion Operator 
//Precondition: string_class& stringObj must be a declared Date class.
//Postcondition: Data is correctly printed.
//Description: Prints specific string classes as the current_string string.
//*************************************************************************************
ostream& operator<<(ostream& out, const string_class& stringObj)
{
	out << stringObj.current_string << endl;
	return out;
}