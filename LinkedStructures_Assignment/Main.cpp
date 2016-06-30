/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 05/17/2015
** Description: This is the main implemenation file for the 
**    Assignment 4 program. This will essentially get the 
**    players set up with their lists, run a loop to start 
**    the fighting between fighters, and then display the 
**    results.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Character.hpp"
#include "Arena.hpp"

using namespace std;

/*****************************************************************
** Description: Start a fight between two characters
** Parameters: None
******************************************************************/
void fight(Lineup &player1, Lineup &player2, Place &loserPile, int &play1Points, int &play2Points)
{
	// Set variables
	Character fighter1,			// Players fighters
		fighter2;
	string name1,				// Character names
		name2,
		type1,					// Character class
		type2, 
		empty;
	bool alive1,				// Character alive status
		alive2,
		achilles1,				// Character's achilles is cut status
		achilles2;
	int attackDie1,				// Character's ability to attack number of DIE
		attackDie2,
		attackSide1,			// Character's ability to attack number of SIDES
		attackSide2,
		defDie1,				// Character's ability to defend number of DIE
		defDie2,
		defSide1,				// Characteer's ability to defend number of SIDES
		defSide2,
		armor1,					// Character's armor rating
		armor2,
		strength1,				// Character's strength
		strength2,
		bluePop1,				// Blue Man population
		bluePop2,
		attackRollTotal,		// Attack and Defend rolls
		defendRollTotal,
		origStrength1,
		origStrength2,
		totalCombat;			// Total after attack and defend are subtracted
	int	shadowRoll;				// For the coin flip of the Shadow defense

	// Get Character from player 1's list and assign stats
	fighter1 = player1.getChara();
	fighter2 = player2.getChara();

	// Get blue man population
	bluePop1 = player1.getBlue();
	bluePop2 = player2.getBlue();

	// Get 1st fighter's attributes
	name1 = fighter1.getCharName();
	type1 = fighter1.getType();
	alive1 = fighter1.getAlive();
	achilles1 = fighter1.getAchillesCut();
	attackDie1 = fighter1.getAttackDice();
	attackSide1 = fighter1.getAttackDice();
	defDie1 = fighter1.getDefenseDice();
	defSide1 = fighter1.getDefenseSides();
	armor1 = fighter1.getArmor();
	strength1 = fighter1.getStrength();
	origStrength1 = strength1;

	// Get 2nd fighter's attributes
	name2 = fighter2.getCharName();
	type2 = fighter2.getType();
	alive2 = fighter2.getAlive();
	achilles2 = fighter2.getAchillesCut();
	attackDie2 = fighter2.getAttackDice();
	attackSide2 = fighter2.getAttackDice();
	defDie2 = fighter2.getDefenseDice();
	defSide2 = fighter2.getDefenseSides();
	armor2 = fighter2.getArmor();
	strength2 = fighter2.getStrength();
	origStrength2 = strength2;

	// Who's fighting?
	cout << "\n\nIt's " << name1 << " a " << type1 << " VS " << name2 << " a " << type2 << endl;
	cout << "Press Enter to continue..." << endl;
	getline(cin, empty);

	while (alive1 && alive2)
	{
		// Player 1 attacks player 2
		attackRollTotal = fighter1.attack(attackDie1, attackSide1);
		defendRollTotal = fighter2.defense(defDie2, defSide2, armor2);

		// Handle Goblin getting 12 roll
		if ((attackRollTotal == 12) && (type1 == "Goblin") && (type2 != "Goblin"))
		{
			achilles2 = true;
			fighter2.setAchillesCut(achilles2);
		}
		// Handle Shadow getting to be able to escape with defense
		if (type2 == "Shadow")
		{
			int die = 1,
				flip = 2;
			shadowRoll = fighter2.attack(die, flip);
			// Just picking a number of 1 or 2, as it's a coin flip
			if (shadowRoll == 1)
			{
				attackRollTotal = 0;
				//cout << "\n\nYou missed the Shadow...It is somewhere else...." << endl;
			}
		}
		// Calculate results to defender
		// Is the achilles cut?
		if (achilles1)
			attackRollTotal = attackRollTotal / 2;
		if (achilles2)
			defendRollTotal = defendRollTotal / 2;
		// Handle Blue Man not attacking with more than 1 population
		if ((type1 == "Blue Men") && (bluePop1 < 2))
			attackRollTotal = 0;
		totalCombat = attackRollTotal - defendRollTotal;
		// Add player points from total combat
		if (totalCombat < 0)
			play1Points += 0;
		else
			play1Points += totalCombat;
		if (totalCombat > 0)
		{
			strength2 -= totalCombat;
			fighter2.setStrength(strength2);
			if (strength2 < 1)
			{
				alive2 = false;
				fighter2.setAlive(alive2);
				cout << "\n\nThe fighter " << name2 << " has perished!" << endl;
			}
		}

		// Player 2 attacks player 1, if alive
		if (alive2)
		{
			attackRollTotal = fighter2.attack(attackDie2, attackSide2);
			defendRollTotal = fighter1.defense(defDie1, defSide1, armor1);

			// Handle Goblin getting 12 roll
			if ((attackRollTotal == 12) && (type2 == "Goblin") && (type1 != "Goblin"))
			{
				achilles1 = true;
				fighter1.setAchillesCut(achilles1);
			}
			// Handle Shadow getting to be able to escape with defense
			if (type1 == "Shadow")
			{
				int die = 1,
					flip = 2;
				shadowRoll = fighter1.attack(die, flip);
				// Just picking a number of 1 or 2, as it's a coin flip
				if (shadowRoll == 1)
				{
					attackRollTotal = 0;
					//cout << "\n\nYou missed the Shadow...It is somewhere else...." << endl;
				}
			}
			// Calculate results to defender
			// Is the achilles cut?
			if (achilles2)
				attackRollTotal = attackRollTotal / 2;
			if (achilles1)
				defendRollTotal = defendRollTotal / 2;
			// Handle Blue Man not attacking with more than 1 population
			if ((type2 == "Blue Men") && (bluePop2 < 2))
				attackRollTotal = 0;
			totalCombat = attackRollTotal - defendRollTotal;
			// Add player points from total combat
			if (totalCombat < 0)
				play2Points += 0;
			else
				play2Points += totalCombat;
			if (totalCombat > 0)
			{
				strength1 -= totalCombat;
				fighter1.setStrength(strength1);
				if (strength1 < 1)
				{
					alive1 = false;
					fighter1.setAlive(alive2);
					cout << "\n\nThe fighter " << name1 << " has perished!" << endl;
				}
			}
		}
	}

	cout << "Press Enter to continue..." << endl;
	getline(cin, empty);

	// Move the winning to the end of the queue, the other goes to the loser pile
	if (alive1)
	{
		// Set Healing for winner
		strength1 = strength1 * 1.5;
		if (strength1 > origStrength1)
			fighter1.setStrength(origStrength1);
		else
			fighter1.setStrength(strength1);
		player1.removeChar();
		player1.addChar(fighter1);
		loserPile.push(fighter2);
		player2.removeChar();
	}
	else
	{
		// Set Healing for winner
		strength2 = strength2 * 1.5;
		if (strength2 > origStrength2)
			fighter2.setStrength(origStrength2);
		else
			fighter2.setStrength(strength2);
		player2.removeChar();
		player2.addChar(fighter2);
		loserPile.push(fighter1);
		player1.removeChar();
	}

}


