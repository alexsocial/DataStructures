#include <iostream>
#include <string>
using namespace std;
//*****************************************************************************
//P R O G R A M	H E A D E R
//
//	Name:	Alex Chaban

//	Z#:	25313043
//	Instructor:	Dr. Bullard
//	Class:	Data Structures
//	Term:	Spring 2021
//	Assignment #8A (Palindrome)
//	Due Date:	3/26/2021
//	Due Time:	11:59PM
//	Points:	25
//
//	Description: This program accesses your C++language skills.
//	Tests the ability to use recursion to create a palindrome
//  checker.
//******************************************************************************
bool palindrome(const string& s) //Palindrome checker.
{
	if (s == "") //NULL checker
	{
		return true;
	}
	char b = s[0]; //beginning
	char e = s[s.length() - 1]; //end
	if (s.length() <= 1) //if length is zero or one, returns true regardless, as it'll be one or no characters									
											//automatically making it a palindrome
	{
		return true;
	}
	if (s.length() == 2) //For some reason, logic does not work with twos, so I implemented a special case.
	{
		if (b == e)
		{
			return true;
		}
	}
	if (b != e) //If the beginning DOES NOT match the end
	{
		return false;
	}
	else
	{
		string sub = s.substr(1, s.length() - 2);
		return palindrome(sub);
	}
	 //Checks if length is zero, and if not, recurses through again until proven false if not
	 //a palindrome.
	
		
	
	
}
string printReversel(const string& s) //Recursive reversal
{ 
	if (s == "") //NULL checker
	{
		return "";
	}
	string reverse = "";
	int e = s.length() - 1;
	//move s one letter at a time, then recursive into the function again and again.
	if (s.length() == 0)
	{
		return "";
	}
	else
	{
		//add end of s to reverse, then make a new s with one less letter.
		reverse += s[e];
		reverse += printReversel(s.substr(0, (e)));
	}
	return reverse;
}
string printIterReverse(const string& s) //Non-Recursive Reversal
{ 
	if (s == "") //NULL checker
	{
		return "";
	}
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		reverse += s[i];
	}
	return reverse;
}



int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no) ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
