/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Play_Jail_Escape.hpp"


int main()
{
	std::srand(time(0)); //Starts a seed using the computers internal clock 

	//Print the title screen
	std::cout << std::endl;
	std::cout << "=========================================================================" << std::endl;
	std::cout << "--                                                                     --" << std::endl;
	std::cout << "--                			WELCOME TO JAIL ESCAPE                         --" << std::endl;
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
	std::cout << "=========================================================================" << std::endl;
	std::cout << "-- Objective --                                                        --" << std::endl;
	std::cout << "---------------                                                        --" << std::endl;
	std::cout << "-- To escape, you must use the items you find scattered throughout the --" << std::endl;
	std::cout << "-- penitentiary. You only have 7 hours before the sun comes up and     --" << std::endl;
	std::cout << "-- each turn costs you 10 minutes. You better move fast!               --" << std::endl;
	std::cout << "=========================================================================" << std::endl;



	Play_Jail_Escape play_game;

	play_game.start_game();

}