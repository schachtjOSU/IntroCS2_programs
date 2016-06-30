#ifndef LIST_HPP
#define LIST_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 04/20/2015
** Description: This is a header file used to create the 
**    List object for the Shopping List Program.  The list 
**    will store such data as the regular items and club 
**    items.  It also includes methods to add items, remove 
**    items and display the list to the user.
***********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Item.hpp"

using namespace std;

// List class
class List
{
public:
	List();
	void addItem(bool);
	void removeItem();
	void displayList();

private:
	vector <Item> items;
	vector <ClubItem> clubItems;
};


#endif