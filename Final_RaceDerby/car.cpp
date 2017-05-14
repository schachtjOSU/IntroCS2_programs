/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 06/03/2015
** Description: This is the implementation file for the 
**    parent car class and it's child classes.  There will 
**    mostly be get and set functions for the object.
***********************************************************/
#include <iostream>
#include <string>
#include "car.hpp"

using namespace std;

/***********************************************************
**  Description: Get function for nameCar
**  Parameters: None
************************************************************/
string Car::getName()
{
	return nameCar;
}

/***********************************************************
**  Description: Get function for speedCar
**  Parameters: None
************************************************************/
int Car::getSpeed()
{
	return speedCar;
}

/***********************************************************
**  Description: Get function for totalCargo
**  Parameters: None
************************************************************/
int Car::getTCargo()
{
	return totalCargo;
}

/***********************************************************
**  Description: Get function for availCargo
**  Parameters: None
************************************************************/
int Car::getACargo()
{
	return availCargo;
}

/***********************************************************
**  Description: Get function for money
**  Parameters: None
************************************************************/
int Car::getMoney()
{
	return money;
}

/***********************************************************
**  Description: Get function for gasTank
**  Parameters: None
************************************************************/
int Car::getTank()
{
	return gasTank;
}

/***********************************************************
**  Description: Get function for gasTurn
**  Parameters: None
************************************************************/
int Car::getGas()
{
	return gasTurn;
}

/***********************************************************
**  Description: Get function for availGas
**  Parameters: None
************************************************************/
int Car::getAGas()
{
	return availGas;
}

/***********************************************************
**  Description: Get function for availSeats
**  Parameters: None
************************************************************/
int Car::getAvailSeats()
{
	return availSeats;
}

/***********************************************************
**  Description: Get function for totalSeats
**  Parameters: None
************************************************************/
int Car::getTSeats()
{
	return totalSeats;
}

/***********************************************************
**  Description: Get function for carSize
**  Parameters: None
************************************************************/
Car::size Car::getSize()
{
	return carSize;
}

/***********************************************************
**  Description: Get function for special
**  Parameters: None
************************************************************/
Car::specialAbility Car::getSpecial()
{
	return special;
}

/***********************************************************
**  Description: Set function for nameCar
**  Parameters: 1 string
************************************************************/
void Car::setName(string n)
{
	nameCar = n;
}

/***********************************************************
**  Description: Set function for speedCar
**  Parameters: 1 integer
************************************************************/
void Car::setSpeed(int speed)
{
	speedCar = speed;
}

/***********************************************************
**  Description: Set function for totalCargo
**  Parameters: 1 integer
************************************************************/
void Car::setTCargo(int cargo)
{
	totalCargo = cargo;
}

/***********************************************************
**  Description: Set function for availCargo
**  Parameters: 1 integer
************************************************************/
void Car::setACargo(int cargo)
{
	availCargo = cargo;
}

/***********************************************************
**  Description: Set function for money
**  Parameters: 1 integer
************************************************************/
void Car::setMoney(int m)
{
	money = m;
}

/***********************************************************
**  Description: Set function for gasTank
**  Parameters: 1 integer
************************************************************/
void Car::setTank(int tank)
{
	gasTank = tank;
}

/***********************************************************
**  Description: Set function for gasTurn
**  Parameters: 1 integer
************************************************************/
void Car::setGas(int gas)
{
	gasTurn = gas;
}

/***********************************************************
**  Description: Set function for availGas
**  Parameters: 1 integer
************************************************************/
void Car::setAGas(int gas)
{
	availGas = gas;
}

/***********************************************************
**  Description: Set function for availSeats
**  Parameters: 1 integer
************************************************************/
void Car::setAvailSeats(int pass)
{
	availSeats = pass;
}

/***********************************************************
**  Description: Set function for totalSeats
**  Parameters: 1 integer
************************************************************/
void Car::setTSeats(int pass)
{
	totalSeats = pass;
}

/***********************************************************
**  Description: Set function for carSize
**  Parameters: 1 enum of size
************************************************************/
void Car::setSize(Car::size s)
{
	carSize = s;
}

/***********************************************************
**  Description: Set function for special
**  Parameters: 1 enum of specialAbility
************************************************************/
void Car::setSpecial(Car::specialAbility ability)
{
	special = ability;
}

