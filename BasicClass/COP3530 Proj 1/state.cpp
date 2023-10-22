
#include "state.h"
#include <iomanip>  //need to use formatting manipulators

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/
state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];
	//used to find space and take lines of the file
	string line;
	int space = 0;
	string name;
	string number;
	//creates in stream and opens the file needed to transfer data 
	ifstream in;
	in.open("census2020_data.txt");
	//Checks if file can be opened.
	if (in.fail())
	{
		cout << "File did not open.";
	}
	else
	{
		//if full before end of file runs the double size function until reaches end of file (if file opens)
		while (!in.eof())
		{
			if (Is_Full())
				double_size();
			//gets the entire line of data
			getline(in, line);
			//breaks up the line into name and number
			//starts at the END of the line so it finds the last space
			//thus breaking it up from beginning to the final space
			for (int i = line.length(); i > 0; i--)
			{
				if (line[i] == ' ')
				{
					space = i;
					break;
				}
			}
			name = line.substr(0, space);
			pop_DB[count].state_name = name;
			//resets name after each loop
			name = " ";
			//gets number and adds it to string, then converts into double
			for (int j = line.length(); j > space; j--)
			{
				number = line[j] + number;
			}
			pop_DB[count].population = std::stod(number);
			//resets number after each loop
			number = " ";
			count++;
		}
		
		
		in.close();
	}
}

/******************************************************************************************************************************************************
Name: Copy Constructor
Pre-Condition: Records are not copied
Post-Condition Records are copied
Description: Copy a state class into the copy constructor
******************************************************************************************************************************************************/
state_class::state_class(const state_class & org)
{
	//note: org is the copy, thus everything will be used org.[example]
	capacity = org.capacity;
	count = org.count;
	//creates new pop_DB
	pop_DB = new population_record[capacity];
	//placeholder variable
	int check = 0;
	//loop to copy info from pop_DB to org.
	while (check < count)
	{
		pop_DB[check] = org.pop_DB[check];
		check++;
	}

}

/******************************************************************************************************************************************************
Name: Destructor
Pre-Condition: Unused memory is not removed.
Post-Condition Unused memory is removed and deallocates space.
Description: Removes the unallocated space from memory.
******************************************************************************************************************************************************/
state_class::~state_class()
{
	//deletes the old pop_DB, sets the capacity and count to 0.
	delete[] pop_DB;
	capacity = 0;
	count = 0;
}

/******************************************************************************************************************************************************
Name: Double Size Function
Pre-Condition: The size of the memory allocated is not doubled before execution.
Post-Condition: The size of the memory allocated is doubled before execution.
Description: double the capacity (size) of the memory allocate to the dynamic array pop_DB.
******************************************************************************************************************************************************/
void state_class::double_size()
{
	if (Is_Full())
	{
		//doubles capacity
		capacity *= 2;
		//creates temp record
		population_record* temp = new population_record[capacity];
		//adds old data into temp from pop_DB;
		for (int i = 0; i < count; i++) 
		{ 
			temp[i] = pop_DB[i]; 
		}
		//removes old pop_DB
		delete[] pop_DB;
		//makes pop_DB same allocation as temp
		pop_DB = temp;
	}
	
}

