#ifndef ARENA_HPP
#define ARENA_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/17/2015
** Description: This is the header file for the arena
**    universe.  This contains essentially a way of managing 
**    the Player lists, Placement list, and somewhat the 
**    rest of the game.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Character.hpp"

using namespace std;

/*****************************************************************
** Description: Parent Lineup Class
******************************************************************/
class Lineup
{
public:
	Lineup(int);				// Constructor
	~Lineup();					// deconstructor
	void addChar(Character);	// Add Characters
	Character getChara();		// Get Characters
	void removeChar();			// Remove Characters
	bool isEmpty() const;		// if array is empty
	void setBlue(int);			// Set the Blue Man population
	int getBlue();

private:
	//Character * baseAtt;
	//Character * baseDef;*/
	int bluePop;				// Blue Man population
	Character *playArr;			// Character array
	int playSize;				// Size of the array
	int playFront;				// Location of front of queue
	int playRear;				// Location of rear of queue
	int playCharacters;			// Number of characters

};

/*****************************************************************
** Description: Place Class or Loser pile
******************************************************************/
class Place
{
public:
	Place(int cap);				// Default constructor
	~Place();					// Deconstructor
	void push(Character fighter);	// Adds fighter to placement
	Character peek();				// Returns the Character on top
	void pop();					// Removes Character on top
	bool isEmpty() const;		// Discovers if placement is empty

private:
	Character *placeArr;		// Place array
	int capacity;
	int top;
};

#endif