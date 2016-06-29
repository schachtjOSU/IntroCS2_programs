/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/11/2015
** Description: This program will be executing a zero-player
**     game called Conway's Game of Life.  This program will
**     ask the user for a configuration and the game will
**     be played.
***********************************************************/
#include <iostream>
#include <string>
#include "ConwayGameLife.hpp"

using namespace std;

/***********************************************************
**  Description:  Create Cannon
**  Parameters: Takes a world object
************************************************************/
void createCannon(ConwayGameLife world)
{
	// Set variables
	int generations;	// number of generations
	string entry;	// user Continues when seen enough

	// Ask user how many generations to see pattern
	cout << "\nEnter number of generations to be seen: ";
	cin >> generations;
	// Ask for the x and y coordinate for oscilator starting point

	//cout << "Starting x and y coordinates are: " << xCoord << ", " << yCoord;
	getline(cin, entry);

	// Start Oscillator
	world.createCannon();
	world.print();
	cout << endl << endl;

	// Loop through generations
	for (int i = 0; i < generations; i++)
	{
		world.gameRules();
		world.print();
		cout << "\nGeneration: " << i + 1;
		cout << "\nEnter to continue...";
		getline(cin, entry);
	}
}

/***********************************************************
**  Description:  Create Oscilator
**  Parameters: Takes a world object
************************************************************/
void createOscillator(ConwayGameLife world)
{
	// Set variables
	int generations,	// number of generations
		xCoord,		// x coordinate
		yCoord;		// y coordinate
	string entry;	// user Continues when seen enough

	// Ask user how many generations to see pattern
	cout << "\nEnter number of generations to be seen: ";
	cin >> generations;
	// Ask for the x and y coordinate for oscilator starting point
	cout << "\nEnter the starting x coordinate between 0 and 39: ";
	cin >> xCoord;
	cout << "\nEnter the starting y coordinate between 0 and 19: ";
	cin >> yCoord;

	//cout << "Starting x and y coordinates are: " << xCoord << ", " << yCoord;
	getline(cin, entry);

	// Start Oscillator
	world.createOscillator(xCoord, yCoord);
	world.print();
	cout << endl << endl;

	// Loop through generations
	for (int i = 0; i < generations; i++)
	{
		world.gameRules();
		world.print();
		cout << "\nGeneration: " << i + 1;
		cout << "\nEnter to continue...";
		getline(cin, entry);
	}
}

/***********************************************************
**  Description:  Create Glider
**  Parameters: Takes a world object
************************************************************/
void createGlider(ConwayGameLife world)
{
	// Set variables
	int generations,	// number of generations
		xCoord,		// x coordinate
		yCoord;		// y coordinate
	string entry;	// user Continues when seen enough

	// Ask user how many generations to see pattern
	cout << "\nEnter number of generations to be seen: ";
	cin >> generations;
	// Ask for the x and y coordinate for oscilator starting point
	cout << "\nEnter the starting x coordinate between 0 and 39: ";
	cin >> xCoord;
	cout << "\nEnter the starting y coordinate between 0 and 19: ";
	cin >> yCoord;

	//cout << "Starting x and y coordinates are: " << xCoord << ", " << yCoord;
	getline(cin, entry);

	// Start Glider
	world.createGlider(xCoord, yCoord);
	world.print();
	cout << endl << endl;

	// Loop through generations
	for (int i = 0; i < generations; i++)
	{
		world.gameRules();
		world.print();
		cout << "\nGeneration: " << i + 1;
		cout << "\nEnter to continue...";
		getline(cin, entry);
	}
}

/***********************************************************
**  Description:  Main Function
**  Parameters: None
************************************************************/
int main()
{
	// Set Variables
	bool exiting = false;
	char userAns;

	// Welcome the user to the program
	cout << "Welcome to Conway's Game of Life Program!" << endl << endl;

	// Create the 'World'
	ConwayGameLife world;

	// Do while loop, until the user selects to quit the program
	do
	{
		// Display selection for user to choose from
		cout << "\nGame Menu" << endl;
		cout << "O) See the Oscillator." << endl;
		cout << "G) See the Glider." << endl;
		cout << "C) See the Cannon." << endl;
		cout << "Q) To Quit." << endl;
		cout << "Please make your letter selection: ";
		cin >> userAns;
		userAns = toupper(userAns);

		// switch and cases
		switch (userAns)
		{
		case 'O':
		{
			// Create the Oscillator
			createOscillator(world);
			break;
		}
		case 'G':
		{
			// Create the Glider
			createGlider(world);
			break;
		}
		case 'C':
		{
			// Create the Cannon
			createCannon(world);
			break;
		}
		case 'Q':
		{
			// Quit the Program
			cout << "\nExiting the Program." << endl << endl;
			exiting = true;
			break;
		}
		default:
			cout << "\nError with entry.  Please Try Again." << endl;
			break;
		}

	} while (!exiting);

	// Exit the program
	return 0;
}