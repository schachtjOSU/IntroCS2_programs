/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/08/2015
** Description: This is the main file for the arena
**    universe.  This contains essentially the main 
**    function for the program and any functions that are 
**    often repetitive.
***********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Character.hpp"
#include "Base.hpp"

using namespace std;

// Main function
int main()
{
	// Set variables
	bool exit = false;
	int menuSelect;
	Character character;

	// Welcome the user to the program
	cout << "** Assignment 3 **" << endl;
	cout << "Welcome Player to the Battle Arena!" << endl << endl;

	// Start a loop with menu option until the user selects to exit the loop
	do
	{
		// Drop the menu here
		cout << "Arena Menu" << endl;
		cout << "1) Add a Character;" << endl;
		cout << "2) Remove a Character;" << endl;
		cout << "3) Stage a fight between Characters;" << endl;
		cout << "4) List all Characters;" << endl;
		cout << "5) Quit the program" << endl;
		
		// User selects menu option here
		cout << "Please make your numbered selection here: ";
		cin >> menuSelect;

		// Switch/Case with user's option
		switch (menuSelect)
		{
		case 1:
		{
			character.addChar();
			break;
		}
		case 2:
		{
			character.removeChar();
			break;
		}
		case 3:
		{
			character.fight();
			break;
		}
		case 4:
		{
			character.displayChar();
			break;
		}
		case 5:
		{
			cout << "Now exiting the program." << endl;
			exit = true;
			break;
		}
		default:
		{
			cout << "Sorry, this program does not understand your entry.  Please try again." << endl;
			break;
		}
		}

	} while (!exit);


	// Exit the program
	return 0;
}