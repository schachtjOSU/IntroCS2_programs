#ifndef REGION_HPP
#define REGION_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 06/04/2015
** Description: This is the header file for the region class.
**    This will serve to create objects from child classes
**    of the region class.
***********************************************************/

#include <iostream>
#include <string>
#include "car.hpp"

using namespace std;

class Region
{
public:
	enum typeReg{mountain, desert, sky, cavern, swamp, urban, gas, finish};

	// Get Methods
	string getRegName();
	int getDifficulty();
	Region::typeReg getType();

	// Set Methods
	void setRegName(string);
	void setDifficulty(int);
	void setType(Region::typeReg);

protected:
	string regName;			// Name of the region
	int difficulty;			// Difficulty level of region
	typeReg type;			// Enumeration of type of region

};

// The following are subClasses of the Region parent
class Mountain : public Region
{
public:
	Mountain(string, int);
	~Mountain();
	void DangrScenMtn(Car &);
};

class Desert : public Region
{
public:
	Desert(string, int);
	~Desert();
	void DangrScenDes(Car &);
};

class Swamp : public Region
{
public:
	Swamp(string, int);
	~Swamp();
	void DangrScenSwp(Car &);
};

class Sky : public Region
{
public:
	Sky(string, int);
	~Sky();
	void DangrScenSky(Car &);
};

class Urban : public Region
{
public:
	Urban(string, int);
	~Urban();
	void DangrScenUrb(Car &);
};

class Cavern : public Region
{
public:
	Cavern(string, int);
	~Cavern();
	void DangrScenCave(Car &);
};

class GasStop : public Region
{
public:
	GasStop();
	~GasStop();
};

class Finish : public Region
{
public:
	Finish();
	~Finish();
};

#endif