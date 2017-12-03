/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Person class. This class is the parent class for both
** characters (guard and inmate) in the jail escape game. This class has member variables
** backpack (to store items), current_location (to keep track of the player), type which
** represents the type of Character the person is, and then dig_speed and under_influence,
** which are used for the inmate class. The class also has member functions to return the
** type of Person, see if a person has a certain item, get the location of the person, 
** set the location of the person, add an item to the backpack, kill the guard (for inmate),
** check if the backpack is full, delete an item from the backpack, delete an item from the
** backpack based on a specific string, see if a person is under the influence, use the 
** syringe, return the digging speed of the person, and print backpack contents. Also 
** contains a virtual destructor for the person object.
*******************************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include "Backpack.hpp"
#include "Menu.hpp"
#include <iostream>

class Space;

class Person
{
protected:
	Backpack pack;
	Space* current_location;	//To keep track of the person's 
	std::string type;

	int dig_speed;
	bool under_influence;

public:
	std::string get_type();
	bool player_has_item(std::string);
	Space* get_location();
	void set_location(Space*);
	void add_item(Item*);
	virtual bool kill_guard();
	bool backpack_full();
	void delete_backpack_item();
	void delete_specific_item(std::string);
	bool is_under_influence();
	void use_syringe();
	int get_dig_speed();
	void print_backpack_contents();
	virtual ~Person();

};
#endif