/***********************************************************
**  Description: Constructor for the RallyCar
**  Parameters: None
************************************************************/
RallyCar::RallyCar()
{
	nameCar = "Rally Car";
	speedCar = 2;
	totalCargo = 0;
	availCargo = 10;
	money = 500;		// Cost is 500 credits
	gasTank = 16;
	gasTurn = 3;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 1;
	carSize = medium;
	special = nothing;
}

/***********************************************************
**  Description: Destructor for the RallyCar
**  Parameters: None
************************************************************/
RallyCar::~RallyCar()
{
}


/***********************************************************
**  Description: Constructor for the LightCycle
**  Parameters: None
************************************************************/
LightCycle::LightCycle()
{
	nameCar = "Light Cycle";
	speedCar = 1;
	totalCargo = 0;
	availCargo = 4;
	money = 250;		// Cost is 750 credits
	gasTank = 21;
	gasTurn = 3;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 0;
	carSize = small;
	special = nothing;
}

/***********************************************************
**  Description: Destructor for the LightCycle
**  Parameters: None
************************************************************/
LightCycle::~LightCycle()
{
}


/***********************************************************
**  Description: Constructor for the VanDango
**  Parameters: None
************************************************************/
VanDango::VanDango()
{
	nameCar = "Van Dango";
	speedCar = 3;
	totalCargo = 0;
	availCargo = 16;
	money = 600;		// Cost is 400 credits
	gasTank = 20;
	gasTurn = 4;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 5;
	carSize = large;
	special = nothing;
}

/***********************************************************
**  Description: Destructor for the VanDango
**  Parameters: None
************************************************************/
VanDango::~VanDango()
{
}


/***********************************************************
**  Description: Constructor for the SolarSailor
**  Parameters: None
************************************************************/
SolarSailor::SolarSailor()
{
	nameCar = "Solar Sailor";
	speedCar = 3;
	totalCargo = 0;
	availCargo = 6;
	money = 500;		// Cost is 500 credits
	gasTank = 1;
	gasTurn = 0;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 1;
	carSize = small;
	special = evadeDesert;
}

/***********************************************************
**  Description: Destructor for the SolarSailor
**  Parameters: None
************************************************************/
SolarSailor::~SolarSailor()
{
}


/***********************************************************
**  Description: Constructor for the MtnCAT
**  Parameters: None
************************************************************/
MtnCAT::MtnCAT()
{
	nameCar = "Mountain CAT";
	speedCar = 3;
	totalCargo = 0;
	availCargo = 20;
	money = 250;		// Cost is 750 credits
	gasTank = 80;
	gasTurn = 10;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 7;
	carSize = large;
	special = evadeMtn;
}

/***********************************************************
**  Description: Destructor for the MtnCAT
**  Parameters: None
************************************************************/
MtnCAT::~MtnCAT()
{
}


/***********************************************************
**  Description: Constructor for the Beaver
**  Parameters: None
************************************************************/
Beaver::Beaver()
{
	nameCar = "B.E.A.V.O.";
	speedCar = 3;
	totalCargo = 0;
	availCargo = 16;
	money = 250;		// Cost is 750 credits
	gasTank = 80;
	gasTurn = 10;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 5;
	carSize = large;
	special = evadeSwamp;
}

/***********************************************************
**  Description: Destructor for the Beaver
**  Parameters: None
************************************************************/
Beaver::~Beaver()
{
}


/***********************************************************
**  Description: Constructor for the Mach5
**  Parameters: None
************************************************************/
Mach5::Mach5()
{
	nameCar = "Mach 5";
	speedCar = 1;
	totalCargo = 0;
	availCargo = 4;
	money = 150;		// Cost is 850 credits
	gasTank = 16;
	gasTurn = 3;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 0;
	carSize = medium;
	special = evadeCave;
}

/***********************************************************
**  Description: Destructor for the Mach5
**  Parameters: None
************************************************************/
Mach5::~Mach5()
{
}


/***********************************************************
**  Description: Constructor for the Airship
**  Parameters: None
************************************************************/
Airship::Airship()
{
	nameCar = "Zepplin de Led";
	speedCar = 3;
	totalCargo = 0;
	availCargo = 16;
	money = 200;		// Cost is 800 credits
	gasTank = 60;
	gasTurn = 2;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 5;
	carSize = large;
	special = evadeSky;
}

/***********************************************************
**  Description: Destructor for the Airship
**  Parameters: None
************************************************************/
Airship::~Airship()
{
}


