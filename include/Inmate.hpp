/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Inmate class. This class is derived from the Person class
** and inherits all of its member variables and functions. This class also has a constructor
** as well as a function to kill the guard.
*******************************************************************************************/
#ifndef INMATE_HPP
#define INMATE_HPP
#include "Person.hpp"

class Inmate : public Person
{

private:

public:
	Inmate();
	bool kill_guard();

};
#endif