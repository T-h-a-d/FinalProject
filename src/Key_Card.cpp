/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Key_Card class. This class is
** derived from the Item class and inherits all of its member variables and functions. This
** class also contains a constructor which initializes the type of the item.
*******************************************************************************************/
#include "Key_Card.hpp"

/******************************************************************************************
** Constructor: Key_Card
** Description: Constructs a Key_Card object. Initializes the name of the item to 
** "Key Card".
*******************************************************************************************/

Key_Card::Key_Card()
{
	type = "Key Card";
}

