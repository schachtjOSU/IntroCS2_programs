/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/17/2015
** Description: This is the implementation file for the arena
**    universe.  This contains essentially a hiearchy of
**    classes with the bottom heirarchy containing classes
**    of characters.  Implementation of functions are
**    addressed in this file.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>		// Header file used for rand
#include "Character.hpp"

using namespace std;

/*****************************************************************
** Description: Default Constructor for Character
** Parameters: None
******************************************************************/
Character::Character()
{
	this->name = "";
	this->type = "";
	this->isAlive = false;
	this->achillesCut = false;
	this->attackDice = 0;
	this->attackSides = 0;
	this->defenseDice = 0;
	this->defenseSides = 0;
	this->armor = 0;
	this->strength = 0;
}

/***********************************************************
**  Description:  Get method for name
**  Parameters: None
************************************************************/
string Character::getCharName()
{
	return this->name;
}

/***********************************************************
**  Description:  Get method for type
**  Parameters: None
************************************************************/
string Character::getType()
{
	return this->type;
}

/***********************************************************
**  Description:  Get method for isAlive
**  Parameters: None
************************************************************/
bool Character::getAlive()
{
	return this->isAlive;
}

/***********************************************************
**  Description:  Get method for achillesCut
**  Parameters: None
************************************************************/
bool Character::getAchillesCut()
{
	return this->achillesCut;
}

/***********************************************************
**  Description:  Get method for attackDice
**  Parameters: None
************************************************************/
int Character::getAttackDice()
{
	return this->attackDice;
}

/***********************************************************
**  Description:  Get method for attackSides
**  Parameters: None
************************************************************/
int Character::getAttackSides()
{
	return this->attackSides;
}

/***********************************************************
**  Description:  Get method for defenseDice
**  Parameters: None
************************************************************/
int Character::getDefenseDice()
{
	return this->defenseDice;
}

/***********************************************************
**  Description:  Get method for defenseSides
**  Parameters: None
************************************************************/
int Character::getDefenseSides()
{
	return this->defenseSides;
}

/***********************************************************
**  Description:  Get method for armor
**  Parameters: None
************************************************************/
int Character::getArmor()
{
	return this->armor;
}

/***********************************************************
**  Description:  Get method for strength
**  Parameters: None
************************************************************/
int Character::getStrength()
{
	return this->strength;
}

/***********************************************************
**  Description:  Set method for Strength
**  Parameters: 1 integer
************************************************************/
void Character::setStrength(int st)
{
	strength = st;
}

/***********************************************************
**  Description:  Set method for isAlive
**  Parameters: 1 bool
************************************************************/
void Character::setAlive(bool alive)
{
	isAlive = alive;
}

/***********************************************************
**  Description:  Set method for AchillesCut
**  Parameters: 1 integer
************************************************************/
void Character::setAchillesCut(bool achillesState)
{
	achillesCut = achillesState;
}

/***********************************************************
**  Description:  Roll random numbers for dice, return total roll
**  Parameters: 1 integer
************************************************************/
int Character::rollDice(int dice, int sides)
{
	int totalRoll = 0,		// Total value count of all dice
		roll;			// Count of die
	const int MINFACES = 1;	// Minimum number of faces on die

	for (int i = 1; i <= dice; i++)
	{
		roll = rand() % (sides - MINFACES + 1) + MINFACES;
		totalRoll += roll;
	}
	//cout << "\n\nTotal value of roll is: " << totalRoll << "\n";
	return totalRoll;
}

/*****************************************************************
** Description: Create the Barbarian object
** Parameters: 1 string
******************************************************************/
Barbarian::Barbarian(string n)
{
	this->name = n;
	this->type = "Barbarian";
	this->isAlive = true;
	this->achillesCut = false;
	this->attackDice = 2;
	this->attackSides = 6;
	this->defenseDice = 2;
	this->defenseSides = 6;
	this->armor = 0;
	this->strength = 12;
}


int Character::attack(int die, int sides)
{
	// Set variables
	int roll;				// Roll

	// Roll the dice
	roll = rollDice(die, sides);

	// Return final total
	return roll;
}

int Character::defense(int die, int sides, int armor)
{
	// Set variables
	int roll;

	// Roll the dice
	roll = rollDice(die, sides);

	// Add any armor
	roll += armor;

	// Return total
	return roll;
}

/*****************************************************************
** Description: Barbarian attacks
** Parameters: none
******************************************************************/
int Barbarian::attack(int die, int sides)
{
	// Set variables
	int roll;				// Roll

	// Roll the dice
	roll = rollDice(die, sides);

	// Return final total
	return roll;
}