/***********************************************************
**  Description: Constructor for the LoRyda
**  Parameters: None
************************************************************/
LoRyda::LoRyda()
{
	nameCar = "Lo Ryda";
	speedCar = 2;
	totalCargo = 0;
	availCargo = 8;
	money = 250;		// Cost is 750 credits
	gasTank = 20;
	gasTurn = 3;
	availGas = gasTank;	// Full Tank
	availSeats = 0;
	totalSeats = 3;
	carSize = medium;
	special = evadeUrban;
}

/***********************************************************
**  Description: Destructor for the LoRyda
**  Parameters: None
************************************************************/
LoRyda::~LoRyda()
{
}

/***********************************************************
**  Description: Displays the car's attributes
**  Parameters: None
************************************************************/
bool Car::displayCar()
{
	// Get variables
	char userChoice;
	bool answer = false;
	bool exit = false;

	// Output car description
	cout << "\n\nThe " << nameCar << endl;
	cout << "Spends " << speedCar << " turn(s) per location." << endl;
	if (carSize == Car::small)
		cout << "The vehicle's size is: Small." << endl;
	else if (carSize == Car::medium)
		cout << "The vehicle's size is: Medium." << endl;
	else
		cout << "The vehicle's size is: Large." << endl;
	cout << "Available cargo space is: " << availCargo << endl;
	cout << "Available passenger seats is: " << totalSeats << endl;
	cout << "Total Gas Tank size is " << gasTank << " and uses " << gasTurn << " units per turn." << endl;
	if (special == Car::evadeDesert)
		cout << "The " << nameCar << " is capable avoiding most obstacles and move at higher speeds in the desert regions." << endl;
	else if (special == Car::evadeCave)
		cout << "The " << nameCar << " is capable of avoiding most obstacles and move at higher speeds in the cavern regions." << endl;
	else if (special == Car::evadeMtn)
		cout << "The " << nameCar << " is capable of avoiding most obstacles and moving at higher speeds in the mountain regions." << endl;
	else if (special == Car::evadeSky)
		cout << "The " << nameCar << " is capable of avoiding most obstacles and moving at higher speeds in the sky regions." << endl;
	else if (special == Car::evadeSwamp)
		cout << "The " << nameCar << " is capable of avoiding most obstacles and moving at higher speeds in the swamp regions." << endl;
	else if (special == Car::evadeUrban)
		cout << "The " << nameCar << " is capable of avoiding most obstacles and moving at higher speeds in the urban regions." << endl;
	else
		cout << "The " << nameCar << " is capable of obtaining a special ability during the race." << endl;

	//Loop, incase user enters incorrect input
	while (!exit)
	{
		cout << "\n\nWould you like to take this car(Y/N)?";
		cin >> userChoice;
		userChoice = toupper(userChoice);

		// Switch Case
		switch (userChoice)
		{
		case 'Y':
		{
			answer = true;
			exit = true;
			break;
		}
		case 'N':
		{
			exit = true;
			break;
		}
		default:
			cout << "\n\nYour answer is unclear.  Please try again." << endl << endl;
			break;
		}
	}
	// return answer
	return answer;
}

/***********************************************************
**  Description: Print Items and passengers
**  Parameters: None
************************************************************/
void Car::printItemsPass()
{
	// Set variables
	int itemSize = items.size();
	int passSize = passengers.size();
	Store item;
	string objName;

	if (itemSize == 0)
		cout << "\n\nYou currently have nothing in your cargo." << endl;
	else
	{
		cout << "\n\nIn your cargo, you have: " << endl;
		// Loop through all the items and print
		for (int i = 0; i < itemSize; i++)
		{
			item = items[i];
			objName = item.getObjName();
			cout << " - " << objName << endl;
		}
	}
	cout << endl << endl;
	// Loop through all the passengers and print
	if (passSize == 0)
		cout << "\nYou currently have no passengers." << endl;
	else
	{
		cout << "\nPassengers include: " << endl;
		// Loop throug all the passengers and print
		for (int j = 0; j < passSize; j++)
		{
			item = passengers[j];
			objName = item.getObjName();
			cout << " - " << objName << endl;
		}
	}
}

/***********************************************************
**  Description: Return an item in inventory to use
**  Parameters: None
************************************************************/
Store Car::displayItems()
{
	// Set variables
	int itemSize = items.size();
	Store item;
	string objName;
	int num;


	if (itemSize == 0)
	{
		cout << "\n\nYou currently have nothing in your cargo." << endl;
		Trap trap;
		item = trap;
	}
	else
	{
		cout << "\n\nIn your cargo, you have: ";
		// Loop through all the items and print
		for (int i = 0; i < itemSize; i++)
		{
			item = items[i];
			objName = item.getObjName();
			cout << i << "- " << objName << endl;
		}
	}
	cout << "33 - To exit!" << endl;
	cout << "Please choose the item from the number: ";
	cin >> num;

	if (num == 33)
	{
		Trap trap;
		item = trap;
	}
	else
	{
		// Get the item
		item = items[num];
		subItem(item.getObj());
	}

	return item;
}

