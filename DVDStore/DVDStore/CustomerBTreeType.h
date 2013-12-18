/*	This class will create and maintain a list of customer.
	Name: Mathew Larribas
	Date: 12/14/2013
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
	void deleteAccount(string accountNumber);
	bool searchAccount(string accNum);
	void printCustomerInfo();
	void rentDvd(string account, string title);
	void returnDvd(string account, string title);
private:
	videoListType dvdList;
};

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
				current = current->rLink;
		}
		else 
		{
			while (current != NULL)
				current = current->lLink;
		}

		if (current == NULL)
		{
			current = newNode;
		}
	}
}

void CustomerBTreeType::deleteAccount(string accountNumber)
{
	CustomerType account;
	account.setAccountNumber(accountNumber);
	
	if (search(account)) 
		deleteNode(account);
}

bool CustomerBTreeType::searchAccount(string accNum)
{
	CustomerType account;
	account.setAccountNumber(accNum);

	return search(account);
}

void CustomerBTreeType::printCustomerInfo()
{
	if (root == NULL)
		cout << "Empty List." << endl << endl;
	else
		this->inorderTraversal();
}

void CustomerBTreeType::rentDvd(string accountNum, string title)
{
	CustomerType customer;
	customer.setAccountNumber(accountNum);
	getNode(customer);

	customer.rentDVD(title);
}

void CustomerBTreeType::returnDvd(string accountNum, string title)
{
	CustomerType customer;
	customer.setAccountNumber(accountNum);
	getNode(customer);

	customer.returnDVD(title);
}

#endif