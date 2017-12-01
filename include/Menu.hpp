/***************************************************************************************
** Thad Sauter
** 10/8/17
** Description: Menu function header file.
****************************************************************************************/
#ifndef MENU_CLASS_HPP
#define MENU_CLASS_HPP
#include <iostream>
#include <string>
#include "Utility_Functions.hpp"

void Make_Menu_Option(std::string, int);
void Menu_Pos_Int_Prompt(std::string, int &);
void Menu_Range_Int_Prompt(std::string prompt, int &, int, int);

#endif
