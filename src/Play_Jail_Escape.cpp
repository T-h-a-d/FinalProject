/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Play_Jail_Escape class. This class 
** is used to implement a game of Jail Escape. It contains 9 different member variables to 
** represent the different Spaces in the game, 2 different person pointers which represent 
** the inmate and the guard, an int to keep track of the game_clock, and two integers to 
** help print out the clock each round to the user. The Play_Jail_Escape class also has 
** member variables to start and play the Jail Escape game, move a Person object from one 
** space to another space, check the location of two person objects to see if they are in 
** the same space, print the options for that round to the user, print the item descriptions 
** for the user, print the clock for the user, print out the map for the user, and check if 
** the game is over. This class also contains a constructor which connects all of the spaces 
** into a 2-d board and a destructor.
*******************************************************************************************/
#include "Play_Jail_Escape.hpp"

/******************************************************************************************
** Constructor: Play_Jail_Escape
** Description: Constructs a Play_Jail_Escape game object. The constructor dynaimcally 
** allocates 9 different spaces and then connects them to eachother to create a 2-d board.
** The constructor also dynamically allocates a guard and an inmate object, initializes
** the game minutes to zero, and sets the starting hour to 1:00.
*******************************************************************************************/

Play_Jail_Escape::Play_Jail_Escape()
{
	//Dynamically allocate spaces
	jail_cell = new Jail_Cell;
	hallway1  = new Hallway("Jail Cell Hallway");
	hallway2  = new Hallway("Infirmary Hallway");
  hallway3  = new Hallway("Entrance Hallway");
  yard 			= new Prison_Yard;	
  infirmary = new Infirmary;
  kitchen 	= new Kitchen;
  entrance	= new Entrance;
	wardens_office = new Wardens_Office;

	//Dynaimcally allocate a guard and an inmate
	guard = new Guard;
	inmate = new Inmate;

	//Inmate starts in jail, guard starts at the entrance
	inmate->set_location(jail_cell);
	guard->set_location(entrance);

	//Connect rooms to each other

	//Set up jail_cell connections
	jail_cell->set_adjacent_spaces("left", hallway2);
	jail_cell->set_adjacent_spaces("top", hallway1);
	jail_cell->set_adjacent_spaces("bottom", nullptr);
	jail_cell->set_adjacent_spaces("right", nullptr);

	//Set up hallway1 connections
	hallway1->set_adjacent_spaces("left", yard);
	hallway1->set_adjacent_spaces("top", nullptr);
	hallway1->set_adjacent_spaces("bottom", jail_cell);
	hallway1->set_adjacent_spaces("right", nullptr);

	//Set up hallway2 connections
	hallway2->set_adjacent_spaces("left", infirmary);
	hallway2->set_adjacent_spaces("top", yard);
	hallway2->set_adjacent_spaces("bottom", nullptr);
	hallway2->set_adjacent_spaces("right", jail_cell);

	//Set up prison_yard connections
	yard->set_adjacent_spaces("left", kitchen);
	yard->set_adjacent_spaces("top", wardens_office);
	yard->set_adjacent_spaces("bottom", hallway2);
	yard->set_adjacent_spaces("right", hallway1);

	//Set up infirmary connections
	infirmary->set_adjacent_spaces("left", nullptr);
	infirmary->set_adjacent_spaces("top", kitchen);
	infirmary->set_adjacent_spaces("bottom", nullptr);
	infirmary->set_adjacent_spaces("right", hallway2);

	//Set up kitchen connections
	kitchen->set_adjacent_spaces("left", nullptr);
	kitchen->set_adjacent_spaces("top", hallway3);
	kitchen->set_adjacent_spaces("bottom", infirmary);
	kitchen->set_adjacent_spaces("right", yard);

	//Set up wardens office connections
	wardens_office->set_adjacent_spaces("left", nullptr);
	wardens_office->set_adjacent_spaces("top", nullptr);
	wardens_office->set_adjacent_spaces("bottom", yard);
	wardens_office->set_adjacent_spaces("right", nullptr);

	//Set up hallway3 connections
	hallway3->set_adjacent_spaces("left", entrance);
	hallway3->set_adjacent_spaces("top", nullptr);
	hallway3->set_adjacent_spaces("bottom", kitchen);
	hallway3->set_adjacent_spaces("right", nullptr);

	//Set up entrance connections
	entrance->set_adjacent_spaces("left", nullptr );
	entrance->set_adjacent_spaces("top", nullptr);
	entrance->set_adjacent_spaces("bottom", nullptr);
	entrance->set_adjacent_spaces("right", hallway3);

	//Initialize game_minutes to zero
	game_minutes = 0;

	//Starting hour is 1:00 am
	starting_hour = 1;
	minutes = 0;

}

