#ifndef H_RENTEDDVDLIST
#define H_RENTEDDVDLIST

#include "unorderedLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class RentedDvdList : public unorderedLinkedList<string>
{
public:
	void insertDvd(string dvdTitle);
	void deleteDvD(string dvdTitle);
	void printDvDList();
};

void RentedDvdList::insertDvd(string title)
{
	nodeType<string> *newNode = new nodeType<string>;
	newNode->info = title;
	newNode->link = NULL;

	nodeType<string> *current;

	if (first == NULL)
	{	// Case where there is no list
		first = newNode;
	}
	else if (first->link == NULL)
	{	// Case where there is only one element
		first->link = newNode;
		return;
	}
	else
	{	// Case for multiple elements
		current = first;

		while (current->link != NULL)
		{
			current = current->link;
		}

		current->link = newNode;
	}
}

void RentedDvdList::deleteDvD(string title)
{
	nodeType<string> *current;
	nodeType<string> *previousNode;
	
	current = first;
	
	if (current->info == title)
	{
		first = first->link;
		delete current;
	}
	else
	{
		while (current != NULL)
		{
			previousNode = current;
			current = current->link;

			if (current->info == title)
			{
				previousNode->link = current->link;
				delete current;
			}
		}

		cout << "Title not found" << endl;
	}
}

void RentedDvdList::printDvDList()
{
	nodeType<string> *current = new nodeType<string>;

	current = first;

	if (first == NULL)
		cout << "This account have not rented any DVD." << endl;
	else
	{
		cout << "Currently checked out: " << endl;
		while (current != NULL)
		{
			cout << current->info << endl;
			current = current->link;			
		}
		cout << endl;
	}
}
#endif