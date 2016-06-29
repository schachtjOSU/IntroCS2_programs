#ifndef CONWAYGAMELIFE_HPP
#define CONWAYGAMELIFE_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/11/2015
** Description: This program will be executing a zero-player
**     game called Conway's Game of Life.  This program will
**     ask the user for a configuration and the game will
**     be played.
***********************************************************/
#include <iostream>

using namespace std;

class ConwayGameLife
{
private:
	// Create the world
	char world[40][20];

public:
	ConwayGameLife();		// Default Constructor
	void createOscillator(int, int);	// Start the oscillator
	void createGlider(int, int);		// Start the Glider
	void createCannon();				// Start the Cannon
	void gameRules();		// Game rules for each cell
	void print();			// Print the world
};
#endif