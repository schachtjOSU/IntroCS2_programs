/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 06/02/2015
** Description: This is the main source file for the Race 
**    Game.  This file will perform the main functions for 
**    the program.
***********************************************************/
class Car;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "car.hpp"
#include "region.hpp"

using namespace std;

/***********************************************************
**  Description: Roll the dice and return the value
**  Parameters: 2 integers
************************************************************/
int rollDice(int dice, int sides)
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

/***********************************************************
**  Description: Plays the danger scenario
**  Parameters: Car
************************************************************/
int dangerScenario(Car &car, int days)
{
	// Set varaibles
	int diceResult;			// Result of the dice roll
	const int DICE = 4;		// Number of dice
	const int SIDES = 6;	// Number of sides
	string empty;			// Stop the instream

	// Roll 4 - 6 sided die, what's the number
	diceResult = rollDice(DICE, SIDES);

	// Switch case for each of the 20 options - some repeat
	switch (diceResult)
	{
	case 4:
	{
		cout << "\n**\n** Road is closed due to Construction!  You've lost 2 days!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		days = days + 2;
		break;
	}
	case 5:
	{
		cout << "\n**\n** Your a good samaritan today and helped an old lady cross the track!"
			<< endl << "** You've earned yourself 100 credits!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		int m = car.getMoney();
		m += 100;
		car.setMoney(m);
		break;
	}
	case 6:
	{
		cout << "\n**\n** You just spotted one of The Baron's henchmen sabotage your engine."
			<< endl << "** If you have a wrench, you won't lose a day..." << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		Store item;
		item = car.displayItems();
		if (item.getObjName() == "Wrench")
			cout << "** You've fixed your auto!" << endl;
		else
		{
			cout << "** You've lost a day" << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 7:
	{
		cout << "\n**\n** No problems on this day!  Keep going!!!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 8:
	{
		cout << "\n**\n** You run into Pirates!!!" << endl;
		cout << "** They take up to 100 credits" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		int m = car.getMoney();
		if (m >= 100)
			car.setMoney(m - 100);
		else
		{
			m = 0;
			car.setMoney(m);
		}
		break;
	}
	case 9:
	{
		cout << "\n**\n** The Baron's henchmen left an oil slick on the entire road."
			<< endl << "** If you have tires or are a large vehicle, you won't lose a day..." << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		Store item;
		item = car.displayItems();
		if ((item.getObjName() == "Traction Tires") || (car.getSize() == Car::large))
			cout << "** You've passed the oil slick!" << endl;
		else
		{
			cout << "** You've lost a day" << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 10:
	{
		cout << "\n**\n** No problems on this day!  Keep going!!!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 11:
	{
		cout << "\n**\n** Your a good samaritan today and helped an old lady cross the track!"
			<< endl << "** You've earned yourself 100 credits!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		int m = car.getMoney();
		m += 100;
		car.setMoney(m);
		break;
	}
	case 12:
	{
		cout << "\n**\n** Region officials forgot to reroute traffic during the rush hour." 
			<< endl << "** Lose a day if you don't have a small car."<< endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		if (car.getSize() == Car::small)
			cout << "** Your vehicle is small. No problems weaving through traffic!" << endl;
		else
		{
			cout << "** Your stuck, with no where to go..." << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 13:
	{
		cout << "\n**\n** No problems on this day!  Keep going!!!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 14:
	{
		cout << "\n**\n** The Baron hosts a tea party with his henchmen!"
			<< endl << "** Use your ninja to defeat the henchmen, " << endl
			<< "** otherwise enjoy the tea and crackers for a day." << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		Store passenger;
		passenger = car.displayPass();
		if (passenger.getObjName() == "Ninja")
			cout << "\n** Your ninja has saved the day!" << endl << endl;
		else
		{
			cout << "\n** Hope you like high tea." << endl << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 15:
	{
		cout << "\n**\n** No problems on this day!  Keep going!!!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 16:
	{
		cout << "\n**\n** Region officials forgot to reroute traffic during the rush hour."
			<< endl << "** Lose a day if you don't have a small car." << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		if (car.getSize() == Car::small)
			cout << "** Your vehicle is small. No problems weaving through traffic!" << endl;
		else
		{
			cout << "** Your stuck, with no where to go..." << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 17:
	{
		cout << "\n**\n** Your a good samaritan today and helped an old lady cross the track!"
			<< endl << "** You've earned yourself 100 credits!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		int m = car.getMoney();
		m += 100;
		car.setMoney(m);
		break;
	}
	case 18:
	{
		cout << "\n**\n** No problems on this day!  Keep going!!!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 19:
	{
		cout << "\n**\n** The Baron's henchmen left an oil slick on the entire road."
			<< endl << "** If you have tires or are a large vehicle, you won't lose a day..." << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		Store item;
		item = car.displayItems();
		if ((item.getObjName() == "Traction Tires") || (car.getSize() == Car::large))
			cout << "** You've passed the oil slick!" << endl;
		else
		{
			cout << "** You've lost a day" << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 20:
	{
		cout << "\n**\n** You run into Pirates!!!" << endl;
		cout << "** They take up to 100 credits" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		int m = car.getMoney();
		if (m >= 100)
			car.setMoney(m - 100);
		else
		{
			m = 0;
			car.setMoney(m);
		}
		break;
	}
	case 21:
	{
		cout << "\n**\n** No problems on this day!  Keep going!!!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 22:
	{
		cout << "\n**\n** You just spotted one of The Baron's henchmen sabotage your engine."
			<< endl << "** If you have a wrench, you won't lose a day..." << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		Store item;
		item = car.displayItems();
		if (item.getObjName() == "Wrench")
			cout << "** You've fixed your auto!" << endl;
		else
		{
			cout << "** You've lost a day" << endl;
			days++;
		}
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		break;
	}
	case 23:
	{
		cout << "\n**\n** Your a good samaritan today and helped an old lady cross the track!"
			<< endl << "** You've earned yourself 100 credits!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		int m = car.getMoney();
		m += 100;
		car.setMoney(m);
		break;
	}
	case 24:
	{
		cout << "\n**\n** Road is closed due to Construction!  You've lost 2 days!" << endl;
		cout << "** Please Press Enter to Continue...";
		getline(cin, empty);
		days = days + 2;
		break;
	}
	default:
		break;
	}

	return days;
}


/***********************************************************
**  Description: Find out if car will go in one turn
**  Parameters: Region and Car
************************************************************/
bool isOneTurn(Car &car, Region &reg)
{
	// Set variables
	bool oneTurn = false;		// Flag for if the car only takes one turn
	Car::specialAbility special;	// Special ability
	Region::typeReg regType;		// Region type

	// Get the special ability and region type
	special = car.getSpecial();
	regType = reg.getType();

	// Does the region match the specific special,  then return true
	if ((special == Car::evadeCave) && (regType == Region::cavern))
		oneTurn = true;
	else if ((special == Car::evadeDesert) && (regType == Region::desert))
		oneTurn = true;
	else if ((special == Car::evadeMtn) && (regType == Region::mountain))
		oneTurn = true;
	else if ((special == Car::evadeSky) && (regType == Region::sky))
		oneTurn = true;
	else if ((special == Car::evadeSwamp) && (regType == Region::swamp))
		oneTurn = true;
	else if ((special == Car::evadeUrban) && (regType == Region::urban))
		oneTurn = true;

	return oneTurn;
}

/***********************************************************
**  Description: Step 3 start the race
**  Parameters: Track and Car
************************************************************/
void theRace(Car &car, vector <Region> &track)
{
	// Set variables
	Store store;		// Store for supplies
	bool firstExit = false;		// bools for exiting the loops when reaching destination
	int move = 0;			// Regions
	int turnMove = 0;		// Turns per Region
	string userAns;			// For going foward or back
	int days = 1;			// Increment number of days
	Region reg;
	string regionName;
	int locPerTurn = car.getSpeed();
	string empty; 
	bool moveBack = false;
	char ans;
	Store item;
	bool oneTurn;			// Special car with one turn
	int BaronTurns = 32;	// Number of Turns it takes the Baron
	int gas;

	// go to the store and get supplies
	store.storeShop(car);
	car.printItemsPass();
	cout << "\n\nPlease Press Enter to Continue...";
	getline(cin, empty);
	cout << endl << endl << endl << endl << endl << "Ready..."
		<< endl << endl << "Set..." << endl << endl << "GooooooOOOOOO!!!!!"
		<< endl;

	// Loop, until the user reaches the Gas Stop
	while (!firstExit)
	{
		bool thirdExit = false;
		reg = track[move];
		regionName = reg.getRegName();

		// Find out if car has special to only take region in 1 turn
		int locPerTurn = car.getSpeed();
		oneTurn = isOneTurn(car, reg);
		if (oneTurn)
			locPerTurn = 1;

		cout << endl << endl << endl << endl << endl << endl << endl;
		cout << "#########################################";
		cout << "\n#### Welcome to " << regionName << " ####" << endl 
			<< "#########################################" << endl;

		cout << "Please Press Enter to Continue...";
		getline(cin, empty);
		cout << endl << endl;

		// Second loop here
		for (int i = 0; i < locPerTurn; i++)
		{
			if (moveBack)
				i = locPerTurn - 1;
			moveBack = false;
			thirdExit = false;

			// if gas runs out, add 3 days to looking for gas
			if ((car.getAGas() - car.getGas()) < 0)
			{
				cout << "\n\nYou ran out of gas!  You spent 3 more days looking to filling up the tank." << endl << endl;
				days += 3;
				car.setAGas(car.getTank());
				cout << "Please Press Enter to Continue...";
				getline(cin, empty);
			}
			
			// Take away gas
			car.setAGas(car.getAGas() - car.getGas());

			// Output turn per location
			cout << "\nTurn " << i << " with total " << locPerTurn << endl << endl;
			cout << "This is day " << days << endl << endl;
			cout << "Please Press Enter to Continue...";
			getline(cin, empty);
			days++;
			
			// Danger Card here
			cout << "\n\n** The Danger Secnario!" << endl << "**";
			days = dangerScenario(car, days);

			// Menu for Quest Card or using items
			//cout << "Quest card?" << endl;
			cout << "\n\n\nYour gas is at " << car.getAGas();
			cout << "\nWould you like to fill gas item (Y/N)? ";
			cin >> ans;
			ans = toupper(ans);
			if (ans == 'Y')
			{
				item = car.displayItems();
				car.setAGas(car.getTank());
			}
			getline(cin, empty);
			// How would user like to move
			while (!thirdExit)
			{
				cout << "\n\nWould you like to move 'f' for forward or 'b' for back:";
				getline(cin, userAns);
				if (userAns == "f")
				{
					thirdExit = true;
				}
				else if (userAns == "b")
				{
					if ((move == 0) && (i == 0))
					{
						cout << "You cannot move back!  Try Again!" << endl;
						continue;
					}
					else
					{
						i--;
						i--;
						thirdExit = true;
					}
				}
				else
					cout << "Error: Please enter 'f' for forward or 'b' for back to continue." << endl;
			}
			if (i < 0)
			{
				moveBack = true;
				break;
			}
		}
		if (moveBack && (move > 0))
			--move;
		else
			move++;

		// Exit for gas station
		if (track[move].getType() == Region::gas)
		{
			//firstExit = true;
			// Go to the store and get supplies
			days++;
			cout << "This is day" << days << endl << endl;
			cout << "Your gas tank is now full!" << endl << endl;
			car.setAGas(car.getTank());
			store.storeShop(car);
			car.printItemsPass();
			move++;
		}
		// Exit for finish line
		if (track[move].getType() == Region::finish)
			firstExit = true;
	}

	// Print results
	cout << "\n\n\n#################################################" << endl;
	cout << "####        Congrats!  Finish Line!!!!       ####" << endl;
	cout << "#################################################" << endl;
	cout << "\n\nIt took you " << days << " days to complete the race!" << endl << endl;
	cout << "It took The Baron " << BaronTurns << " days to complet the race!" << endl << endl;
	if (days > BaronTurns)
		cout << "\nSorry, you lost to The Baron" << endl;
	else if (days < BaronTurns)
		cout << "\nCongratulations!!!  You beat The Baron in the Race!" << endl << endl;
	else
		cout << "\nYou and The Baron tied?!?!" << endl << endl;
}


/***********************************************************
**  Description: Step 2 to starting race - select car
**     Drop menu for user to select the desired car
**  Parameters: Track
************************************************************/
void selectCar(vector <Region> &track)
{
	// Set Variables
	bool userAgree = false;
	string empty;
	int userSelect;
	bool select = false;

	// Loop, until user agrees to choice of car
	while (!userAgree)
	{
		Car raceCar;
		
		// Drop menu
		cout << "\n\n#*#*# Car Menu #*#*#" << endl << endl;
		cout << "1 - Rally Car" << endl;
		cout << "2 - Light Cycle" << endl;
		cout << "3 - Van Dango" << endl;
		cout << "4 - Solar Sailor" << endl;
		cout << "5 - Mountain CAT" << endl;
		cout << "6 - B.E.A.V.O." << endl;
		cout << "7 - Mach 5" << endl;
		cout << "8 - Zepplin de Led" << endl;
		cout << "9 - Lo Ryda" << endl;
		// User Selects the choice
		cout << "Select car by integer for preview: ";
		cin >> userSelect;

		// Switch Case for each car type
		switch (userSelect)
		{
		case 1:
		{
			RallyCar rally;
			raceCar = rally;
			select = true;
			break;
		}
		case 2:
		{
			LightCycle cycle;
			raceCar = cycle;
			select = true;
			break;
		}
		case 3:
		{
			VanDango van;
			raceCar = van;
			select = true;
			break;
		}
		case 4:
		{
			SolarSailor solar;
			raceCar = solar;
			select = true;
			break;
		}
		case 5:
		{
			MtnCAT cat;
			raceCar = cat;
			select = true;
			break;
		}
		case 6:
		{
			Beaver beav;
			raceCar = beav;
			select = true;
			break;
		}
		case 7:
		{
			Mach5 mach;
			raceCar = mach;
			select = true;
			break;
		}
		case 8:
		{
			Airship airship;
			raceCar = airship;
			select = true;
			break;
		}
		case 9:
		{
			LoRyda loryda;
			raceCar = loryda;
			select = true;
			break;
		}
		default:
			cout << "Error: Did not interpret your selection.  Try again." << endl << endl;
			break;
		}
		
		// Display attributes
		if (select)
		{
			select = false;
			//select = displayCar(raceCar);
			select = raceCar.displayCar();
			if (select)
				userAgree = true;
		}
		// Start the race
		theRace(raceCar, track);
	}
}

/***********************************************************
**  Description: Step 1 to starting race - create track
**  Parameters: None
************************************************************/
void createTrack()
{
	// Set variables
	int dieTotal;			// Total from dice roll
	const int DIE = 1;		// Only need 1 die
	const int SIDES = 6;	// Only have 6 kinds of locations
	const int REGHALF = 5;	// First half of track
	const int REGSECHALF = 4;	// Second half of track
	int levelOne = 1;
	int finalLevel = 2;
	int maxNum;
	vector <Region> track;
	const int ARRSIZE = 5;
	string caveArr[ARRSIZE] = { "Mole Town", "Pirate Caves", "The Lava Fields", "Atlantis", "Center of the Earth" };
	string desertArr[ARRSIZE] = {"Fox Oasis", "Flats of Rascals", "Dunes of Plenty", "Arrakis", "Valley of Death"};
	string mtnArr[ARRSIZE] = {"Snow Bunny Summit", "Wolf Traverse", "Twin Peaks", "Yetti Mtn.", "Dragon's Peak"};
	string skyArr[ARRSIZE] = {"Cirrus Traverse", "Cumulus Hwy.", "Road of Rainbow", "Township of Bespin", "Eye of the Storm Pass"};
	string swampArr[ARRSIZE] = {"Soggy Bottoms Bog", "Misquito Marsh", "Water Snakes Slough", "Croc's Quagmire", "El Dorado"};
	string urbArr[ARRSIZE] = {"Bedrock", "Springfield", "Emerald City", "Sunnydale, CA", "Gotham"};
	int caveNum = 0,
		desertNum = 0,
		mtnNum = 0,
		skyNum = 0,
		swampNum = 0,
		urbNum = 0;
	bool regCreated = true;

	// Create track
	// Start with the first 6 regions, then add a gas stop
	for (int i = 0; i < REGHALF; i++)
	{
		// Roll the dice with 1 die and 6 sides
		dieTotal = rollDice(DIE, SIDES);

		// Conditionals fo random die
		if (dieTotal == 1)
		{
			// As long as it's not the last one
			if (caveNum < 4)
			{
				// Create cave and push back to track
				Cavern cave(caveArr[caveNum], levelOne);
				caveNum++;
				track.push_back(cave);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 2)
		{
			// As long as it's not the last one
			if (desertNum < 4)
			{
				// Create desert and push back to track
				Desert desert(desertArr[desertNum], levelOne);
				desertNum++;
				track.push_back(desert);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 3)
		{
			// As long as it's not the last one
			if (mtnNum < 4)
			{
				// Create mountain and push back to track
				Mountain mountain(mtnArr[mtnNum], levelOne);
				mtnNum++;
				track.push_back(mountain);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 4)
		{
			// As long as it's not the last one
			if (skyNum < 4)
			{
				// create sky and push back to track
				Sky sky(skyArr[skyNum], levelOne);
				skyNum++;
				track.push_back(sky);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 5)
		{
			// As long as it's not the last one
			if (swampNum < 4)
			{
				// Create swamp and push back to track
				Swamp swamp(swampArr[swampNum], levelOne);
				swampNum++;
				track.push_back(swamp);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else
		{
			// as long as it's not the last one
			if (urbNum < 4)
			{
				// Create urban and push back to track
				Urban urban(urbArr[urbNum], levelOne);
				urbNum++;
				track.push_back(urban);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
	}

	// Push the gas stop to the next location
	GasStop gasStop;
	track.push_back(gasStop);
	
	// Make the second half regions.
	for (int i = 0; i < REGSECHALF; i++)
	{
		// Roll the dice with 1 die and 6 sides
		dieTotal = rollDice(DIE, SIDES);

		// Conditionals fo random die
		if (dieTotal == 1)
		{
			// As long as it's not the last one
			if (caveNum < 4)
			{
				// Create cave and push back to track
				Cavern cave(caveArr[caveNum], levelOne);
				caveNum++;
				track.push_back(cave);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 2)
		{
			// As long as it's not the last one
			if (desertNum < 4)
			{
				// Create desert and push back to track
				Desert desert(desertArr[desertNum], levelOne);
				desertNum++;
				track.push_back(desert);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 3)
		{
			// As long as it's not the last one
			if (mtnNum < 4)
			{
				// Create mountain and push back to track
				Mountain mountain(mtnArr[mtnNum], levelOne);
				mtnNum++;
				track.push_back(mountain);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 4)
		{
			// As long as it's not the last one
			if (skyNum < 4)
			{
				// create sky and push back to track
				Sky sky(skyArr[skyNum], levelOne);
				skyNum++;
				track.push_back(sky);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else if (dieTotal == 5)
		{
			// As long as it's not the last one
			if (swampNum < 4)
			{
				// Create swamp and push back to track
				Swamp swamp(swampArr[swampNum], levelOne);
				swampNum++;
				track.push_back(swamp);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
		else
		{
			// as long as it's not the last one
			if (urbNum < 4)
			{
				// Create urban and push back to track
				Urban urban(urbArr[urbNum], levelOne);
				urbNum++;
				track.push_back(urban);
			}
			else
			{
				// Redo
				--i;
				continue;
			}
		}
	}

	// Get the Finish line region with level 2 difficulty
	maxNum = max(caveNum, max(desertNum, max(mtnNum, max(skyNum, max(swampNum, urbNum)))));

	// Conditionals
	if (maxNum == caveNum)
	{
		cout << "\n###  Welcome to the Golden Mole Cup!  ###" << endl << endl;
		Cavern cave(caveArr[caveNum], finalLevel);
		track.push_back(cave);
	}
	else if (maxNum == desertNum)
	{
		cout << "\n###  Welcome to the Desert Fox Cup!  ###" << endl << endl;
		Desert desert(desertArr[desertNum], finalLevel);
		track.push_back(desert);
	}
	else if (maxNum == mtnNum)
	{
		cout << "\n###  Welcome to the Mountain Goat Cup!  ###" << endl << endl;
		Mountain mountain(mtnArr[mtnNum], finalLevel);
		track.push_back(mountain);
	}
	else if (maxNum == skyNum)
	{
		cout << "\n###  Welcome to the Blue Falcon Cup!  ###" << endl << endl;
		Sky sky(skyArr[skyNum], finalLevel);
		track.push_back(sky);
	}
	else if (maxNum == swampNum)
	{
		cout << "\n###  Welcome to the Soggy Frog Cup!  ###" << endl << endl;
		Swamp swamp(swampArr[swampNum], finalLevel);
		track.push_back(swamp);
	}
	else
	{
		cout << "\n###  Welcome to the Green Piston Cup!  ###" << endl << endl;
		Urban urban(urbArr[urbNum], finalLevel);
		track.push_back(urban);
	}

	// Push the finish to the next location
	Finish finish;
	track.push_back(finish);

	// print out the track
	int trackSize = track.size();
	Region::typeReg type;
	cout << "The Race Regions are as follows:";
	for (int j = 0; j < trackSize; j++)
	{
		type = track[j].getType();
		if (type == Region::cavern)
			cout << "-C-";
		else if (type == Region::desert)
			cout << "-D-";
		else if (type == Region::gas)
			cout << "-G-";
		else if (type == Region::mountain)
			cout << "-M-";
		else if (type == Region::sky)
			cout << "-Sk-";
		else if (type == Region::swamp)
			cout << "-Sw-";
		else if (type == Region::urban)
			cout << "-U-";
		else
			cout << "-F#";
	}

	cout << "\n\nLegend:" << endl << "C - Cavern" << endl << "D - Desert" << endl << "G - Gas Stop"
		<< endl << "M - Mountain" << endl << "Sk - Sky" << endl << "Sw - Swamp" << endl << "U - Urban" << endl;


	// Step 2 - slect a car
	selectCar(track);
}

int main()
{
	// Set variables
	string empty;			// Just something to pause the output
	bool exit = false;		// For exiting the main loop
	int iterMenu = 0;		// How many times have we looped through the menu
	char letMenu;			// Game menu choice
	
	// Welcome the user!
	cout << "*** The Racing Derby Game ***" << endl;
	cout << "Created by Jeffrey Schachtsick" << endl << endl;
	cout << "Welcome Racer!" << endl << endl;
	cout << "Press Enter to Continue..." << endl;
	getline(cin, empty);

	// Establish the Game Rules!
	cout << "Objective: To reach the finish line as quickly as possible." << endl;
	cout << "Rules: " << endl << " - You will be given the chance to choose your car." << endl;
	cout << " - The car you choose will cary inventory and passengers." << endl;
	cout << " - Each car has different attributes.  Choose wisely." << endl;
	cout << " - Each time spent in a location will reveal a danger situation." << endl;
	cout << " - A danger situation will be something you will need fix" << endl << "     with something in your inventory or pay the penalty." << endl;
	//cout << " - There are also quest situations the player can do to earn additional inventory." << endl;
	cout << " - Be fast!  You need to beat The Baron to the finish line!" << endl;
	cout << "Good Luck!!" << endl << endl;
	cout << "Press Enter to Continue..." << endl;
	getline(cin, empty);

	// Loop through the main program until the user decides to exit
	while (!exit)
	{
		// Display a menu of choices
		cout << "\n### Racing Derby Menu ###" << endl;
		cout << "S - Start a new race." << endl;
		//cout << "V - View Top Scores." << endl;
		cout << "Q - Quit the game." << endl;
		
		// user makes a choice
		cout << "From list above, please enter the character of your choice: ";
		cin >> letMenu;
		letMenu = toupper(letMenu);

		// switch case with user's choice
		switch (letMenu)
		{
		case 'S':
		{
			// Start a new race
			cout << "\nYou're Starting a new race!" << endl << endl;
			// Create track function
			createTrack();
			iterMenu++;
			break;
		}
		/*case 'V':
		{
			// View top scores
			cout << "\n\n ^^^ Top Scores ^^^" << endl;
			break;
		}*/
		case 'Q':
		{
			// Set exit flag to true
			cout << "\nThank you for playing my game!" << endl;
			exit = true;
			break;
		}
		default:
			cout << "\nI'm sorry.  I did not understand your selection.  Please try again." << endl << endl;
			break;
		}
	}


	// Exit the program
	return 0;
}