/*****************************************************************
** Description: Barbarian defense
** Parameters: none
******************************************************************/
int Barbarian::defense(int die, int sides, int armor)
{
	// Set variables
	int roll;

	// Roll the dice
	roll = rollDice(die, sides);

	// Add any armor
	roll += armor;

	// Return total
	return roll;
}

/*****************************************************************
** Description: Create the Reptile object
** Parameters: 1 string
******************************************************************/
Reptile::Reptile(string n)
{
	this->name = n;
	this->type = "Reptile";
	this->isAlive = true;
	this->achillesCut = false;
	this->attackDice = 3;
	this->attackSides = 6;
	this->defenseDice = 1;
	this->defenseSides = 6;
	this->armor = 7;
	this->strength = 18;
}

/*****************************************************************
** Description: Reptile attacks
** Parameters: none
******************************************************************/
int Reptile::attack(int die, int sides)
{
	// Set variables
	int roll;				// Roll

	// Roll the dice
	roll = rollDice(die, sides);

	// Return final total
	return roll;
}

/*****************************************************************
** Description: Reptile defense
** Parameters: none
******************************************************************/
int Reptile::defense(int die, int sides, int armor)
{
	// Set variables
	int roll;

	// Roll the dice
	roll = rollDice(die, sides);

	// Add any armor
	roll += armor;

	// Return total
	return roll;
}

/*****************************************************************
** Description: Create the Goblin object
** Parameters: 1 string
******************************************************************/
Goblin::Goblin(string n)
{
	this->name = n;
	this->type = "Goblin";
	this->isAlive = true;
	this->achillesCut = false;
	this->attackDice = 2;
	this->attackSides = 6;
	this->defenseDice = 1;
	this->defenseSides = 6;
	this->armor = 3;
	this->strength = 8;
}

/*****************************************************************
** Description: Goblin attacks
** Parameters: none
******************************************************************/
int Goblin::attack(int die, int sides)
{
	// Set variables
	int roll;				// Roll

	// Roll the dice
	roll = rollDice(die, sides);

	// Return final total
	return roll;
}

/*****************************************************************
** Description: Goblin defense
** Parameters: none
******************************************************************/
int Goblin::defense(int die, int sides, int armor)
{
	// Set variables
	int roll;

	// Roll the dice
	roll = rollDice(die, sides);

	// Add any armor
	roll += armor;

	// Return total
	return roll;
}

/*****************************************************************
** Description: Create the Blue MEN object
** Parameters: 1 string
******************************************************************/
Blue::Blue(string n)
{
	this->name = n;
	this->type = "Blue Men";
	this->isAlive = true;
	this->achillesCut = false;
	this->attackDice = 2;
	this->attackSides = 10;
	this->defenseDice = 3;
	this->defenseSides = 6;
	this->armor = 3;
	this->strength = 12;
}

/*****************************************************************
** Description: Blue Men attacks
** Parameters: none
******************************************************************/
int Blue::attack(int die, int sides)
{
	// Set variables
	int roll;				// Roll

	// Roll the dice
	roll = rollDice(die, sides);

	// Return final total
	return roll;
}

/*****************************************************************
** Description: Goblin defense
** Parameters: none
******************************************************************/
int Blue::defense(int die, int sides, int armor)
{
	// Set variables
	int roll;

	// Roll the dice
	roll = rollDice(die, sides);

	// Add any armor
	roll += armor;

	// Return total
	return roll;
}

/*****************************************************************
** Description: Create the Shadow object
** Parameters: 1 string
******************************************************************/
Shadow::Shadow(string n)
{
	this->name = n;
	this->type = "Shadow";
	this->isAlive = true;
	this->achillesCut = false;
	this->attackDice = 2;
	this->attackSides = 10;
	this->defenseDice = 1;
	this->defenseSides = 6;
	this->armor = 0;
	this->strength = 12;
}

/*****************************************************************
** Description: Shadow attacks
** Parameters: none
******************************************************************/
int Shadow::attack(int die, int sides)
{
	// Set variables
	int roll;				// Roll

	// Roll the dice
	roll = rollDice(die, sides);

	// Return final total
	return roll;
}

/*****************************************************************
** Description: Shadow defense
** Parameters: none
******************************************************************/
int Shadow::defense(int die, int sides, int armor)
{
	// Set variables
	int roll;

	// Roll the dice
	roll = rollDice(die, sides);

	// Add any armor
	roll += armor;

	// Return total
	return roll;
}