/***********************************************************
**  Description: Return a passenger to be used
**  Parameters: None
************************************************************/
Store Car::displayPass()
{
	// Set variables
	int passSize = passengers.size();
	Store passenger;
	string passName;
	int num;


	if (passSize == 0)
	{
		cout << "\n\nYou currently have no passengers" << endl;
		Trap trap;
		passenger = trap;
	}
	else
	{
		cout << "\n\nIn your passenger seats, you have: ";
		// Loop through all the items and print
		for (int i = 0; i < passSize; i++)
		{
			passenger = passengers[i];
			passName = passenger.getObjName();
			cout << i << "- " << passName << endl;
		}
	}
	cout << "33 - To exit!" << endl;
	cout << "Please choose the item from the number: ";
	cin >> num;

	if (num == 33)
	{
		Trap trap;
		passenger = trap;
	}
	else
	{
		// Get the item
		passenger = passengers[num];
		subPass(passenger.getObj());
	}

	return passenger;
}

/***********************************************************
**  Description: Add object to the car's cargo
**  Parameters: 1 Store inventory item
************************************************************/
void Car::addItem(Store item, int itemSize)
{
	// Add item to vector
	items.push_back(item);

	// Add size of item to total Cargo
	totalCargo += itemSize;
}

/***********************************************************
**  Description: Add passenger to the car's seat
**  Parameters: 1 Store inventory item
************************************************************/
void Car::addPass(Store pass)
{
	// Add item to vector
	passengers.push_back(pass);

	// Add an occupied seat
	availSeats++;
}

/***********************************************************
**  Description: Remove item from car's cargo
**  Parameters: 1 Store enumeration of typeObj
************************************************************/
void Car::subItem(Store::typeObj it)
{
	// Set variables
	int itemSize = items.size();
	Store::typeObj item;

	// Loop through vector
	for (int i = 0; i < itemSize; i++)
	{
		item = items[i].getObj();
		if (item == it)
		{
			// Remove the item
			items.erase(items.begin()+i);
			totalCargo = totalCargo - 1;
			break;
		}
	}
}

/***********************************************************
**  Description: Remove passenger from car's seat
**  Parameters: 1 Store enumeration of typeObj
************************************************************/
void Car::subPass(Store::typeObj person)
{
	// Set variables
	int passSize = passengers.size();
	Store::typeObj pass;

	// Loop through vector
	for (int i = 0; i < passSize; i++)
	{
		pass = passengers[i].getObj();
		if (pass == person)
		{
			// Remove the passenger
			passengers.erase(passengers.begin() + i);
			availSeats = availSeats - 1;
			break;
		}
	}
}

/***********************************************************
**  Description: Get function for objname
**  Parameters: None
************************************************************/
string Store::getObjName()
{
	return objName;
}

/***********************************************************
**  Description: Get function for cost
**  Parameters: None
************************************************************/
int Store::getCost()
{
	return cost;
}

/***********************************************************
**  Description: Get function for spaceObj
**  Parameters: None
************************************************************/
int Store::getObjSpace()
{
	return spaceObj;
}

/***********************************************************
**  Description: Get function for obj
**  Parameters: None
************************************************************/
Store::typeObj Store::getObj()
{
	return obj;
}

/***********************************************************
**  Description: Get function for inv
**  Parameters: None
************************************************************/
Store::invType Store::getInv()
{
	return inv;
}

/***********************************************************
**  Description: Set function for objname
**  Parameters: 1 string
************************************************************/
void Store::setObjName(string n)
{
	objName = n;
}

/***********************************************************
**  Description: Set function for cost
**  Parameters: 1 integer
************************************************************/
void Store::setCost(int c)
{
	cost = c;
}

/***********************************************************
**  Description: Set function for spaceObj
**  Parameters: 1 integer
************************************************************/
void Store::setObjSpace(int space)
{
	spaceObj = space;
}

/***********************************************************
**  Description: set function for obj
**  Parameters: 1 Store::typeObj
************************************************************/
void Store::setTypeObj(Store::typeObj to)
{
	obj = to;
}

