#ifndef H_RENTEDDVDLIST
#define H_RENTEDDVDLIST

#include "unorderedLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class RentedDvdList : public unorderedLinkedList<string>
{
private:
	nodeType<string> *first;
public:
	void insertDvd(string dvdTitle);
	void deleteDvD(string dvdTitle);
	void printDvDList();
};

void RentedDvdList::insertDvd(string title)
{
	nodeType<string> *current;

	if (first == NULL)
		first->info = title;
	else
	{
		current = first->link;

		while (current != NULL)
			current = current->link;
		current->info = title;
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
	nodeType<string> *current;

	current = first;

	while (current != NULL)
	{
		cout << current->info << endl;
		current = current->link;
	}
	cout << endl;
}
#endif