/*****************************************************************
** Description: Add a character
** Parameters: The Player's list
******************************************************************/
void addChar(Lineup &list)
{
	// Set variables
	string name;		// name of character
	int userOpt;		// menu option
	string empty;		// Catch outstanding outstream
	int blueNum = 1;

	getline(cin, empty);

	// Ask user for name of the new Character
	cout << "Adding a New Character!" << endl;
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
		//characters.push_back(barb);
		list.addChar(barb);
		cout << name << " is a Barbarian!" << endl << endl;
		break;
	}
	case 2:
	{
		Reptile rept(name);
		list.addChar(rept);
		cout << name << " is a Reptile!" << endl << endl;
		break;
	}
	case 3:
	{
		Goblin gob(name);
		list.addChar(gob);
		cout << name << " is a Goblin!" << endl << endl;
		break;
	}
	case 4:
	{
		Blue blu(name);
		list.addChar(blu);
		cout << name << " is a Blue Man!" << endl << endl;
		list.setBlue(blueNum);
		break;
	}
	case 5:
	{
		Shadow shade(name);
		list.addChar(shade);
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


int main()
{
	// Set variables
	int fightNum;
	Character fighter;	// Fighter for stranded fighters in the queue
	Character loseFighter;  // From the stack of placements
	string nameFighter;
	string empty;
	int player1Total = 0;		// Total Points for player 1
	int player2Total = 0;		// Total Points for player 2

	// Welcome the user to the program
	cout << "This is Assignment 4: Battle Arena 2 with Linked Structures!" << endl << endl;

	// Ask the user how many fighters per each player.
	cout << "Please enter the number of fighters for EACH player: ";
	cin >> fightNum;

	// Create the static structures for players 1 and 2 and placement stack with user input
	Lineup player1(fightNum);
	Lineup player2(fightNum);
	Place loserPile(fightNum);

	// Add fighters for player 1
	for (int i = 0; i < fightNum; i++)
	{
		cout << "\n\nAdding fighters for player 1!" << endl << endl;
		addChar(player1);
	}

	// Add fighters for player 2
	for (int i = 0; i < fightNum; i++)
	{
		cout << "\n\nAdding fighters for player 2!" << endl << endl;
		addChar(player2);
	}

	cout << "Press Enter to continue..." << endl;
	getline(cin, empty);

	// Start the battle arena
	while (!player1.isEmpty() && !player2.isEmpty())
	{
		fight(player1, player2, loserPile, player1Total, player2Total);
	}

	// Place any left over characters into the stack
	if (!player1.isEmpty())
	{
		while (!player1.isEmpty())
		{
			fighter = player1.getChara();
			loserPile.push(fighter);
			player1.removeChar();
		}
	}
	if (!player2.isEmpty())
	{
		while (!player2.isEmpty())
		{
			fighter = player2.getChara();
			loserPile.push(fighter);
			player2.removeChar();
		}
	}

	// Display placement list and total points for each player
	cout << "\n\nPlacement!" << endl;
	int place;
	place = 1;
	while (!loserPile.isEmpty())
	{
		loseFighter = loserPile.peek();
		nameFighter = loseFighter.getCharName();
		cout << "\nIn " << place << " place... " << nameFighter << "!!!!" << endl;
		loserPile.pop();
		place++;
		if (place == 4)
			break;
	}

	cout << "Press Enter to continue..." << endl;
	getline(cin, empty);

	// Display Player Points
	cout << "\n\nPlayer Point Totals!!!" << endl << endl;
	cout << "Player 1 total points is: " << player1Total << endl;
	cout << "Player 2 total points is: " << player2Total << endl << endl;
	cout << "The Winner is... ";
	if (player1Total > player2Total)
		cout << "\n...........PLAYER 1!!!!!!!" << endl << endl;
	else if (player2Total > player1Total)
		cout << "\n...........PLAYER 2!!!!!!!" << endl << endl;
	else
		cout << "\n...............It's a TIE!!!!!!!" << endl << endl;

	// Destroy the structures
	player1.~Lineup();
	player2.~Lineup();
	loserPile.~Place();

	// Exit the program
	cout << "Press Enter to Exit..." << endl;
	getline(cin, empty);
	return 0;
}