/******************************************************************************************
** Function: start_game
** Description: This function implements a game of Jail Escape. The do while loop runs 
** while the game_over conditions are not met. Each round, the user has the option to 
** choose an action (moving or interacting with the space), or calling a function which
** prints a map, backpack contents, or a hint guide. The actions take time off the game 
** clock, while the help choices do not. The guard also moves every time the player chooses
** an action. The location of the guard is printed out each round if the player has the
** guard_radio.
*******************************************************************************************/

void Play_Jail_Escape::start_game()
{
	do
	{
		print_clock();

		int user_choice_1 = print_user_options();

		switch(user_choice_1)
		{
			case(1):
			{
				//Move the guard in a random direction if user moves or inspects
				std::string guard_direction;

				guard_direction = guard->get_location()->room_options_guard();

				move_person(guard, guard_direction);

				//Move the inmate based on user input
				std::string user_direction;

				std::cout << "Where would you like to go?" << std::endl;
				std::cout << std::endl;
				user_direction = inmate->get_location()->room_options_player();

				move_person(inmate, user_direction);

				//Moving takes 10 minutes
				game_minutes = game_minutes + 10;
				minutes = minutes + 10;

				break;
			}

			case(2):
			{
				//Move the guard in a random direction if user moves or inspects
				std::string guard_direction;

				guard_direction = guard->get_location()->room_options_guard();

				move_person(guard, guard_direction);

				//Interact with the room
				inmate->get_location()->inspect_room(inmate);

				//Inspecting room takes 10 minutes
				game_minutes = game_minutes + 10;
				minutes = minutes + 10;

				break;

			}

			case(3):
			{
				//List the current items in the backpack(does not take any time)
				inmate->print_backpack_contents();

				break;
			}

			case(4):
			{
				//Print each item and their functions
				print_item_descriptions();

				break;
			}

			case(5):
			{
				//print the map for the user to see
				print_map();
			}
		}

		//Print out guard location if user has guard_radio
		if(inmate->player_has_item("Guard's Radio"))
		{
			std::cout << std::endl;
			std::cout << "Guard's Current Location: ";
			std::cout << guard->get_location()->get_name() << std::endl;
		}
	}
	while(!check_if_game_over());
}

/******************************************************************************************
** Function: move_person
** Description: Function which takes a person pointer and string (direction) as paramters
** and then changes the location of the person to the new location specified by the 
** string which represents the correct direction to travel in. The guard is allowed to move
** to any space, but the player is restricted to certain spaces based on the items in the
** backpack.
*******************************************************************************************/

void Play_Jail_Escape::move_person(Person* p, std::string direction)
{
	//Get current location of person
	Space* current_position = p->get_location();

	if(p->get_type() == "Inmate")
	{
		//Check if player needs access to get into certain space
		if(current_position->get_adjacent_space(direction)->item_needed())
		{
			std::string item_name = current_position->get_adjacent_space(direction)->get_name_of_item_needed();

			//Player has the item needed to enter the space
			if(p->player_has_item(item_name))
			{
				//Set new position equal the direction that the user entered
				Space* new_position = current_position->get_adjacent_space(direction);
				p->set_location(new_position);
			}

			//Player does not have required access to the space
			else
			{
				current_position->get_adjacent_space(direction)->print_item_needed();
			}
		}

		//No item is required to enter the space
		else
		{
			//Set new position equal the direction that the user entered
			Space* new_position = current_position->get_adjacent_space(direction);
			p->set_location(new_position);
		}
	}

	//Else the person to move is the guard
	else
	{
		//Set new position equal to the direction parameter
		Space* new_position = current_position->get_adjacent_space(direction);
		p->set_location(new_position);
	}
}

/******************************************************************************************
** Function: check_location
** Description: Function which takes two person pointers as parameters and checks if 
** their current locations are equal to eachother. If they are in the same room, the 
** function returns a boolean value of true. If they are not in the same room, the function
** returns false.
*******************************************************************************************/

bool Play_Jail_Escape::check_location(Person* p1, Person* p2)
{
	bool same_location;

	std::string p1_location = p1->get_location()->get_name();
	std::string p2_location = p2->get_location()->get_name();

	if(p1_location == p2_location)
	{
		same_location = true;
	}

	else
	{
		same_location = false;
	}

	return(same_location);
}

/******************************************************************************************
** Function: print_user_options
** Description: This function prints the options that the user has to choose from 
** each round. The function then gets the user input, stores it in user_choice, and 
** returns it as an integer to the start_game function above.
*******************************************************************************************/

