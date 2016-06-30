#ifndef CHARACTER_HPP
#define CHARACTER_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/09/2015
** Description: This is the header file for the arena
**    universe.  This contains essentially a hiearchy of
**    classes with the bottom heirarchy containing classes
**    of characters.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*****************************************************************
** Description: Base Class
** Child Class of: Character
******************************************************************/
class Character
{
public:
	Character();
	string getCharName();
	string getType();
	bool getAlive();
	bool getAchillesCut();
	int getAttackDice();
	int getAttackSides();
	int getDefenseDice();
	int getDefenseSides();
	int getArmor();
	int getStrength();
	void setStrength(int);
	void setAlive(bool);
	void setAchillesCut(bool);
	int setAttack(Character *);
	int setDefense(Character *);
	virtual int attack(int, int);
	virtual int defense(int, int, int);
	int rollDice(int, int);

protected:
	string name;
	string type;
	bool isAlive;
	bool achillesCut;
	int attackDice;
	int attackSides;
	int defenseDice;
	int defenseSides;
	int armor;
	int strength;
};


/*****************************************************************
** Description: Barbarian Class
** Child Class of: Character
******************************************************************/
class Barbarian : public Character
{
public:
	Barbarian(string);
	int attack(int, int);
	int defense(int, int, int);
};

/*****************************************************************
** Description: Reptile Class
** Child Class of: Character
******************************************************************/
class Reptile : public Character
{
public:
	Reptile(string);
	int attack(int, int);
	int defense(int, int, int);
};

/*****************************************************************
** Description: Goblin Class
** Child Class of: Character
******************************************************************/
class Goblin : public Character
{
public:
	Goblin(string);
	int attack(int, int);
	int defense(int, int, int);
};

/*****************************************************************
** Description: Blue Men Class
** Child Class of: Character
******************************************************************/
class Blue : public Character
{
public:
	Blue(string);
	int attack(int, int);
	int defense(int, int, int);
};

/*****************************************************************
** Description: Shadow Class
** Child Class of: Character
******************************************************************/
class Shadow : public Character
{
public:
	Shadow(string);
	int attack(int, int);
	int defense(int, int, int);
};

#endif