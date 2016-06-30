/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/09/2015
** Description: This is the implementation file for the arena
**    universe.  This contains essentially a hiearchy of
**    classes with the bottom heirarchy containing classes
**    of characters.  Implementation of functions are 
**    addressed in this file.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Character.hpp"
#include "Base.hpp"

using namespace std;

/*****************************************************************
** Description: Creation of the Character object
** Parameters: None
******************************************************************/
Character::Character()
{
	vector <Base> characters;
	bluePop = 0;
}

/*****************************************************************
** Description: Add a character to the Character class
** Parameters: None
******************************************************************/
void Character::addChar()
{
	// Set variables
	string name;		// name of character
	int userOpt;		// menu option
	string empty;		// Catch outstanding outstream
	int blue = 1;


	getline(cin, empty);

	// Ask user for name of the new Character
	cout << "\n\nAdding a New Character!" << endl;
	cout << "Enter name of this Champion: ";
	getline(cin, name);

	// Drop menu for which class of character to be added
	cout << "\n\nPlease select the character type below..." << endl;
	cout << "1) Barbarian" << endl;
	cout << "2) Reptile" << endl;
	cout << "3) Goblin" << endl;
	cout << "4) Blue Men" << endl;
	cout << "5) Shadow" << endl;
	cout << "Your selection: ";
	cin >> userOpt;

	// Switch/Case for each option, then add character
	switch (userOpt)
	{
	case 1:
	{
		Barbarian barb(name);
		characters.push_back(barb);
		cout << name << " is a Barbarian!" << endl << endl;
		break;
	}
	case 2:
	{
		Reptile rept(name);
		characters.push_back(rept);
		cout << name << " is a Reptile!" << endl << endl;
		break;
	}
	case 3:
	{
		Goblin gob(name);
		characters.push_back(gob);
		cout << name << " is a Goblin!" << endl << endl;
		break;
	}
	case 4:
	{
		Blue blu(name);
		characters.push_back(blu);
		bluePop += 1;
		cout << name << " is a Blue Man!" << endl << endl;
		break;
	}
	case 5:
	{
		Shadow shade(name);
		characters.push_back(shade);
		cout << name << " is a Shadow!" << endl << endl;
		break;
	}
	default:
	{
		cout << "Sorry, I did not understand your selection.  Please Try to add a character again." << endl << endl;
		break;
	}
	}
}


