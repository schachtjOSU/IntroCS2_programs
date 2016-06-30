/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/20/2015
** Description: This is the main source file for the 
**    Shopping List program.  This file will have include 
**    the other header and source files, while having only 
**    a main function to have the user choose which option 
**    to do.  Depending on the option, it will delegate to 
**    methods and functions outside of this file.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "List.hpp"
#include "Item.hpp"

//Main function
int main()
{
	// Set variables
	char clubAns;				// User answer to being a Club Member
	bool isClubMem = false;
	string userID;				// Club Member ID
	string empty;				// Catch escape characters
	bool exitProg = false;		// Used to exit loop
	char userSelect;			// User selects option from menu

	// Welcome user to the program
	cout << "Welcome to the Shopping List Program!" << endl << endl;

	// Ask the user if they are a Club member, if so ask for number
	cout << "Are you Club Member (Y/N)? ";
	cin >> clubAns;
	// Send answer to upper case
	clubAns = toupper(clubAns);
	getline(cin, empty);
	// Conditional to set is Club Member
	if (clubAns == 'Y')
	{
		cout << "\nWelcome Valued Customer" << endl;
		cout << "Enter your ID: ";
		getline(cin, userID);
		isClubMem = true;
	}
	
	// Create List object
	List list;

	// Start loop for user choice, do while until exiting the program
	do
	{	
		// Display Menu
		cout << "\n\nShopping Menu" << endl;
		cout << "1) Display Shopping List" << endl;
		cout << "2) Add an Item to List" << endl;
		cout << "3) Remove an Item from List" << endl;
		cout << "4) Quit the program" << endl;
		cout << "Enter the number selection: ";
		
		// User makes selection
		cin >> userSelect;
		
		// Switch case starts here
		switch (userSelect)
		{
		case '1':
		{
			list.displayList();
			break;
		}
		case '2':
		{
			list.addItem(isClubMem);
			break;
		}
		case '3':
		{
			list.removeItem();
			break;
		}
		case '4':
		{
			cout << "\n\nNow exiting the program." << endl;
			exitProg = true;
			break;
		}
		default:
		{
			cout << "\n\nERROR: Your selection " << userSelect << " is not an option.  Please Try Again.";
			break;
		}
		}


	} while (!exitProg);

	// Exit the program
	return 0;
}