/***********************************************************
**  Description: Set function for inv
**  Parameters: 1 Store::invType
************************************************************/
void Store::setInvType(Store::invType it)
{
	inv = it;
}

/***********************************************************
**  Description: Constructor for wrench
**  Parameters: None
************************************************************/
Wrench::Wrench()
{
	objName = "Wrench";
	cost = 20;
	spaceObj = 1;
	obj = Store::wrench;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for wrench
**  Parameters: None
************************************************************/
Wrench::~Wrench()
{

}

/***********************************************************
**  Description: Constructor for nas
**  Parameters: None
************************************************************/
Nas::Nas()
{
	objName = "Nas";
	cost = 100;
	spaceObj = 1;
	obj = Store::nas;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for nas
**  Parameters: None
************************************************************/
Nas::~Nas()
{

}

/***********************************************************
**  Description: Constructor for ninja
**  Parameters: None
************************************************************/
Ninja::Ninja()
{
	objName = "Ninja";
	cost = 75;
	spaceObj = 0;
	obj = Store::ninja;
	inv = Store::passenger;
}

/***********************************************************
**  Description: Destructor for ninja
**  Parameters: None
************************************************************/
Ninja::~Ninja()
{

}

/***********************************************************
**  Description: Constructor for tracTire
**  Parameters: None
************************************************************/
TracTire::TracTire()
{
	objName = "Traction Tires";
	cost = 75;
	spaceObj = 4;
	obj = Store::tracTire;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for tracTire
**  Parameters: None
************************************************************/
TracTire::~TracTire()
{

}

/***********************************************************
**  Description: Constructor for letter
**  Parameters: None
************************************************************/
Letter::Letter()
{
	objName = "Letter";
	cost = 0;
	spaceObj = 1;
	obj = Store::letter;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for letter
**  Parameters: None
************************************************************/
Letter::~Letter()
{

}

/***********************************************************
**  Description: Constructor for food
**  Parameters: None
************************************************************/
Food::Food()
{
	objName = "Food";
	cost = 0;
	spaceObj = 3;
	obj = Store::food;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for food
**  Parameters: None
************************************************************/
Food::~Food()
{

}

/***********************************************************
**  Description: Constructor for water
**  Parameters: None
************************************************************/
Water::Water()
{
	objName = "Water";
	cost = 0;
	spaceObj = 2;
	obj = Store::water;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for water
**  Parameters: None
************************************************************/
Water::~Water()
{

}

/***********************************************************
**  Description: Constructor for traveler
**  Parameters: None
************************************************************/
Traveler::Traveler()
{
	objName = "Traveler";
	cost = 0;
	spaceObj = 0;
	obj = Store::traveler;
	inv = Store::passenger;
}

/***********************************************************
**  Description: Destructor for traveler
**  Parameters: None
************************************************************/
Traveler::~Traveler()
{

}

/***********************************************************
**  Description: Constructor for trap
**  Parameters: None
************************************************************/
Trap::Trap()
{
	objName = "Trap";
	cost = 50;
	spaceObj = 1;
	obj = Store::trap;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for trap
**  Parameters: None
************************************************************/
Trap::~Trap()
{

}

/***********************************************************
**  Description: Constructor for gas
**  Parameters: None
************************************************************/
Gas::Gas()
{
	objName = "Extra Gas";
	cost = 30;
	spaceObj = 1;
	obj = Store::gas;
	inv = Store::cargo;
}

/***********************************************************
**  Description: Destructor for gas
**  Parameters: None
************************************************************/
Gas::~Gas()
{

}

/***********************************************************
**  Description: Decide if there is enough money and space for vehicle
**  Parameters: 1 car object, and 2 integers
************************************************************/
bool Store::enoughSpace(int cost, int space, int carTSpace, int carASpace, int carMoney)
{
	// Set variables
	bool spaceCheck = false;
	bool moneyCheck = false;
	int spaceLeft;
	bool check = false;

	// Check for enough space
	spaceLeft = carASpace - carTSpace;
	if ((spaceLeft - space) >= 0)
		spaceCheck = true;

	// Check for enough money
	if ((carMoney - cost) >= 0)
		moneyCheck = true;

	//Output results
	if ((!spaceCheck) && (!moneyCheck))
		cout << "\nYou don't have enough money and enough cargo space." << endl << endl;
	else if ((spaceCheck) && (!moneyCheck))
		cout << "\nYou have enough space, but not enough money!" << endl << endl;
	else if ((!spaceCheck) && (moneyCheck))
		cout << "\nThere's enough money, but don't have the space for more cargo!" << endl << endl;
	else
	{
		cout << "\nNo problem!  Will make the add." << endl << endl;
		check = true;
	}
	return check;
}

/***********************************************************
**  Description: Purchase avialable items from the store
**  Parameters: 1 car object
************************************************************/
void Store::storeShop(Car &car)
{
	// Set variables
	bool exit = false;			// For exiting loop
	char userMenu;				// User selection from menu
	int carTCargo,				// Car's current total cargo
		carACargo,				// Car's max available cargo
		carMoney,				// Current money
		carASeats,				// Car's current occupied passenger seats
		carTSeats;				// Car's max avaialable seats
	bool spaceMonCheck = false;
	int cost,					// size and cost for item
		size;
	string empty;				// for instream returns

	cout << "\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$   Welcome to the Pit Stop Store!   $$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
	// Loop, until the user wishes to exit the store
	while (!exit)
	{
		// Get some of Car's current attributes
		carTCargo = car.getTCargo();
		carACargo = car.getACargo();
		carMoney = car.getMoney();
		carASeats = car.getAvailSeats();
		carTSeats = car.getTSeats();

		// Output Money, Available Seats and Available Cargo
		cout << "\nYou currently have " << carMoney << " credits." << endl;
		cout << "You have " << carACargo - carTCargo << " cargo left." << endl;
		cout << "You have " << carTSeats - carASeats << " seats left." << endl << endl;

		// Store Menu Output
		cout << "**## Store Menu ##**" << endl;
		cout << "W - Wrench for 20 credits." << endl;
		cout << "N - Nas for 100 credits." << endl;
		cout << "C - Contract a Ninja for 75 credits." << endl;
		cout << "T - Traction tires for 75 credits." << endl;
		cout << "R - Trap for 50 credits." << endl;
		cout << "G - Reserve Gas for 30 credits." << endl;
		cout << "Q - To Exit the store." << endl;
		// user input
		cout << "Please make character selection from menu above: ";
		cin >> userMenu;
		userMenu = toupper(userMenu);

		// Switch case
		// See if there is enough room and Is there enough money?
		// If both conditions okay, add item/passenger to inventory.  Take away money
		switch (userMenu)
		{
		case 'W':
		{
			cost = 20;
			size = 1;
			spaceMonCheck = enoughSpace(cost, size, carTCargo, carACargo, carMoney);
			if (spaceMonCheck)
			{
				Wrench wrench;
				car.addItem(wrench, size);
				car.setMoney((carMoney - cost));
			}
			break;
		}
		case 'N':
		{
			cost = 100;
			size = 1;
			spaceMonCheck = enoughSpace(cost, size, carTCargo, carACargo, carMoney);
			if (spaceMonCheck)
			{
				Nas nas;
				car.addItem(nas, size);
				car.setMoney((carMoney - cost));
			}
			break;
		}
		case 'C':
		{
			cost = 75;
			size = 1;
			spaceMonCheck = enoughSpace(cost, size, carASeats, carTSeats, carMoney);
			if (spaceMonCheck)
			{
				Ninja ninja;
				car.addPass(ninja);
				car.setMoney((carMoney - cost));
			}
			break;
		}
		case 'T':
		{
			cost = 75;
			size = 3;
			spaceMonCheck = enoughSpace(cost, size, carTCargo, carACargo, carMoney);
			if (spaceMonCheck)
			{
				TracTire tires;
				car.addItem(tires, size);
				car.setMoney((carMoney - cost));
			}
			break;
		}
		case 'R':
		{
			cost = 50;
			size = 1;
			spaceMonCheck = enoughSpace(cost, size, carTCargo, carACargo, carMoney);
			if (spaceMonCheck)
			{
				Trap trap;
				car.addItem(trap, size);
				car.setMoney((carMoney - cost));
			}
			break;
		}
		case 'G':
		{
			cost = 30;
			size = 2;
			spaceMonCheck = enoughSpace(cost, size, carTCargo, carACargo, carMoney);
			if (spaceMonCheck)
			{
				Gas gas;
				car.addItem(gas, size);
				car.setMoney((carMoney - cost));
			}
			break;
		}
		case 'Q':
		{
			cout << "\nLeaving the shop..." << endl << endl;
			exit = true;
			break;
		}
		default:
		{
			cout << "\n\nError: Your selection does not match.  Please try again." << endl << endl;
			break;
		}
		}
	}
}