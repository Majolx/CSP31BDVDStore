#include <iostream>
#include <fstream>
#include <string>
#include "videoType.h" 
#include "videoListType.h"
#include "CustomerBTreeType.h"

using namespace std; 

void createVideoList(ifstream& infile, 
                     videoListType& videoList);
void displayMenu();

int main()
{
    videoListType videoList;
    int choice;
    char ch;
    string title;
	string accountNum;
	string firstName = "", lastName = "", accNum = "";
	CustomerType newPerson;
	CustomerBTreeType customer;
    
	ifstream infile;

           //open the input file
    infile.open("videoDat.txt");
    if (!infile)
    {
        cout << "The input file does not exist. "
             << "The program terminates!!!" << endl;
        return 1;
    }

        //create the video list
    createVideoList(infile, videoList);
    infile.close();
	
	//pointer to videoList
	//customer.setVideoList(videoList);

        //show the menu
    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;    //get the request
    cin.get(ch);
    cout << endl;

        //process the requests
    while (choice != 9)
    {
        switch (choice)
        {
        case 1: 
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

        case 2: 
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

        case 3: 
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

        case 4: 
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

        case 5: 
            videoList.videoPrintTitle();
            break;

        case 6: 
            videoList.print();
            break;

		case 7:
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

		case 8:
			customer.printCustomerInfo();
			cout << endl;
			break;

		case 9:
			cout << "Enter account number: ";
			cin >> accountNum;
			cout << "Enter title: ";
			cin >> title;

			customer.rentDvd(accountNum, title);
			break;

        default: 
            cout << "Invalid selection." << endl;
        }//end switch

        displayMenu();     //display menu

        cout << "Enter your choice: ";
        cin >> choice;     //get the next request
        cin.get(ch);
        cout << endl;

    }//end while

    return 0;
}

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

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
         << "particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is " 
         << "in stock." << endl;
    cout << "5: To print only the titles of all the videos."
         << endl;
    cout << "6: To print a list of all the videos." << endl;
	cout << "7: Add an account" << endl;
	cout << "8: Print account(s)" << endl;
    cout << "9: To exit" << endl
		;
} //end displayMenu