int Play_Jail_Escape::print_user_options()
{
	int user_choice;

	std::cout << std::endl;
	std::cout << "------------ Actions ------------" << std::endl;
	std::cout << "1. Travel to another room" << std::endl;
	std::cout << "2. Inspect " << inmate->get_location()->get_name() << std::endl;
	std::cout << std::endl;

	std::cout << "------------ Help ---------------" << std::endl;
	std::cout << "3. Look at contents of backpack" << std::endl;
	std::cout << "4. Print item descriptions" << std::endl;
	std::cout << "5. Print map" << std::endl;
	std::cout << std::endl;

	Menu_Range_Int_Prompt("", user_choice, 1, 5);

	return(user_choice);
}

/******************************************************************************************
** Function: print_item_descriptions
** Description: This function prints all of the item descriptions including the name of
** the item, the location of the item, and the special function of the item.
*******************************************************************************************/

void Play_Jail_Escape::print_item_descriptions()
{
	std::cout << std::endl;
	std::cout << "=========================================================================" << std::endl;
	std::cout << "-- Item --                -- Location --           -- Special Function --" << std::endl;
	std::cout << "----------                --------------           ----------------------" << std::endl;
	std::cout << "-- Gun                       Hallway               Can be used to kill --" << std::endl;
	std::cout << "--                        (random drop)            the guard.          --" << std::endl;
	std::cout << "--                                                                     --" << std::endl;
	std::cout << "-- Radio                     Hallway               Shows the location  --" << std::endl;
	std::cout << "--                        (random drop)            of the guard.       --" << std::endl;   
	std::cout << "--                                                                     --" << std::endl;  
	std::cout << "-- Syringe                   Hallway               Increases inmates   --" << std::endl;
	std::cout << "--                        (random drop)            digging speed. Must --" << std::endl;
	std::cout << "--                                                 be adminstered in   --" << std::endl;  
	std::cout << "--                                                 the infirmary.      --" << std::endl;     
	std::cout << "--                                                                     --" << std::endl;
	std::cout << "-- Warden's Mask          Warden's Office          Disguises inmate    --" << std::endl;
	std::cout << "--                                                 so that he cannot   --" << std::endl;   
	std::cout << "--                                                 be caught by guard. --" << std::endl; 
	std::cout << "--                                                                     --" << std::endl;  
	std::cout << "-- Spoon                     Kitchen               Used to dig an      --" << std::endl;  
	std::cout << "--                                                 escape hole in the  --" << std::endl;   
	std::cout << "--                                                 inmate's jail cell. --" << std::endl; 
	std::cout << "--                                                                     --" << std::endl;
	std::cout << "-- Key Card                Prison Yard             Used to gain access --" << std::endl;
	std::cout << "--                                                 to the Warden's     --" << std::endl;
	std::cout << "--                                                 Office.             --" << std::endl;
	std::cout << "=========================================================================" << std::endl;   
	std::cout << std::endl;
}

/******************************************************************************************
** Function: check_if_game_over
** Description: Function that checks the current status of the game. If the player has
** reached the entrance or is done digging the hole in their cell, then the function 
** returns true right away and the player wins the game. If the player ends up in the 
** same space as the guard, the game is over if the player does not have the Wardens Mask
** as a disguise. If the time has run out (6 hours), then the game is over and the player
** loses. 
*******************************************************************************************/

bool Play_Jail_Escape::check_if_game_over()
{
	bool game_over = false;

	//Check if the inmate reached the entrance with the Warden's Mask
	if(inmate->get_location()->get_name() == "Entrance")
	{
		std::cout << std::endl;
		std::cout << "Guard at Entrance: Hey Warden, just checking out?" << std::endl;
		std::cout << "You: Ehm yeah see you tomorrow ..." << std::endl;
		std::cout << " ... " << std::endl;
		std::cout << "You have escaped from Jail!" << std::endl;
		std::cout << std::endl;
		std::cout << "YOU WIN" << std::endl;
		return(true);
	}

	//Check if the inmate has finished digging the hole through his cell
	if(jail_cell->done_digging() == true)
	{
		std::cout << std::endl;
		std::cout << "You have escaped from Jail!" << std::endl;
		std::cout << std::endl;
		std::cout << "YOU WIN" << std::endl;
		return(true);
	}

	//Check if the inmate and guard end up in the same room
	if(check_location(inmate, guard) == true)
	{
		//Guard does not recognize inmate if he has the Warden's Mask
		if(inmate->player_has_item("Warden's Mask"))
		{
			std::cout << std::endl;
			std::cout << "Guard: Warden?! What are you doing here so late ..." << std::endl;
			std::cout << "You: I uh had some work to catch up on" << std::endl;
			std::cout << "Guard: Okay good luck with that. See you around " << std::endl;
			std::cout << std::endl;
			std::cout << "Wow that was a close one ..." << std::endl;
			std::cout << std::endl;

		}

		//Inmate can choose to shoot the guard
		else if(inmate->player_has_item("Gun"))
		{
			bool dead = inmate->kill_guard();

			if(dead)
			{
				game_over = true;

				std::cout << std::endl;
				std::cout << "What did you think no one would hear your gun shot?" << std::endl;
				std::cout << "You've been detained by the other guard's in the prison..." << std::endl;
				std::cout << std::endl;
				std::cout << "GAME OVER" << std::endl;
			}

			else
			{
				std::cout << "You've been caught by the guard ... !" << std::endl;
				std::cout << std::endl;
				std::cout << "GAME OVER" << std::endl;
				std::cout << std::endl;
				game_over = true;
			}
		}

		else
		{
			std::cout << "You've been caught by the guard ... !" << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
			std::cout << std::endl;

			game_over = true;
		}	
	}

	//Prisoner has 6 hours to escape
	if(game_minutes == 360)
	{
		std::cout << "You ran out of time!" << std::endl;
		std::cout << std::endl;
		std::cout << "GAME OVER" << std::endl;
		std::cout << std::endl;

		game_over = true;
	}

	return(game_over);
}

