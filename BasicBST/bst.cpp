/*
This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the BST ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;


bst::bst()
{
	//sets the input file and dynamic string arrays
	ifstream in;
	root = 0;
	//using project 1's method of separating the string from the number
	string line = "";
	char space = ' ';
	string name;
	string number;
	string nameInsert;
	double numInsert;

	in.open("county_data.txt");
	if (in.fail())
	{
		cout << "File did not open.";
	}
	else
	{
		while (!in.eof())
		{
			getline(in, line);

			for (int i = line.length(); i > 0; i--)
			{
				if (line[i] == ' ')
				{
					space = i;
					break;
				}
			}
			name = line.substr(0, space);

			for (int j = line.length(); j > space; j--)
			{
				number = line[j] + number;
			}
			nameInsert = name;
			numInsert = std::stod(number);
			//Finally, inserts the new county names and populations into the binary tree.
			insert(nameInsert, numInsert);
			name = " ";
			number = " ";
		}
	}
}

bool bst::empty()
{
	return (root == 0);
}

void bst::insert(const string& item, const double& population)
{

	insert(root, item, population);
}

void bst::insert(treenode*& loc_ptr, const string& item, const double& population)
{

	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = item;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->county_name > item)
		insert(loc_ptr->lchild, item, population);
	else if (loc_ptr->county_name < item)
		insert(loc_ptr->rchild, item, population);
	else
		cout << "the item is already in the tree\n";
}



treenode* bst::search_tree(string item)
{
	return search_tree(root, item);
}

treenode* bst::search_tree(treenode* loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
			return loc_ptr;
		else if (loc_ptr->county_name > item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
		
}



void bst::del_name(string item)
{
	del_name(root, item);
}

void bst::del_name(treenode*& loc_ptr, string item)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->county_name < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode* ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}

}

treenode* bst::inorder_succ(treenode* loc_ptr)
{

	treenode* ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}
void bst::county_ranges(const string& min_name, const string& max_name)
{
	county_ranges(root, min_name, max_name);
}
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{
	if (loc_ptr != 0)
	{
		county_ranges(loc_ptr->lchild, min_name, max_name);
		if(loc_ptr->county_name >= min_name && loc_ptr->county_name <= max_name)
			cout << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		county_ranges(loc_ptr->rchild, min_name, max_name);
	}
		
}
void bst::print_tree()
{
	print_tree(root);
}

void bst::print_tree(treenode*& loc_ptr)
{
	cout.setf(ios::fixed);
	cout.precision(0);
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		print_tree(loc_ptr->rchild);
	}
}
void bst::sorted_info()
{
	ofstream out;
	out.open("county_info.txt");
	sorted_info(out, root);
}
void bst::sorted_info(ostream& out, treenode*& loc_ptr)
{
	out.setf(ios::fixed);
	out.precision(0);
	if (loc_ptr != 0)
	{
		sorted_info(out, loc_ptr->lchild);
		out << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		sorted_info(out, loc_ptr->rchild);
	}
}
void bst::empty_tree()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}

bst::~bst()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}

