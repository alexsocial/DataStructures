#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std; 


class string_class
{
private:
	//required private members
	string current_string;
public:
	//public functions/members
	string_class(); //Default Constructor: Sets current_string to "";
	string_class(string s); //Explicit Constructor: Sets current_string to whatever s is.
	bool palindrome(); //Palindrome function: Checks if string is a palindrome
	void replace_all(string oldS, string newS); //Replace All function; Works similar to Ctrl+F and Replace, where
	//It replaces instances of x with y.
	friend ostream& operator<< (ostream& out, const string_class& stringObj); //Overload operator with chaining:
	//Replaces the << function.
};