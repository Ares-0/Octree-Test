// quadtree.cpp
// 
// assumptions / standards: 
// quadrants are numbered clockwise, with 0 being North East of the origin
// For some reason I'm assuming coordinates 0,0 as the bottom left corner, if that ever comes up
#include "quadtree.h"
#include "entity2D.h"
#include <iostream>
#include <string>

using namespace std;


quadtree::quadtree()
{
	cout << "constructing new quadtree" << endl;
	child0 = NULL;
	child1 = NULL;
	child2 = NULL;
	child3 = NULL;

	xpos = 0;
	ypos = 0;
	radius = 0;

	leaf = true;
}

quadtree::quadtree(int x0, int y0, int radius0)
{
	cout << "making a new quadtree with some initial values" << endl;
	child0 = NULL;
	child1 = NULL;
	child2 = NULL;
	child3 = NULL;

	xpos = x0;
	ypos = y0;
	radius = radius0;

	leaf = true;
	// quadtree(); // can I pull the children and the leaf out and just call this?
}

void quadtree::hello_world()
{
	cout << "Hello, world! Quadtree here" << endl;
}

bool quadtree::isleaf()
{
	return leaf;
}

// Add an entity to the tree where appropriate
// Rebalance tree if need be
void quadtree::add_entity(entity2D ent)
{
	cout << ent.to_string() << endl;

	// figure out what child to potentially look at
	int quad = get_quadrant(ent);
	void* quad_ptr = nullptr;
	if (quad == 0)
		quad_ptr = child0;
	if (quad == 1)
		quad_ptr = child1;
	if (quad == 2)
		quad_ptr = child2;
	if (quad == 3)
		quad_ptr = child3;

	// case 1: the entity goes in a spot that is currently empty
	if (quad_ptr == nullptr)
	{
		quad_ptr = &ent;
	}
	// case 2: the entity goes in a spot that has a child tree already
	// case 3: the entity goes in a spot that has an entity already
	return;
}

// Determine the quadrant in which an entity should belong
// represented as an integer (0,3)
//
// ent: entity to check coordinates of
// return: int, quandrant number
int quadtree::get_quadrant(entity2D ent)
{
	// include radius error check?
	// if distance_to ent.origin > radius
	//     throw error???

	// should just be some simple position checks
	// If the coords are exactly the same, tie goes to quadrant further from origin
	// 3 | 0
	// -   -
	// 2 | 1
	// origin is bottom left (towards 2)
	// theres a clever one liner in here somewhere but maybe later

	if (ent.xpos >= xpos)
	{
		// 0 or 1
		if (ent.ypos >= ypos)
			return 0;
		else
			return 1;
	}
	else
	{
		// 2 or 3
		if (ent.ypos >= ypos)
			return 3;
		else
			return 2;
	}
	// code should never reach here
}

// Output a string representation of the tree
// This is really just for quick and dirty status checks
//   and will NOT recursively include the children
//
// return: string, human readable
std::string quadtree::to_string()
{
	string last = "This is a quadtree:\n";
	last = last + "(x, y): " + std::to_string(xpos) + ", " + std::to_string(ypos) + "\n";
	last = last + "radius: " + std::to_string(radius) + "\n";
	last = last + "leaf: " + std::to_string(leaf) + "\n";
	last = last + "\nchildren:\n";
	
	if (child0 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(((quadtree*)child0)->isleaf());
	if (child1 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(((quadtree*)child1)->isleaf());
	if (child2 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(((quadtree*)child2)->isleaf());
	if (child3 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(((quadtree*)child3)->isleaf());

	return last;
}

// Output a json representation of the tree
// This will (should) include the children recursively
// Slightly less quick slightly less dirty status checks
// Note: dont bother with whitespace stuff, Ill just copy paste it 
//   somewhere else that clean it up if I really need to
//
// return: string, json formatted
std::string quadtree::to_json()
{
	return "";
}