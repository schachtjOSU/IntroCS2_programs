#ifndef CAR_HPP
#define CAR_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 06/03/2015
** Description: This is the header file for the car class.  
**    This will serve to create objects from child classes 
**    of the car class.
***********************************************************/
class Car;
#include <iostream>
#include <string>
#include <vector>
//#include "store.hpp"

using namespace std;

class Store
{
public:
	enum typeObj{ wrench, nas, ninja, tracTire, letter, food, water, traveler, trap, gas };
	enum invType{ cargo, passenger };

	// Get methods
	string getObjName();
	int getCost();
	int getObjSpace();
	Store::typeObj getObj();
	Store::invType getInv();

	// Set methods
	void setObjName(string);
	void setCost(int);
	void setObjSpace(int);
	void setTypeObj(Store::typeObj);
	void setInvType(Store::invType);

	// methods for shopping at the store
	void storeShop(Car &);
	bool enoughSpace(int, int, int, int, int);

protected:
	string objName;			// Name of Object
	int cost;				// Cost of Object
	int spaceObj;			// Space taken up in cargo
	typeObj obj;			// type of object
	invType inv;			// Does obj go in the cargo or passenger seat
};

class Car
{
public:
	// Create the different enumerations for the car
	enum size{ small, medium, large };
	enum specialAbility{evadeDesert, evadeMtn, evadeSwamp, evadeCave, evadeSky, evadeUrban, warpBoost, goldWrench, goldMap, goldNinja, goldTires, nothing};

	// Get functions
	string getName();
	int getSpeed();
	int getTCargo();
	int getACargo();
	int getMoney();
	int getTank();
	int getGas();
	int getAGas();
	int getAvailSeats();
	int getTSeats();
	Car::size getSize();
	Car::specialAbility getSpecial();

	// Set functions
	void setName(string);
	void setSpeed(int);
	void setTCargo(int);
	void setACargo(int);
	void setMoney(int);
	void setTank(int);
	void setGas(int);
	void setAGas(int);
	void setAvailSeats(int);
	void setTSeats(int);
	void setSize(Car::size);
	void setSpecial(Car::specialAbility);

	// Get and set location of Car

	// Add and subtract items from cargo and passengers from seats
	void addItem(Store, int);
	void addPass(Store);
	void subItem(Store::typeObj);
	void subPass(Store::typeObj);
	void printItemsPass();
	Store displayItems();
	Store displayPass();
	bool displayCar();

protected:
	string nameCar;			// Name of car
	int speedCar,			// Speed of the car or turns per location
		totalCargo,			// Total cargo car currently has
		availCargo,			// Available cargo space in car
		money,				// Money left
		gasTank,			// Size of car's tank
		gasTurn,			// Gas used per turn
		availGas,			// Gas car currently has
		availSeats,			// occupied passenger seats
		totalSeats;			// Seats for passengers
	size carSize;			// Size of car
	specialAbility special;	// Special item
	vector <Store> items;	// Items in cargo
	vector <Store> passengers;	// Passengers in seats
	// Pointer to locatio of car

};

class RallyCar : public Car
{
public:
	RallyCar();
	~RallyCar();
};

class LightCycle : public Car
{
public:
	LightCycle();
	~LightCycle();
};

class VanDango : public Car
{
public:
	VanDango();
	~VanDango();
};

class SolarSailor : public Car
{
public:
	SolarSailor();
	~SolarSailor();
};

class MtnCAT : public Car
{
public:
	MtnCAT();
	~MtnCAT();
};

class Beaver : public Car
{
public:
	Beaver();
	~Beaver();
};

class Mach5 : public Car
{
public:
	Mach5();
	~Mach5();
};

class Airship : public Car
{
public:
	Airship();
	~Airship();
};

class LoRyda : public Car
{
public:
	LoRyda();
	~LoRyda();
};

// The following are sub classes of the Store parent
class Wrench : public Store
{
public:
	Wrench();
	~Wrench();
};

class Nas : public Store
{
public:
	Nas();
	~Nas();
};

class Ninja : public Store
{
public:
	Ninja();
	~Ninja();
};

class TracTire : public Store
{
public:
	TracTire();
	~TracTire();
};

class Letter : public Store
{
public:
	Letter();
	~Letter();
};

class Food : public Store
{
public:
	Food();
	~Food();
};

class Water : public Store
{
public:
	Water();
	~Water();
};

class Traveler : public Store
{
public:
	Traveler();
	~Traveler();
};

class Trap : public Store
{
public:
	Trap();
	~Trap();
};

class Gas : public Store
{
public:
	Gas();
	~Gas();
};
#endif