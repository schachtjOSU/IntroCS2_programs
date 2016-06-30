/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/21/2015
** Description: This is the list source file for the
**    Shopping List program.  This file will have include
**    the other header and source files, while having a
**    List constructor and set and get methods for each of
**    the data.  
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "List.hpp"
#include "Item.hpp"
#include <iomanip>

using namespace std;

/***********************************************************
**  Description:  Default Constructor
**  Parameters: None
************************************************************/
List::List()
{
	vector <Item> items;
}

/***********************************************************
**  Description:  Add Items
**  Parameters: 1 bool for is a club member
************************************************************/
void List::addItem(bool isMember)
{
	// set variables
	Item item;			// Create the item object
	ClubItem clubItem;	// Create the club item object
	string itemName;	// Get the Name of item
	string empty;		// Capture any escape characters
	string unitType;	// Get the unit type
	double unitsBought;	// Get the units bought from user
	double price;		// Get the price per unit from user
	bool isProdClub = false;	// Get whether product gets a discount
	char clubAns = 'N';		
	const double DISCOUNT = 0.10;

	getline(cin, empty);
	// Need an if statement for later when we start to add Club Items.
	if (isMember)
	{
		cout << "\n\nIs this Item have a Club discount (Y/N)? ";
		cin >> clubAns;
		clubAns = toupper(clubAns);
		getline(cin, empty);
	}

	// Ask the user for specifics
	cout << "\n\nEnter the name of the product: ";
	getline(cin, itemName);

	cout << "\nEnter the unit of scale(ie. ounce, case, dozen, etc): ";
	getline(cin, unitType);

	cout << "\nEnter the number of units bought: ";
	cin >> unitsBought;

	getline(cin, empty);

	cout << "\nEnter the price per unit: $";
	cin >> price;

	getline(cin, empty);

	// If not a Club item...
	if (clubAns != 'Y')
	{
		// Set each of the user answers into the item object
		item.setItemName(itemName);
		item.setUnitType(unitType);
		item.setNumBought(unitsBought);
		item.setUnitPrice(price);
		// Add the item into the list
		items.push_back(item);
	}
	else
	{
		clubItem.setItemName(itemName);
		clubItem.setUnitType(unitType);
		clubItem.setNumBought(unitsBought);
		price = price - (price * DISCOUNT);
		clubItem.setUnitPrice(price);
		items.push_back(clubItem);
	}
}

/***********************************************************
**  Description:  Remove Items
**  Parameters: None
************************************************************/
void List::removeItem()
{
	// Set variables
	string userRemove;
	string empty;
	int itemSize;
	string compName;
	bool found = false;
	

	getline(cin, empty);
	itemSize = items.size();

	// Ask the user for the name of the item
	cout << "\nEnter the name of the item to be removed: ";
	getline(cin, userRemove);

	// Loop through each item in the list until there is a match
	for (int i = 0; i < itemSize; i++)
	{
		compName = items[i].getItemName();
		if (userRemove == compName)
		{
			items.erase(items.begin()+i);
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "\nItem could not be found.  Please display and try again." << endl;
	}

}

/***********************************************************
**  Description:  Display Items
**  Parameters: None
************************************************************/
void List::displayList()
{
	// Set variables
	int itemSize;
	string name;
	string unType;
	double numUnits = 0;
	double price = 0;
	double tempPrice = 0;
	double totalPrice = 0;

	// Get the size of the items vector
	itemSize = items.size();

	if (itemSize == 0)
	{
		cout << "\n\nYou have no items in your list.  Please go to add in your list!" << endl;
	}
	else
	{

		// Entry Display
		cout << "\n\nYour Shopping List: " << endl;

		// Loop through each item
		for (int i = 0; i < itemSize; i++)
		{
			// Get each item data
			name = items[i].getItemName();
			unType = items[i].getUnitType();
			numUnits = items[i].getNumBought();
			price = items[i].getUnitPrice();
			tempPrice = numUnits * price;
			totalPrice += tempPrice;

			// Display each data from item
			cout << "\nItem Name: " << name;
			cout << "\n    Unit Type: " << unType;
			cout << "\n    Number of Units: " << numUnits;
			cout << "\n    Price: $" << fixed << setprecision(2) << price;
		}

		cout << "\n\nTotal Price of List: $" << totalPrice;
	}
}