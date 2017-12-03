/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Play_Jail_Escape class. This class is used to implement
** a game of Jail Escape. It contains 9 different member variables to represent the 
** different Spaces in the game, 2 different person pointers which represent the inmate and
** the guard, an int to keep track of the game_clock, and two integers to help print out the
** clock each round to the user. The Play_Jail_Escape class also has member variables to 
** start and play the Jail Escape game, move a Person object from one space to another 
** space, check the location of two person objects to see if they are in the same space, 
** print the options for that round to the user, print the item descriptions for the user,
** print the clock for the user, print out the map for the user, and check if the game
** is over. This class also contains a constructor which connects all of the spaces into
** a 2-d board and a destructor.
*******************************************************************************************/
#ifndef PLAY_JAIL_ESCAPE_HPP
#define PLAY_JAIL_ESCAPE_HPP
#include "Menu.hpp"
#include "Guard.hpp"
#include "Inmate.hpp"
#include "Jail_Cell.hpp"
#include "Prison_Yard.hpp"
#include "Wardens_Office.hpp"
#include "Infirmary.hpp"
#include "Entrance.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"


class Play_Jail_Escape
{
private:
	Space* jail_cell;
	Space* hallway1;
	Space* hallway2;
	Space* hallway3;
	Space* yard;
	Space* infirmary;
	Space* kitchen;
	Space* entrance;
	Space* wardens_office;

	Person* guard;
	Person* inmate;

	//Keep track of in-game minutes
	int game_minutes;

	//Keep track of in-game clock
	int starting_hour;
	int minutes;

public:
	Play_Jail_Escape();
	void start_game();
	void move_person(Person* p, std::string direction);
	bool check_location(Person*, Person*);
	int print_user_options();
	void print_item_descriptions();
	bool check_if_game_over();
	void print_clock();
	void print_map();
	~Play_Jail_Escape();


};
#endif