/*****************************************************************
** Description: Remove a character from the characters list
** Parameters: None
******************************************************************/
void Character::removeChar()
{
	// Set variables
	string empty;					// Catch any outstanding outstream
	string userRem;					// Name of character to remove
	int size;						// Get the current size of the character vector
	string charName;
	bool found = false;

	getline(cin, empty);
	// Get the size of the characters list
	size = characters.size();

	// Ask the user for the name of the character
	cout << "\n\nRemoving a Champion from the Arena!" << endl;
	cout << "Enter the name of the character to be removed: ";
	getline(cin, userRem);

	// Loop through the vector of characters until a match has been found, remove
	for (int i = 0; i < size; i++)
	{
		charName = characters[i].getCharName();
		if (userRem == charName)
		{
			characters.erase(characters.begin() + i);
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "\nCharacter could not be found.  Please display and try again." << endl;
	}
	cout << endl << endl;
}

/*****************************************************************
** Description: List all characters in characters vector
** Parameters: None
******************************************************************/
void Character::displayChar()
{
	// Set variables
	int size;
	string name,					// Get the character attributes here
		type;					
	bool alive,
		achilles;
	int armor,
		strength;
	int totalComp = 0;
	
	// Get the vector size
	size = characters.size();

	// Loop through vector of characters and output to display
	if (size == 0)
	{
		cout << "\n\nYou have no characters in your list.  Please add characters!" << endl;
	}
	else
	{
		// Entry Display
		cout << "\n\nCharacters in the arena: " << endl;

		// Loop through vector
		for (int i = 0; i < size; i++)
		{
			// Get each item data
			name = characters[i].getCharName();
			type = characters[i].getType();
			alive = characters[i].getAlive();
			achilles = characters[i].getAchillesCut();
			armor = characters[i].getArmor();
			strength = characters[i].getStrength();
			totalComp += 1;

			// Display competitors
			cout << "\nName: " << name;
			cout << "\nType: " << type;
			if (alive)
				cout << "\nIs still Alive!";
			else
				cout << "\nOut of Competition!";
			if (achilles)
				cout << "\nThe Achilles has been cut by a Goblin!";
			cout << "\nArmor: " << armor;
			cout << "\nStrength: " << strength;
			cout << endl;
		}
		cout << "\n\nTotal Competitors in the arena are " << totalComp << endl << endl;
	}
}

/*****************************************************************
** Description: Start a fight between two characters
** Parameters: None
******************************************************************/
void Character::fight()
{
	// Set variables
	string empty,
		attackName,
		defendName,
		attackList,
		defenseList,
		typeAttack,
		typeDefense;
	int size;
	bool found = false;
	bool dFound = false;
	int strength,				// Get attributes from character
		attackSide,
		attackDie,
		defendSide,
		defendDie,
		armor,
		attackRollTotal,		// Attack and defend roll totals
		defendRollTotal;
	bool achillesAttack,
		achillesDef,
		aliveAttack,
		aliveDef;
	int totalCombat,
		shadowRoll;				// For the coin flip of the Shadow defense
	
	getline(cin, empty);
	// If there is only one Character
	size = characters.size();
	if (size < 2)
		cout << "\n\nPlease add more characters to continue..." << endl;
	else
	{
		// Get the Attacker name from the user
		cout << "\n\nArena Combat!" << endl;
		cout << "Enter the name of the attacker: ";
		getline(cin, attackName);

		// Search for the attacker in characters, save as the attacking object
		for (int i = 0; i < size; i++)
		{
			attackList = characters[i].getCharName();
			if (attackName == attackList)
			{
				baseAtt = &characters[i];
				attackSide = characters[i].getAttackSides();
				attackDie = characters[i].getAttackDice();
				achillesAttack = characters[i].getAchillesCut();
				aliveAttack = characters[i].getAlive();
				typeAttack = characters[i].getType();
				found = true;
				break;
			}
		}
		if ((typeAttack == "Blue Men") && (bluePop < 2))
		{
			cout << "Not enough Blue Men.  Add more for them to attack!" << endl << endl;
			return;
		}
		if (found && aliveAttack)
		{
			// Get the Defender name from the user
			cout << "\n\nEnter the name of the defender: ";
			getline(cin, defendName);

			// Search for the defender in characters, save as the defending object
			for (int i = 0; i < size; i++)
			{
				defenseList = characters[i].getCharName();
				if (defendName == defenseList)
				{
					baseDef = &characters[i];
					defendDie = characters[i].getDefenseDice();
					defendSide = characters[i].getDefenseSides();
					achillesDef = characters[i].getAchillesCut();
					aliveDef = characters[i].getAlive();
					strength = characters[i].getStrength();
					armor = characters[i].getArmor();
					typeDefense = characters[i].getType();
					dFound = true;
					break;
				}
			}
			if (dFound && aliveDef)
			{
				// Return attack and defense rolls for each character
				attackRollTotal = baseAtt->attack(attackDie, attackSide);
				defendRollTotal = baseDef->defense(defendDie, defendSide, armor);

				// Handle Goblin getting 12 roll
				if ((attackRollTotal == 12) && (typeAttack == "Goblin") && (typeDefense != "Goblin"))
				{
					achillesDef = true;
					baseDef->setAchillesCut(achillesDef);
				}

				// Handle Shadow 50/50 chance of actually being able to be hit
				if (typeDefense == "Shadow")
				{
					int die = 1,
						flip = 2;
					shadowRoll = baseAtt->attack(die, flip);
					// Just picking a number of 1 or 2, as it's a coin flip
					if (shadowRoll == 1)
					{
						attackRollTotal = 0;
						cout << "\n\nYou missed the Shadow...It is somewhere else...." << endl;
					}
				}

				// Calculate results to defender
				// Is the achilles cut?
				if (achillesAttack)
					attackRollTotal = attackRollTotal / 2;
				if (achillesDef)
					defendRollTotal = defendRollTotal / 2;

				totalCombat = attackRollTotal - defendRollTotal;
				if (totalCombat > 0)
				{
					strength = strength - totalCombat;
					baseDef->setStrength(strength);
					if (strength < 1)
					{
						aliveDef = false;
						baseDef->setAlive(aliveDef);
					}
				}

			}
			else
				cout << "\nDefender character could not be found or is not alive.  Please try again." << endl;
		}
		else
			cout << "\nCharacter could not be found or is not alive.  Please try again." << endl;		
	}
}