/******************************************************************************************************************************************************
Name: Overload Operator/Insert Function
Pre-Condition: pop_DB exists and contains variables.
Post-Condition: pop_DB now contains the new state and population added to it.
Description: Overload operator+ without chaining.  The function inserts a popultation record into the population dynamic array (pop_DB).
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	//since isFull() does not work here...
	if (count >= capacity)
	{
		double_size();
	}
	//initializes new record
	population_record newRecord;
	//Overloads the operator w/o chaining
	if (r.state_name.empty())
	{
		cout << "Please enter a state name: ";
		cin >> newRecord.state_name;
		cout << "Please enter a population: ";
		cin >> newRecord.population;
	}
	// The new record otherwise has to take from the original array
	else
	{
		newRecord.state_name = r.state_name;
		newRecord.population = r.population;
	}
	pop_DB[count] = newRecord;
	count++;
}

/******************************************************************************************************************************************************
Name: Search Function
Pre-Condition: pop_DB needs to be initialized and contains variables
Post-Condition: array slot will be found
Description: search pop_DB for a state in pop_DB. If the state is in pop_DB the location of the record is return; otherwise a -1 is returned.
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	//loops through the entire array and finds the specific state at point i, else returns -1.
	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].state_name == (state))
			return i;
	}
	cout << "Error! Could not find state you're looking for." << endl;
	return -1;
}


/******************************************************************************************************************************************************
Name: Remove Function
Pre-Condition: pop_DB must be initialized and contains variables.
Post-Condition: Once found, the slot will be removed.
Description: deletes a population record from pop_DB if the key field matches the state name.
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	int removal;
	//searches for state needed to be removed
	removal = Search(state);
	//checks if it isn't a state in the list
	if (removal != -1)
	{
		//shifts the list by 1
		for (int j = removal; j < count; j++)
		{
			pop_DB[j] = pop_DB[j + 1];
		}
		//subtracts count by one to keep balance
		count--;
	}
	else
	{
		cout << "Could not remove. State put is not in list." << endl;
	}

}


/******************************************************************************************************************************************************
Name: Print to File Function
Pre-Condition: Requires at least one variable in pop_DB, file name to print to
Post-Condition: Everything from pop_DB is printed to the file.
Description: Prints all the fields of all the population records stored in pop_DB to the filename stored in datafile.
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	
	cout.setf(ios::fixed);
	cout.precision(0);

	ofstream out;
	out.open(filename);

	if (out.fail())
	{
		cout << "Output file did not open." << endl;
	}
	int count2 = 0;
	out << "\n\tState:\t\t    Population:\n";
	for (int i = 0; i < count; i++)
	{
		//prints and makes it look nice
		out << setw(25) << pop_DB[i].state_name << "\t" << ' ' << (int)pop_DB[i].population << endl;
	}
	out.close();
}
/******************************************************************************************************************************************************
Name: Print All Function
Pre-Condition: Nothing is printed.
Post-Condition: Every state name in the dynamic array is printed.
Description: Prints all the fields of all the population records stored in pop_DB to the screen.
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	//prints the entire dynamic array using a for loop up to count, being the max
	cout << "\n\tState:\t\t    Population:\n";
	for (int i = 0; i < count; i++)
	{
		//magic formula
		cout.setf(ios::fixed);
		cout.precision(0);
		//prints and makes it look nice
		cout << setw(25) << pop_DB[i].state_name << "\t" << ' ' << pop_DB[i].population << endl;
	}
}


/******************************************************************************************************************************************************
Name: Print Range Function
Pre-Condition: Min and max must be initialized and pop_DB must be initialized with variables.
Post-Condition: Displays everything between min and max.
Description: prints all the fields of all the population records stored in pop_DB with a population between min and max to the screen
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	//Loops through pop_DB and prints based on condition
	for (int i = 0; i < count; i++)
	{
		if ((pop_DB[i].population >= (double)min) && (pop_DB[i].population <= (double)max))
		{
			cout << setw(25) << pop_DB[i].state_name << "\t" << ' ' << pop_DB[i].population << endl;
		}
	}
}


/******************************************************************************************************************************************************
Name: State Count Function
Pre-Condition: Min and max must be initialized and pop_DB must be initialized with variables.
Post-Condition: Displays everything between min and max.
Description: returns the total number of states with a population between min and max, inclusive.
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	//counter for the number of states
	int counter = 0;
	//Loops through pop_DB and prints based on condition
	for (int i = 0; i < count; i++)
	{
		if ((pop_DB[i].population >= (double)min) && (pop_DB[i].population <= (double)max))
		{
			counter++;
		}
	}
	return counter;
}

/******************************************************************************************************************************************************
Name: Sort Function
Pre-Condition: pop_DB must be initialized and contain variables
Post-Condition: everything in pop_DB will be sorted either alphabetically or numerically.
Description: sorts the array pop_DB in alphabetical order based on state_name field using insertion sort algorithm
******************************************************************************************************************************************************/
void state_class::Sort()
{
	string choice = "a";
	//Asks the user if they want to sort by state or population
	std::cout << "How would you like to sort: State or Population (s/p)? : ";
	cin >> choice;
	//To prevent memory error
	//Creates temporary record
	population_record temp;
	bool choicetaken = false;
	//State Choice
	while (choicetaken == false)
	{
		if (choice == "s")
		{
			//Loops through array, finding and swapping by alphabetical order.
			for (int i = 0; i < count; i++)
			{
				for (int j = i + 1; j < count; j++)
				{
					if (pop_DB[i].state_name > pop_DB[j].state_name)
					{
						temp = pop_DB[i];
						pop_DB[i] = pop_DB[j];
						pop_DB[j] = temp;
					}
				}
			}
			choicetaken = true;
		}
	//Population Choice
		else if (choice == "p")
		{
			//Loops through array, finding and swapping by least to most population.
			for (int i = 0; i < count; i++)
			{
				for (int j = i + 1; j < count; j++)
				{
					if (pop_DB[i].population > pop_DB[j].population)
					{
						temp = pop_DB[i];
						pop_DB[i] = pop_DB[j];
						pop_DB[j] = temp;
					}
				}
			}
			choicetaken = true;
		}
		else
		{
			cout << "Thats not a choice. Please try again. State or Population (s/p)? ";
			cin >> choice;
		}
	}
}
