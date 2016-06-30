#ifndef ITEM_HPP
#define ITEM_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/20/2015
** Description: This is a header file used to create Item 
**    objects for the Shopping List Program.  The Item 
**    objects will store such data as the name, units of 
**    measure, number of units bought, price per unit.  
**    Methods are also in place to help store or retrieve 
**    data from the objects.
***********************************************************/
#include <iostream>
#include <string>

using namespace std;

//Item class
class Item
{
public:
	Item();
	Item(string, string, double, double);
	string getItemName();
	void setItemName(string);
	string getUnitType();
	void setUnitType(string);
	double getNumBought();
	void setNumBought(double);
	double getUnitPrice();
	void setUnitPrice(double);
	

private:

protected:
	string name;
	string unit;
	double numBought;
	double unitPrice;
};

// Club Item class
class ClubItem : public Item
{
public:
	ClubItem();
	ClubItem(string, string, double, double);
	string getItemName();
	void setItemName(string);
	string getUnitType();
	void setUnitType(string);
	double getNumBought();
	void setNumBought(double);
	double getUnitPrice();
	void setUnitPrice(double);

private:

protected:
	string clubName;
	string clubUnit;
	double clubNumBought;
	double clubUnitPrice;
};

#endif