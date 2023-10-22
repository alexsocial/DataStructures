#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"
//*********************************************************************************************
//	D A T E	. C P P


//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name:	Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:	This is the default constructor which will be called automatically when
//an object is declared.	It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	cout << "Default constructor has been called:" << endl;
	myMonth = 01;
	myDay = 01;
	myYear = 0001;
	cout << setfill('0') << setw(2) << myMonth << "\\" << setfill('0') << setw(2) << myDay << "\\"
		<< setfill('0') << setw(4) << myYear << "\n" << endl;
}


//*************************************************************************************
//Name:	Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description: Explicit Constructor: Prints a calendar date based when a Date 
//object is declared. Intializes the Date with a specific month, day, and year.
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit Constructor has been called:" << endl;
	myMonth = m;
	myDay = d;
	myYear = y;
	//Declares if it can print the date or not
	bool incorrectFormat = false;
	//Leap Year checker
	bool leapYear = false;
	if (myYear % 4 == 0)
	{
		leapYear = true;
	}
	//If month is out of bounds of range...
	if (myMonth > 12 || myMonth < 1)
	{
		cout << "Month = " << myMonth << " is incorrect." << endl;
		incorrectFormat = true;
	}
	//February exception...
	if (myMonth == 2 && myDay > 29)
	{
		cout << "Day = " << myDay << " is incorrect." << endl;
		incorrectFormat = true;
	}
	//Leap Year February Exception...
	else if (leapYear = true && myMonth == 2 && myDay > 30)
	{
		cout << "Day = " << myDay << " is incorrect." << endl;
		incorrectFormat = true;
	}
	//Checks the even months (30 days) and August (31)
	else if ((myMonth % 2 == 0 && myDay > 31) || (myMonth == 8 && myDay > 31))
	{
		cout << "Day = " << myDay << " is incorrect." << endl;
		incorrectFormat = true;
	}
	//Checks odd months and negative days
	else if ((myDay > 31) || (myDay <= 0))
	{
		cout << "Day = " << myDay << " is incorrect." << endl;
		incorrectFormat = true;
	}
	//If year is 0 or lower/10000 or more...
	if (myYear <= 0 || myYear > 9999)
	{
		cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect." << endl;
		incorrectFormat = true;
	}
	//Final Check to print the date or not, if EVERYTHING is correct.
	if (incorrectFormat == false)
	{
		cout << setfill('0') << setw(2) << myMonth << "\\" << setfill('0') << setw(2) << myDay << "\\" 
			<< setfill('0') << setw(4) << myYear << endl;
		if (myYear % 4 == 0) //For some reason, leapYear does not work, thus using the original method to find leap year.
		{
			cout << "This is a leap year." << endl;
		}
	}
	cout << "\n" << endl;

}

//*************************************************************************************
//Name:	Display
//Precondition: N/A
//Postcondition: Date will be printed.
//Description: Prints the date in calendar format.
//
//
//*************************************************************************************
void Date::display()
{
	cout << setfill('0') << setw(2) << myMonth << "\\" << setfill('0') << setw(2) << myDay << "\\"
		<< setfill('0') << setw(4) << myYear << endl;
}

//*************************************************************************************
//Name:	getMonth
//Precondition: Requires a valid month.
//Postcondition: Month will be retained.
//Description: Accessor: Gets the "myMonth" value.
//
//
//*************************************************************************************
int Date::getMonth()
{

	return myMonth;

}

//*************************************************************************************
//Name:	getDay
//Precondition: Requires a valid day.
//Postcondition: Day will be retained.
//Description: Accessor: Gets the "myDay" value.
//
//
//*************************************************************************************
int Date::getDay()
{

	return myDay;

}


//*************************************************************************************
//Name:	getYear
//Precondition: Requires a valid year.
//Postcondition: Year will be retained.
//Description: Accessor: Gets the "myYear" value.
//
//
//*************************************************************************************
int Date::getYear()
{

	return myYear;

}

//*************************************************************************************
//Name: setMonth
//Precondition: Requires a value for myMonth.
//Postcondition: myMonth is correctly changed.
//Description: Mutator: Changes the myMonth value to value m.
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	myMonth = m;
}

//*************************************************************************************
//Name:	setDay
//Precondition: Requires a value for myDay.
//Postcondition: myDay is correctly changed.
//Description: Mutator: Changes the myDay value to value d.
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}

//*************************************************************************************
//Name:	getYear
//Precondition: Requires a value for myYear.
//Postcondition: myYear is correctly changed.
//Description: Mutator: Changes the myYear value to value y.
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}


//*************************************************************************************
//Name:	Overload Operator <</Stream Insertion Operator 
//Precondition: Date& dateObj must be a declared Date class.
//Postcondition: Data is correctly printed.
//Description: Prints specific Date classes as a xx/xx/xxxx format, when calling 
//the class itself.
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{
	out << setfill('0') << setw(2) << dateObj.myMonth << "\\" << setfill('0') << setw(2) << dateObj.myDay << "\\"
		<< setfill('0') << setw(4) << dateObj.myYear;


	return out;

}

//*********************************************************************************************