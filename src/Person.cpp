/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Person class function implementation. This class is the parent class for both
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
#include "Person.hpp"
#include "Space.hpp"

/******************************************************************************************
** Function: get_type
** Description: Returns a string which corresponds to the type that the Person is.
*******************************************************************************************/

std::string Person::get_type()
{
	return(type);
}

/******************************************************************************************
** Function: get_location
** Description: Returns a Space pointer which corresponds to the space that the Person is
** currently in.
*******************************************************************************************/

Space* Person::get_location()
{
	return(current_location);
}

/******************************************************************************************
** Function: set_location
** Description: Takes a space pointer as a parameter and sets the location of the Person
** to that specified space.
*******************************************************************************************/

void Person::set_location(Space* loc)
{
	current_location = loc;
}

/******************************************************************************************
** Function: player_has_item
** Description: Takes a string which represents the item to be searched for and looks 
** through the persons backpack to see if they have the item. Returns true if they do have 
** the item and false otherwise.
*******************************************************************************************/

bool Person::player_has_item(std::string item)
{
	bool has_item = false;

	if(pack.item_in_backpack(item))
	{
		has_item = true;
	}

	else
	{
		has_item = false;
	}

	return(has_item);
}

/******************************************************************************************
** Function: add_item
** Description: Takes an item pointer as a parameter and adds the item that the pointer 
** points to to the Person's backpack.
*******************************************************************************************/

void Person::add_item(Item* player_item)
{
	//Add item pointer to backpack
	pack.add_item(player_item);
}

/******************************************************************************************
** Function: backpack_full
** Description: Returns true if the Person's backpack is at capactiy and false otherwise.
*******************************************************************************************/

bool Person::backpack_full()
{
	if(pack.at_capacity())
	{
		return(true);
	}

	else
	{
		return(false);
	}
}

/******************************************************************************************
** Function: delete_backpack_item
** Description: Prompts the user to delete a specific backpack item from the Person's 
** backpack.
*******************************************************************************************/

void Person::delete_backpack_item()
{
	int user_delete_choice;
	int items_in_pack = pack.print_list();

	std::cout << std::endl;
	std::cout << "Enter the number of the item you would like to delete." << std::endl;
	std::cout << std::endl;

	Menu_Range_Int_Prompt("", user_delete_choice, 1, items_in_pack);

	pack.delete_item(user_delete_choice);
}

/******************************************************************************************
** Function: delete_specific_item
** Description: Takes in a string which represents the type of the item to delete, and 
** deletes that item from the person's backpack if it exists.
*******************************************************************************************/

void Person::delete_specific_item(std::string str)
{
	pack.delete_specific_item(str);
}

/******************************************************************************************
** Function: is_under_influence
** Description: Returns true if a Person is under the influence and false otherwise.
*******************************************************************************************/

bool Person::is_under_influence()
{
	return(under_influence);
}

/******************************************************************************************
** Function: use_syringe
** Description: Function which increases the dig_speed of a Person to 6, and sets the 
** boolean member variable under_influence to true.
*******************************************************************************************/

void Person::use_syringe()
{
	//If the player uses the PCP syringe, dig speed increases 6 fold
	dig_speed = 6;
	under_influence = true;
}

/******************************************************************************************
** Function: get_dig_speed
** Description: Returns the current dig_speed of the Person.
*******************************************************************************************/

int Person::get_dig_speed()
{
	return(dig_speed);
}

/******************************************************************************************
** Function: print_backpack_contents
** Description: Function which prints out the current contents of the Person's backpack.
*******************************************************************************************/

void Person::print_backpack_contents()
{
	pack.print_list();
}

/******************************************************************************************
** Function: kill_guard
** Description: This function will be overriden by a function in the inmate class.
*******************************************************************************************/

bool Person::kill_guard()
{


}

/******************************************************************************************
** Destructor: Person
** Description: Destroys a Person object.
*******************************************************************************************/

Person::~Person()
{

	
}

