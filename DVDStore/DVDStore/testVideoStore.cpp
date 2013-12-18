///////////////////////////////////////////////////////////////////////////
 // TestVideoStore.cpp  -  A test file for the DVD Store program.
 //
 // Created by:
 //		Mathew Larribas
 //		Norlan Prudente
 //		Micheal Askew
 //
 //   For Prof. Ma'umalanga's class CSP31B project 4
 //
 ////////////////////////////////////////////////////////////////////////// 
#include <iostream>
#include <fstream>
#include <string>
#include "videoType.h" 
#include "videoListType.h"
#include "CustomerBTreeType.h"

using namespace std; 


// Properties and Values
videoListType videoList;

void createVideoList(ifstream& infile, 
                     videoListType& videoList);
void displayMenu();
void runMenu();

string inventoryFileName = "videoDat.txt";

// ================================================================ /
// Main Loop                                               MAIN     /
// =================================================================/
int main()
{
	// Load the inventory
	ifstream invfile;

	invfile.open(inventoryFileName);
    if (!invfile)
    {
        cout << "The input file does not exist. "
             << "The program terminates!!!" << endl;
        return 1;
    }

	createVideoList(invfile, videoList);

	invfile.close();
    

	// Show the menu
    displayMenu();
	runMenu();

	// Termination
	cout << "\n\nThank you for using your DVD rental assistant!" << endl;
	cout << "Don't forget to clock out!\n\n" << endl;
	system("PAUSE");

    return 0;
}


// ================================================================ /
// Create a new video list                                          /
// =================================================================/
void createVideoList(ifstream& infile, 
                     videoListType& videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int inStock;

    videoType newVideo;

    getline(infile, title);
	
    while (infile)
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);
        newVideo.setVideoInfo(title, star1, star2, producer,
                              director, productionCo, inStock);
        videoList.insertFirst(newVideo);

        getline(infile, title);
    }//end while
}//end createVideoList

// ================================================================ /
// Display the options menu                                         /
// =================================================================/
void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: Check if we carry a video" << endl;
    cout << "2: Rent a video to the customer" << endl;
    cout << "3: Return a video to the customer" << endl;
    cout << "4: Check if a video is in stock" << endl;
    cout << "5: Print Stock, Titles Only" << endl;
    cout << "6: Print Stock" << endl;
	cout << "7: Add/Remove a customer account" << endl;
	cout << "8: Print customer account(s)" << endl;
    cout << "9: Exit this program" << endl;
} //end displayMenu

// ================================================================ /
// User Select in the Options Menu                                  /
// =================================================================/
void runMenu()
{
	int choice;
	char ch;

	CustomerType newPerson;
	CustomerBTreeType customer;
	string accountNum;

	string title;


	// User input the initial selection
	cout << "Make a selection: ";
    cin >> choice;    
    cin.get(ch);
    cout << endl;


	while (choice != 9)
    {
        switch (choice)
        {

        case 1:							// Check if we carry a video
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
                cout << "The store carries " << title 
                     << endl;
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;


        case 2:							// Rent a video to the customer
			cout << "Enter account number: ";
			getline(cin, accountNum);
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                {
					customer.rentDvd(accountNum, title);
                    videoList.videoCheckOut(title);
                    cout << "Enjoy your movie: " 
                         << title << endl;
                }
                else
                    cout << "Currently " << title
                         << " is out of stock." << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;


        case 3:							// Return a video to the customer
			cout << "Enter account number: ";
			getline(cin, accountNum);
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
				customer.returnDvd(accountNum,title);
                videoList.videoCheckIn(title);
                cout << "Thanks for returning "
                     << title << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;


        case 4:							// Check if a video is in stock
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                    cout << title << " is currently in " 
                         << "stock." << endl;
                else
                    cout << title << " is currently out "
                         << "of stock." << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;


        case 5:							// Print Stock, Titles Only
            videoList.videoPrintTitle();
            break;

				
        case 6:							// Print Stock
            videoList.print();
            break;


		case 7:							// Add/Remove a customer account
			string firstName = "", lastName = "", accNum = "";

			int selection;
			cout << "(1) Add or (2) Delete: ";
			cin >> selection;

			if (selection == 1)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter first name: ";
				getline(cin, firstName);
				cout << "Enter last name: ";
				getline(cin, lastName);
				cout << "Enter an account number of your choice: ";
				getline(cin, accNum);
				cout << endl;

				newPerson.setNameAndAccountNumber(firstName, lastName, accNum);
				customer.newCustomer(newPerson);
			}
			else if (selection == 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter account number to delete: ";
				getline(cin, accNum);
				cout << endl;
				customer.deleteAccount(accNum);
			}
			break;


		case 8:							// Print customer account(s)
			customer.printCustomerInfo();
			cout << endl;
			break;


		case 9:							// Exit this program
			cout << "Enter account number: ";
			cin >> accountNum;
			cout << "Enter title: ";
			cin >> title;

			customer.rentDvd(accountNum, title);
			break;


        default:						// Invalid Selection 
            cout << "Invalid selection." << endl;
        }//end switch


		// Redraw the menu
        displayMenu();

		// Make another selection
        cout << "Enter your choice: ";
        cin >> choice;
        cin.get(ch);
        cout << endl;

    }//end while
}