#ifndef CHARACTER_HPP
#define CHARACTER_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/07/2015
** Description: This is the header file for the arena 
**    universe.  This contains essentially a hiearchy of 
**    classes with the bottom heirarchy containing classes 
**    of characters.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Base.hpp"
#include "Character.hpp"

using namespace std;

/*****************************************************************
** Description: Parent Character Class
******************************************************************/
class Character
{
public:
	Character();
	void addChar();
	void removeChar();
	void displayChar();
	void fight();
	void setBlue(int);

protected:
	vector <Base> characters;
	Base * baseAtt;
	Base * baseDef;
	int bluePop;
};

#endif