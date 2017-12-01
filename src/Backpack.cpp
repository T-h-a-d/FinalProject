/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Backpack.hpp"


/******************************************************************************************
** Constructor: Backpack
** Description: Constructs a backpack object. Initializes the head and tail node 
** pointers to nullptr.
*******************************************************************************************/

Backpack::Backpack()
{
	head = nullptr;
	tail = nullptr;
	num_tools = 0;
}

/******************************************************************************************
** Function: is_empty
** Description: 
*******************************************************************************************/

bool Backpack::is_empty()
{
	if(head == nullptr && tail == nullptr)
	{
		return(true);
	}

	else
	{
		return(false);
	}
}

/******************************************************************************************
** Function: add_node_to_head
** Description: This function takes in an int team and Character pointer as parameters.
** If a list has no entries yet, the team number and Character pointer are added to the head
** node (also the tail node). Otherwise, the team number and Character pointer is added
** to the newly created node at the front of the list.
*******************************************************************************************/

void Backpack::add_item(Item* t)
{
	if(head == nullptr)
	{
		//Create new node that head and tail both point at (only one node in list)
		head = new Node;
		tail = head;

		//Put the item in the backpack
		head->tool = t;

		//Only one node in list, so next and prev point at nothing
		head->next = nullptr;
		head->prev = nullptr;
	}

	else
	{
		//Create new node 
		Node* nodePtr = new Node;

		//Set value of node
		nodePtr->tool = t;

		//Connect the nodes
		head->prev = nodePtr;
		nodePtr->next = head;
		nodePtr->prev = nullptr;

		//Head points at new head
		head = nodePtr;
	}

	//Increment the number of tools in the backpack
	num_tools++;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Backpack::delete_item(int t)
{
	//Keep track of node to be deleted
	Node* garbage = head;

	//Go to the item specified for deletion
	for(int i = 1; i < t; i++)
	{
		garbage = garbage->next;
	}

	//If the item to delete is at the front
	if(garbage == head)
	{
		//If there is only one item in the list
		if(garbage->next == nullptr && garbage->prev == nullptr)
		{
			delete garbage;

			head = nullptr;
			tail = nullptr;
		}

		else
		{
			head = garbage->next;
			head->prev = nullptr;

			delete garbage;
		}	
	}

	//If the item to delete is at the front
	else if(garbage == tail)
	{
		//If there is only one item in the list
		if(garbage->next == nullptr && garbage->prev == nullptr)
		{
			delete garbage;

			head = nullptr;
			tail = nullptr;
		}

		else
		{
			tail = garbage->prev;
			tail->next = nullptr;

			delete garbage;
		}	
	}

	//Else the item must be in the middle
	else
	{
		garbage->next->prev = head;
		garbage->prev->next = tail;

		delete garbage;
	}
}

/******************************************************************************************
** Function: print_list
** Description: Loops through all of the node objects in the list and prints out their 
** respective values to the screen. Starts with the head of the list and makes its way to
** the tail of the list.
*******************************************************************************************/

void Backpack::print_list()
{
	//Print out items in backpack
	int i = 1;

	if(head == nullptr && tail == nullptr)
	{
		std::cout << "There are no tools currently in your backpack" << std::endl;
	}

	else
	{
		Node* print_node = head;

		std::cout << std::endl;
		std::cout << "--------------------- Backpack ----------------------- ";
		std::cout << std::endl;
		
		//Loop through list
		while(print_node)
		{
			std::cout << i << ". " << print_node->tool->get_type() << std::endl;
			print_node = print_node->next;
			i++;
		}
		std::cout << std::endl;
	}
}


/******************************************************************************************
** Function: at_capacity
** Description: 
*******************************************************************************************/

bool Backpack::at_capacity()
{	
	if(num_tools == 3)
	{
		return(true);
	}

	else
	{
		return(false);
	}
}


bool Backpack::item_in_backpack(std::string item_type)
{
	bool item = false;

	Node* findItem = head;

	while(findItem)
	{
		if(findItem->tool->get_type() == item_type)
		{
			item = true;
		}

		//Move to next item in backpack
		findItem = findItem->next;
	}

	return(item);
}

/******************************************************************************************
** Destructor: Backpack
** Description: Destroys all of the node objects in the Backpack. Starts at the head,
** and then loops through each node in the list, deleting them one by one. At the end,
** the head and tail pointers are reset to nullptr.
*******************************************************************************************/

Backpack::~Backpack()
{
	Node* nodePtr = head;

	//Loop through the linked list
	while(nodePtr)
	{
		//Keep track of node to be deleted
		Node* garbage = nodePtr;

		//Move onto next node if it exists
		nodePtr = nodePtr->next;

		//Delete character
		delete garbage->tool;

		//Delete node
		delete garbage;
	}

	head = nullptr;
	tail = nullptr;
}