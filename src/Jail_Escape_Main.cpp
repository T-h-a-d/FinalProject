/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Main function for the Jail Escape game. This function prints the title of
** the game, the backstory, the objective, how to beat the game, and some game hints, and
** then creates a Jail_Escape_Game object to play the game. After the user is finished 
** playing the game, the user is asked if they would like to play again or exit. The game
** will keep playing as long as the user chooses to play again.
**
** ### Use ./JailEscape to run ###
*******************************************************************************************/
#include "Play_Jail_Escape.hpp"
#include <iostream>


int main()
{
	std::srand(time(0)); //Starts a seed using the computers internal clock 
	bool exit_game = false;
	int user_choice;

	do
	{
		//Print the title screen
		std::cout << std::endl;
		std::cout << "=========================================================================" << std::endl;
		std::cout << "--                                                                     --" << std::endl;
		std::cout << "--                    	WELCOME TO JAIL ESCAPE                         --" << std::endl;
		std::cout << "--                                                                     --" << std::endl;
		std::cout << "=========================================================================" << std::endl;
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "=========================================================================" << std::endl;
		std::cout << "-- Backstory --                                                        --" << std::endl;
		std::cout << "---------------                                                        --" << std::endl;
		std::cout << "-- You are an inmate at a maximum-security prison. It is the middle of --" << std::endl;
		std::cout << "-- the night and your jail cell mysteriously opens. You peek out into  --" << std::endl;
		std::cout << "-- the hallway and see that everyone else is asleep. The guard is      --" << std::endl;
		std::cout << "-- nowhere to be seen ...                                              --" << std::endl;
		std::cout << "=========================================================================" << std::endl;

		std::cout << std::endl;
		std::cout << "Press enter to continue ...";
		std::cin.ignore();

		std::cout << std::endl;
		std::cout << "=========================================================================" << std::endl;
		std::cout << "-- Objective --                                                        --" << std::endl;
		std::cout << "---------------                                                        --" << std::endl;
		std::cout << "-- To escape, you must use the items you find scattered throughout the --" << std::endl;
		std::cout << "-- penitentiary. You only have 7 hours before the sun comes up and     --" << std::endl;
		std::cout << "-- each turn costs you 10 minutes. You better move fast!               --" << std::endl;
		std::cout << "=========================================================================" << std::endl;

		std::cout << std::endl;
		std::cout << "Press enter to continue ...";
		std::cin.ignore();

		std::cout << std::endl;
		std::cout << "=========================================================================" << std::endl;
		std::cout << "-- How to Escape --                                                    --" << std::endl;
		std::cout << "-------------------                                                    --" << std::endl;
		std::cout << "-- There are 2 different ways to escape. The inmate can either find    --" << std::endl;
		std::cout << "-- the Warden's Mask and escape through the Entrance, or the inmate    --" << std::endl;
		std::cout << "-- can find the spoon and use it to dig a hole in their cell. Either   --" << std::endl;
		std::cout << "-- way, you must avoid the patrolling guard! If he catches you, then   --" << std::endl;
		std::cout << "-- you automatically lose the game!                                    --" << std::endl;
		std::cout << "--                                                                     --" << std::endl;
		std::cout << "-- Hint: Certain items you collect will give you special abilities.    --" << std::endl;
		std::cout << "-- Choose the items you collect wisely because you can only carry 3    --" << std::endl;
		std::cout << "-- items at a time. Once you drop an item it is gone for good!         --" << std::endl;
		std::cout << "--                                                                     --" << std::endl;
		std::cout << "-- Note: Action options from the menu take time and allow the guard to --" << std::endl;
		std::cout << "-- move while the Help options from the menu do not! If you get stuck, --" << std::endl;
		std::cout << "-- use the Help options!                                               --" << std::endl;
		std::cout << "--                                                                     --" << std::endl;
		std::cout << "--                           GOOD LUCK!                                --" << std::endl;
		std::cout << "=========================================================================" << std::endl;

		std::cout << std::endl;
		std::cout << "Press enter to start game ...";
		std::cin.ignore();


		Play_Jail_Escape play_game;

		play_game.start_game();

		std::cout << std::endl;
		std::cout << "Would you like to play Jail Escape again?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		std::cout << std::endl;

		Menu_Range_Int_Prompt("", user_choice, 1, 2);

		switch(user_choice)
		{
			case 1:
			{
				exit_game = false;
			}

			case 2:
			{
				exit_game = true;
			}
		}

	}
	while(!exit_game)
}