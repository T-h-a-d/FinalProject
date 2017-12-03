/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
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