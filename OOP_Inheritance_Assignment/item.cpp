/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/21/2015
** Description: This is the item source file for the
**    Shopping List program.  This file will have include
**    the other header and source files, while having an 
**    Item constructor and set and get methods for each of 
**    the data.  There will also be an added second class 
**    for the ClubItem having the same as the Item.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "List.hpp"
#include "Item.hpp"

using namespace std;

/***********************************************************
**  Description:  Default Constructor
**  Parameters: None
************************************************************/
Item::Item()
{
	this->name = "";
	this->unit = "";
	this->numBought = 0;
	this->unitPrice = 0;
}

/***********************************************************
**  Description:  Constructor
**  Parameters: 1 string, 1 enum for unit, and 2 double
************************************************************/
Item::Item(string n, string u, double buy, double price)
{
	// Set variables
	Item item;

	// Set data for object
	this->name = n;
	this->unit = u;
	this->numBought = buy;
	this->unitPrice = price;
}

/***********************************************************
**  Description:  Set method for name
**  Parameters: 1 string
************************************************************/
void Item::setItemName(string n)
{
	name = n;
}

/***********************************************************
**  Description:  Set method for unit
**  Parameters: 1 enumeration Unit
************************************************************/
void Item::setUnitType(string u)
{
	unit = u;
}

/***********************************************************
**  Description:  Set method for numBought
**  Parameters: 1 double
************************************************************/
void Item::setNumBought(double buy)
{
	numBought = buy;
}

/***********************************************************
**  Description:  Set method for unitPrice
**  Parameters: 1 double
************************************************************/
void Item::setUnitPrice(double price)
{
	unitPrice = price;
}

/***********************************************************
**  Description:  Get method for name
**  Parameters: None
************************************************************/
string Item::getItemName()
{
	return this->name;
}

/***********************************************************
**  Description:  Get method for unit
**  Parameters: None
************************************************************/
string Item::getUnitType()
{
	return unit;
}

/***********************************************************
**  Description:  Get method for numBought
**  Parameters: None
************************************************************/
double Item::getNumBought()
{
	return this->numBought;
}

/***********************************************************
**  Description:  Get method for unitPrice
**  Parameters: None
************************************************************/
double Item::getUnitPrice()
{
	return this->unitPrice;
}

//Club Item Methods///////////////////////////////////////////

/***********************************************************
**  Description:  Default Constructor
**  Parameters: None
************************************************************/
ClubItem::ClubItem()
{
	this->clubName = "";
	this->clubUnit = "";
	this->clubNumBought = 0;
	this->clubUnitPrice = 0;
}

/***********************************************************
**  Description:  Constructor
**  Parameters: 1 string, 1 enum for unit, and 2 double
************************************************************/
ClubItem::ClubItem(string n, string u, double buy, double price)
{
	// Set variables
	Item item;

	// Set data for object
	this->clubName = n;
	this->clubUnit = u;
	this->clubNumBought = buy;
	this->clubUnitPrice = price;
}

/***********************************************************
**  Description:  Set method for name
**  Parameters: 1 string
************************************************************/
void ClubItem::setItemName(string n)
{
	name = n;
}

/***********************************************************
**  Description:  Set method for unit
**  Parameters: 1 enumeration Unit
************************************************************/
void ClubItem::setUnitType(string u)
{
	unit = u;
}

/***********************************************************
**  Description:  Set method for numBought
**  Parameters: 1 double
************************************************************/
void ClubItem::setNumBought(double buy)
{
	numBought = buy;
}

/***********************************************************
**  Description:  Set method for unitPrice
**  Parameters: 1 double
************************************************************/
void ClubItem::setUnitPrice(double price)
{
	unitPrice = price;
}

/***********************************************************
**  Description:  Get method for name
**  Parameters: None
************************************************************/
string ClubItem::getItemName()
{
	return this->name;
}

/***********************************************************
**  Description:  Get method for unit
**  Parameters: None
************************************************************/
string ClubItem::getUnitType()
{
	return unit;
}

/***********************************************************
**  Description:  Get method for numBought
**  Parameters: None
************************************************************/
double ClubItem::getNumBought()
{
	return this->numBought;
}

/***********************************************************
**  Description:  Get method for unitPrice
**  Parameters: None
************************************************************/
double ClubItem::getUnitPrice()
{
	return this->unitPrice;
}