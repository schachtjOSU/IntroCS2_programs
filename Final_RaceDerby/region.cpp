/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 06/04/2015
** Description: This is the implementation file for the 
**    parent region class and it's child classes.  There will 
**    mostly be get and set functions for the object.
***********************************************************/

#include <iostream>
#include <string>
#include "region.hpp"
#include "car.hpp"

using namespace std;

/***********************************************************
**  Description: Get function for regName
**  Parameters: None
************************************************************/
string Region::getRegName()
{
	return regName;
}

/***********************************************************
**  Description: Get function for difficulty
**  Parameters: None
************************************************************/
int Region::getDifficulty()
{
	return difficulty;
}

/***********************************************************
**  Description: Get function for type
**  Parameters: None
************************************************************/
Region::typeReg Region::getType()
{
	return type;
}

/***********************************************************
**  Description: Set function for regName
**  Parameters: 1 string
************************************************************/
void Region::setRegName(string n)
{
	regName = n;
}

/***********************************************************
**  Description: Set function for difficulty
**  Parameters: 1 integer
************************************************************/
void Region::setDifficulty(int diff)
{
	difficulty = diff;
}

/***********************************************************
**  Description: Set function for type
**  Parameters: 1 Region::type
************************************************************/
void Region::setType(Region::typeReg t)
{
	type = t;
}

/***********************************************************
**  Description: Constructor for the Mountain Class
**  Parameters: 1 string and 1 integer
************************************************************/
Mountain::Mountain(string n, int diff)
{
	regName = n;
	difficulty = diff;
	type = Region::mountain;
}

/***********************************************************
**  Description: Destructor for the Mountain Class
**  Parameters: None
************************************************************/
Mountain::~Mountain()
{

}

/***********************************************************
**  Description: Runs Danger Scenario for Mountain
**  Parameters: Car object
************************************************************/
void Mountain::DangrScenMtn(Car &car)
{

}

/***********************************************************
**  Description: Constructor for the Desert Class
**  Parameters: 1 string and 1 integer
************************************************************/
Desert::Desert(string n, int diff)
{
	regName = n;
	difficulty = diff;
	type = Region::desert;
}

/***********************************************************
**  Description: Destructor for the Desert Class
**  Parameters: None
************************************************************/
Desert::~Desert()
{

}

/***********************************************************
**  Description: Runs Danger Scenario for Desert
**  Parameters: Car object
************************************************************/
void Desert::DangrScenDes(Car &car)
{

}

/***********************************************************
**  Description: Constructor for the Swamp Class
**  Parameters: 1 string and 1 integer
************************************************************/
Swamp::Swamp(string n, int diff)
{
	regName = n;
	difficulty = diff;
	type = Region::swamp;
}

/***********************************************************
**  Description: Destructor for the Swamp Class
**  Parameters: None
************************************************************/
Swamp::~Swamp()
{

}

/***********************************************************
**  Description: Runs Danger Scenario for Swamp
**  Parameters: Car object
************************************************************/
void Swamp::DangrScenSwp(Car &car)
{

}

/***********************************************************
**  Description: Constructor for the Sky Class
**  Parameters: 1 string and 1 integer
************************************************************/
Sky::Sky(string n, int diff)
{
	regName = n;
	difficulty = diff;
	type = Region::sky;
}

/***********************************************************
**  Description: Destructor for the Sky Class
**  Parameters: None
************************************************************/
Sky::~Sky()
{

}

/***********************************************************
**  Description: Runs Danger Scenario for Sky
**  Parameters: Car object
************************************************************/
void Sky::DangrScenSky(Car &car)
{

}

/***********************************************************
**  Description: Constructor for the Urban Class
**  Parameters: 1 string and 1 integer
************************************************************/
Urban::Urban(string n, int diff)
{
	regName = n;
	difficulty = diff;
	type = Region::urban;
}

/***********************************************************
**  Description: Destructor for the Urban Class
**  Parameters: None
************************************************************/
Urban::~Urban()
{

}

/***********************************************************
**  Description: Runs Danger Scenario for Urban
**  Parameters: Car object
************************************************************/
void Urban::DangrScenUrb(Car &car)
{

}

/***********************************************************
**  Description: Constructor for the Cavern Class
**  Parameters: 1 string and 1 integer
************************************************************/
Cavern::Cavern(string n, int diff)
{
	regName = n;
	difficulty = diff;
	type = Region::cavern;
}

/***********************************************************
**  Description: Destructor for the Cavern Class
**  Parameters: None
************************************************************/
Cavern::~Cavern()
{

}

/***********************************************************
**  Description: Runs Danger Scenario for Cavern
**  Parameters: Car object
************************************************************/
void Cavern::DangrScenCave(Car &car)
{

}

/***********************************************************
**  Description: Constructor for the Gas Stop
**  Parameters: None
************************************************************/
GasStop::GasStop()
{
	regName = "Gas Stop";
	difficulty = 0;
	type = Region::gas;
}

/***********************************************************
**  Description: Destructor for the Gas Stop
**  Parameters: None
************************************************************/
GasStop::~GasStop()
{

}

/***********************************************************
**  Description: Constructor for the Gas Stop
**  Parameters: None
************************************************************/
Finish::Finish()
{
	regName = "Finish";
	difficulty = 0;
	type = Region::finish;
}

/***********************************************************
**  Description: Destructor for the Gas Stop
**  Parameters: None
************************************************************/
Finish::~Finish()
{

}