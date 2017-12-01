/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef INMATE_HPP
#define INMATE_HPP
#include "Person.hpp"

class Inmate : public Person
{

private:

public:
	Inmate();
	void kill_guard();

};
#endif