/******************************************************************************************
** Function: print_clock
** Description: Function which prints the game clock to the users screen. 
*******************************************************************************************/

void Play_Jail_Escape::print_clock()
{
	if(game_minutes % 60 == 0)
	{
		if(game_minutes == 0)
		{
			//Do nothing
		}
		else
		{
			starting_hour++;
			minutes = 0;
		}
	}

	if(minutes == 0)
	{
		std::cout << std::endl;
		std::cout << "--------------" << std::endl;
		std::cout << "- Time: "<< starting_hour << ":" << minutes << "0";
		std::cout << " -" << std::endl;
		std::cout << "--------------" << std::endl;
	}

	else
	{
		std::cout << std::endl;
		std::cout << "--------------" << std::endl;
		std::cout << "- Time: "<< starting_hour << ":" << minutes;
		std::cout << " -" << std::endl;
		std::cout << "--------------" << std::endl;
	}
}

/******************************************************************************************
** Function: print_map
** Description: Function which prints a map of the 2-d game board to the user's screen.
*******************************************************************************************/

void Play_Jail_Escape::print_map()
{
	std::cout << std::endl;
	std::cout << "===========================================================================" << std::endl;
	std::cout << "-- Map --                                                                --" << std::endl;
	std::cout << "---------                                                                --" << std::endl;
	std::cout << "--                                                                       --" << std::endl;
	std::cout << "--  -------------                       -------------                    --" << std::endl;
	std::cout << "--  | Entrance  |                       | Warden's  |                    --" << std::endl;
	std::cout << "--  |           |                       | Office    |                    --" << std::endl;
	std::cout << "--  |           |                       |           |                    --" << std::endl;
	std::cout << "--  ----     ----                       ----     ----                    --" << std::endl;
	std::cout << "--      |   |                               |   |                        --" << std::endl;
	std::cout << "--      |   |                               |   |                        --" << std::endl;
	std::cout << "-- -----     -----   ---------------   -----     -----   --------------  --" << std::endl;
	std::cout << "-- | Entrance    |---|  Kitchen    |---| Prison Yard |---| Jail Cell  |  --" << std::endl;
	std::cout << "-- | Hallway                                                Hallway   |  --" << std::endl;
	std::cout << "-- |             |---|             |---|             |---|            |  --" << std::endl;
	std::cout << "-- ---------------   -----     -----   -----     -----   -----     ----  --" << std::endl;
	std::cout << "--                        |   |             |   |             |   |      --" << std::endl;
	std::cout << "--                        |   |             |   |             |   |      --" << std::endl;
	std::cout << "--                   -----     -----   -----     -----   -----      ---- --" << std::endl;
	std::cout << "--                   |  Infirmary  |---| Infirmary   |---|  Jail Cell  | --" << std::endl;
	std::cout << "--                   |                    Hallway                      | --" << std::endl;
	std::cout << "--                   |             |---|             |---|             | --" << std::endl;
	std::cout << "--                   ---------------   ---------------   --------------- --" << std::endl;
	std::cout << "--                                                                       --" << std::endl;
	std::cout << "===========================================================================" << std::endl;
	std::cout << std::endl;
}

/******************************************************************************************
** Destructor: Play_Jail_Escape
** Description: Destroys a Play_Jail_Escape object. Deletes all of the previously 
** dynamically allocated Space objects and the 2 person objects (guard and inmate).
*******************************************************************************************/

Play_Jail_Escape::~Play_Jail_Escape()
{
	//Get rid of dynamically allocated spaces
	delete jail_cell;
	delete hallway1;
	delete hallway2;
  delete hallway3;
  delete yard;	
  delete infirmary;
  delete kitchen;
  delete entrance;
	delete wardens_office;

	//Get rid of dynamically allocated person objects
	delete guard;
	delete inmate;
}