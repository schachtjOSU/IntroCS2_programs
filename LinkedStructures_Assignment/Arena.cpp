/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/17/2015
** Description: This is the implementation file for the arena
**    universe.  This contains essentially a way of managing
**    the Player lists, Placement list, and somewhat the
**    rest of the game.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Character.hpp"
#include "Arena.hpp"

using namespace std;

/*****************************************************************
** Description: Default Constructor for Lineup
** Parameters: 1 integer for capacity
******************************************************************/
Lineup::Lineup(int cap)
{
	playArr = new Character[cap];
	playSize = cap;
	playFront = -1;
	playRear = -1;
	playCharacters = 0;
	bluePop = 0;
}

/*****************************************************************
** Description: Destructor to deallocate memory used by the list
** Parameters: None
******************************************************************/
Lineup::~Lineup()
{
	delete[] playArr;
	playArr = 0;
}

/*****************************************************************
** Description: Add Character to the queue
** Parameters: 1 Character object
******************************************************************/
void Lineup::addChar(Character fighter)
{
	// Calculate the rear positon
	playRear = (playRear + 1) % playSize;

	// Insert new Character
	playArr[playRear] = fighter;
	playCharacters++;
}

/*****************************************************************
** Description: Get the Character at the front
** Parameters: None
******************************************************************/
Character Lineup::getChara()
{
	// Set variables
	Character fighter;

	// Get the fighter in the front
	fighter = playArr[(playFront + 1) % playSize];

	return fighter;
}

/*****************************************************************
** Description: Remove the Character
** Parameters: None
******************************************************************/
void Lineup::removeChar()
{
	if (isEmpty())
	{
		cout << "\n\nError:  This queue is empty!" << endl << endl;
	}
	else
	{
		playFront = (playFront + 1) % playSize;
		playCharacters--;
	}
}

/*****************************************************************
** Description: Returns if the queue is empty
** Parameters: None
******************************************************************/
bool Lineup::isEmpty() const
{
	// If there are fighters
	if (playCharacters > 0)
		return false;
	else
		return true;
}

/*****************************************************************
** Description: Add to the Blue Man population
** Parameters: 1 integer 
******************************************************************/
void Lineup::setBlue(int blue)
{
	bluePop += blue;
}

/*****************************************************************
** Description: Return the Blue Man population
** Parameters: None
******************************************************************/
int Lineup::getBlue()
{
	return bluePop;
}

/*****************************************************************
** Description: Default Constructor for Place
** Parameters: 1 integer for capacity
******************************************************************/
Place::Place(int cap)
{
	this->capacity = cap * 2;
	placeArr = new Character[capacity];
	top = 0;
}

/*****************************************************************
** Description: Deconstructor for Place
** Parameters: None
******************************************************************/
Place::~Place()
{
	delete[] placeArr;
	placeArr = 0;
}

/*****************************************************************
** Description: Add fighter to placement stack
** Parameters: 1 Character
******************************************************************/
void Place::push(Character fighter)
{
	if (top == capacity)
	{
		cout << "We've hit capacity!  Nothing more to add!" << endl;
		return;
	}
	else
	{
		placeArr[top] = fighter;
		if (top != (capacity - 1))
			top++;
	}
}

/*****************************************************************
** Description: Return the Character that is at the top
** Parameters: None
******************************************************************/
Character Place::peek()
{
	// Set variable
	Character fighter;

	// Get the value from the top of the stack
	fighter = placeArr[top];

	return fighter;
}

/*****************************************************************
** Description: Default Constructor for Lineup
** Parameters: 1 integer for capacity
******************************************************************/
void Place::pop()
{
	if (isEmpty())
	{
		cout << "Error: Nothing left to take out of the stack!" << endl << endl;
	}
	else
		top--;
}

/*****************************************************************
** Description: Determine if the placement stack is empty
** Parameters: None
******************************************************************/
bool Place::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}