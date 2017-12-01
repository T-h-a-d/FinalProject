/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Backpack class. This class is a linked-list like 
** data structure that is used to hold Item objects.
*******************************************************************************************/
#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include "Item.hpp"
#include "Guard_Radio.hpp"
#include "Gun.hpp"
#include "Spoon.hpp"

class Backpack
{
private:
	struct Node
	{
		Node* next;
		Node* prev;
		Item* tool;
	};

	Node* head;
	Node* tail;
	int num_tools;

public:
	Backpack();
	bool is_empty();
	void add_item(Item*);
	int print_list();
	void delete_item(int);
	bool at_capacity();
	bool item_in_backpack(std::string);
	void delete_specific_item(std::string);
	~Backpack();
};
#endif