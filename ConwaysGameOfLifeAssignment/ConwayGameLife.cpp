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
**  Description:  Default Constructor
**  Parameters: None
************************************************************/
ConwayGameLife::ConwayGameLife()
{
	{
		for (int rows = 0; rows < 40; rows++)
		{
			for (int columns = 0; columns < 20; columns++)
			{
				world[rows][columns] = { '.' };
			}
		}
	}
}

/***********************************************************
**  Description: This prints the world to display
**  Parameters: None
************************************************************/
void ConwayGameLife::print()
{
	// Variables
	int rows;
	int columns;
	world[rows][columns];

	cout << endl;
	
	//Loop through each row to print
	for (rows = 0; rows < 40; rows++)
	{
		cout << "\n";
		for (columns = 0; columns < 20; columns++)
		{
			cout << "  " << world[rows][columns];
		}
	}
	cout << endl;
}

/***********************************************************
**  Description: Plays through the game rules
**  Parameters: None
************************************************************/
void ConwayGameLife::gameRules()
{
	// Set variables
	int rows;
	int columns;
	int adjRowBelow,
		adjRowAbove;
	int adjColumnRight,
		adjColumnLeft;
	char status[40][20];

	//Loop through each cell, starting from origin
	for (rows = 0; rows < 40; rows++)
	{
		for (columns = 0; columns < 20; columns++)
		{
			int liveCount = 0;

			// Make sure bottom cell is not greater than 39
			if ((rows + 1) == 40)
				adjRowBelow = 0;
			else
				adjRowBelow = rows + 1;

			// Make sure top cell is not less than 0
			if ((rows - 1) == -1)
				adjRowAbove = 39;
			else
				adjRowAbove = rows - 1;

			// Make sure right cell is not greater than 19
			if ((columns + 1) == 20)
				adjColumnRight = 0;
			else
				adjColumnRight = columns + 1;

			// Make sure left cell is not less than 0
			if ((columns - 1) == -1)
				adjColumnLeft = 19;
			else
				adjColumnLeft = columns - 1;
			// Count any live neighbor cells
			if (world[adjRowAbove][adjColumnLeft] == 'X')
				liveCount++;
			if (world[adjRowAbove][columns] == 'X')
				liveCount++;
			if (world[adjRowAbove][adjColumnRight] == 'X')
				liveCount++;
			if (world[rows][adjColumnLeft] == 'X')
				liveCount++;
			if (world[rows][adjColumnRight] == 'X')
				liveCount++;
			if (world[adjRowBelow][adjColumnLeft] == 'X')
				liveCount++;
			if (world[adjRowBelow][columns] == 'X')
				liveCount++;
			if (world[adjRowBelow][adjColumnRight] == 'X')
				liveCount++;
			
			// Go through each Rule
			// Rule #1, Any cell with less than 2 live neighbors, should be dead
			if (liveCount < 2)
				status[rows][columns] = '.';
			// Rule #2, Any cell with more than 3 live neighbors, should be dead
			else if (liveCount > 3)
				status[rows][columns] = '.';
			// Rule #3, When cell is dead, but has 3 live neighbors, should be alive
			else if ((world[rows][columns] == '.') && (liveCount == 3))
				status[rows][columns] = 'X';
			// Catch all for dead cells, cell remains dead with 2 live neighvors
			else if ((world[rows][columns] == '.') && (liveCount == 2))
				status[rows][columns] = '.';
			else
				status[rows][columns] = 'X';
		}
	}

	// Update the world with the status
	for (rows = 0; rows < 40; rows++)
	{
		for (columns = 0; columns < 20; columns++)
		{
			world[rows][columns] = status[rows][columns];
		}
	}
}

/***********************************************************
**  Description: This initially creates the live cells for oscillator
**  Parameters: 2 integers with x and y coordinates
************************************************************/
void ConwayGameLife::createOscillator(int x, int y)
{
	// Set variables
	int rows;
	int columns;
	world[rows][columns];

	// Make live cell for the middle
	world[x][y] = 'X';

	// Make sure bottom cell is not greater than 39
	if ((x + 1) == 40)
		world[0][y] = 'X';
	else
		world[x + 1][y] = 'X';
	

	// Make sure top cell is not less than 0
	if ((x - 1) == -1)
		world[39][y] = 'X';
	else
		world[x - 1][y] = 'X';
}

/***********************************************************
**  Description: This initially creates the live cells for the glider
**  Parameters: 2 integers with x and y coordinates
************************************************************/
void ConwayGameLife::createGlider(int x, int y)
{
	// Make live cell for the origin
	world[x][y] = 'X';

	// Make live cells for the rest of config
	// Just above origin point
	if ((x - 1) == -1)
		world[39][y] = 'X';
	else
		world[x - 1][y] = 'X';
	// Just to the left
	if ((y - 1) == -1)
		world[x][19] = 'X';
	else
		world[x][y - 1] = 'X';
	// Just 2 to the left
	if ((y - 2) == -2)
		world[x][18] = 'X';
	else if ((y - 2) == -1)
		world[x][19] = 'X';
	else
		world[x][y - 2] = 'X';
	// Just one to the left and 2 up
	if (((x - 2) < 0) && (y >= 0))
		world[(x - 2) + 39][y - 1];
	else if (((x - 2) < 0) && ((y - 1) < 0))
		world[(x - 2) + 39][(y - 1) + 19];
	else if (((x - 2) >= 0) && ((y - 1) < 0))
		world[x - 2][(y - 1) + 19];
	else
		world[x - 2][y - 1] = 'X';
}

/***********************************************************
**  Description: This initially creates the live cells for the cannon
**  Parameters: None
************************************************************/
void ConwayGameLife::createCannon()
{
	// Set up for the Cannon
	//Top Block
	world[2][4] = 'X';
	world[3][4] = 'X';
	world[2][5] = 'X';
	world[3][5] = 'X';

	// Top Catalyst
	world[13][2] = 'X';
	world[13][3] = 'X';
	world[13][7] = 'X';
	world[13][8] = 'X';
	world[15][3] = 'X';
	world[15][7] = 'X';
	world[16][4] = 'X';
	world[16][5] = 'X';
	world[16][6] = 'X';
	world[17][4] = 'X';
	world[17][5] = 'X';
	world[17][6] = 'X';

	// Bottom Catalyst
	world[20][7] = 'X';
	world[21][6] = 'X';
	world[21][7] = 'X';
	world[21][8] = 'X';
	world[22][5] = 'X';
	world[22][9] = 'X';
	world[23][7] = 'X';
	world[24][4] = 'X';
	world[24][10] = 'X';
	world[25][4] = 'X';
	world[25][10] = 'X';
	world[26][5] = 'X';
	world[26][9] = 'X';
	world[27][6] = 'X';
	world[27][7] = 'X';
	world[27][8] = 'X';

	// Bottom Block
	world[36][6] = 'X';
	world[37][6] = 'X';
	world[36][7] = 'X';
	world[37][7] = 'X';
}