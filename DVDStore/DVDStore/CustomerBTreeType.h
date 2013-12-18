/*	This class will create and maintain a list of customer.
	Name: Mathew Larribas
	Date: 12/14/2013

	Modified by:
	Norlan Prudente
	12/18/2013
*/
#ifndef _Customer_B_Tree_Type_h
#define _Customer_B_Tree_Type_h

#include "videoListType.h"
#include "videoType.h"
#include "binaryTree.h"
#include "bSearchTreeType.h"
#include "CustomerType.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class CustomerBTreeType : public bSearchTreeType<CustomerType>
{
public:
	void newCustomer(const CustomerType& newPerson);
	//Add new customer to the binary tree
	//Pre check if node is taken or not
	//Post node is put in the right spot of binary tree
	void deleteAccount(string accountNumber);
	//Delete customer from the binary tree
	//Pre check if node is empty or not
	//Post node deleted
	bool searchAccount(string accNum);
	//Search through the binary tree
	void printCustomerInfo();
	//Print all of the customers name, account number, and the 
	//video they rented that are in the binaru tree
	//Pre customer must be in the list
	//Post customer info is shown
	void rentDvd(string account, string title);
	//Add the dvd rented according to the account number
	//Pre account number must be valid
	//Post Dvd is added to customers rented list
	void returnDvd(string account, string title);
	//return the dvd rented according to the account number
	//Pre account number must be valid
	//Post Dvd is returned
private:
	videoListType dvdList;
};


// ================================================================ /
// Grow a new customer onto the tree
// ================================================================ /
void CustomerBTreeType::newCustomer(const CustomerType& newPerson)
{
	node<CustomerType> *newNode;
	node<CustomerType> *current;

	newNode = new node<CustomerType>;
	newNode->info = newPerson;
	newNode->lLink = NULL;
	newNode->rLink = NULL;
	current = root;


	if (root == NULL)
		root = newNode;
	else
	{
		if (newNode->info.getAccountNumber() > root->info.getAccountNumber())
		{
			while (current != NULL)
			{
				if (current->rLink == NULL)
				{
					current->rLink = newNode;
					return;
				}
				else
					current = current->rLink;
			}
			
		}
		else if (newNode->info.getAccountNumber() < root->info.getAccountNumber())
		{
			while (current != NULL)
			{
				if (current->lLink == NULL)
				{
					current->lLink = newNode;
					return;
				}
				else
					current = current->lLink;
			}
		}
	}
}


// ================================================================ /
// Prunes an account from the tree
// ================================================================ /
void CustomerBTreeType::deleteAccount(string accountNumber)
{
	CustomerType account;
	account.setAccountNumber(accountNumber);
	
	if (search(account)) 
		deleteNode(account);
}


// ================================================================ /
// Searches for an account 
// ================================================================ /
bool CustomerBTreeType::searchAccount(string accNum)
{
	CustomerType account;
	account.setAccountNumber(accNum);

	return search(account);
}


// ================================================================ /
// Prints a list of all customers
// ================================================================ /
void CustomerBTreeType::printCustomerInfo()
{
	if (root == NULL)
		cout << "Empty List." << endl << endl;
	else
		this->inorderTraversal();
}


// ================================================================ /
// Rents a DVD to the customer
// ================================================================ /
void CustomerBTreeType::rentDvd(string accountNum, string title)
{
	node<CustomerType> *current;

	current = root;

	if (current->info.getAccountNumber() > accountNum)
	{
		while (current != NULL && current->info.getAccountNumber() != accountNum)
		{
			if (current->info.getAccountNumber() > accountNum)
			{
				if (current->lLink == NULL)
				{
					cout << "Account not found!\n";
					return;
				}

				current = current->lLink;
			}
		}
	}
	else if (current->info.getAccountNumber() < accountNum)
	{
		while (current != NULL && current->info.getAccountNumber() != accountNum)
		{
			if (current->info.getAccountNumber() > accountNum)
			{
				if (current->lLink == NULL)
				{
					cout << "Account not found!\n";
					return;
				}

				current = current->rLink;
			}
		}
	}

	current->info.rentDVD(title);
}


// ================================================================ /
// Return a DVD out of the customer's inventory
// ================================================================ /
void CustomerBTreeType::returnDvd(string accountNum, string title)
{
	node<CustomerType> *current;

	current = root;

	if (current->info.getAccountNumber() > accountNum)
	{
		while (current != NULL && current->info.getAccountNumber() != accountNum)
		{
			if (current->info.getAccountNumber() > accountNum)
			{
				current = current->lLink;
			}
		}
	}
	else if (current->info.getAccountNumber() < accountNum)
	{
		while (current != NULL && current->info.getAccountNumber() != accountNum)
		{
			if (current->info.getAccountNumber() > accountNum)
			{
				current = current->rLink;
			}
		}
	}

	if (current != NULL)
	{
		current->info.returnDVD(title);
	}
	else
	{
		cout << "You didn't rent that video." << endl;
	}
}

#endif