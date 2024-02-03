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

// Completely blank constructor
quadtree::quadtree()
{
	children = vector<quadtree*>(4);
	data = NULL;
	leaf = false;

	xpos = 0;
	ypos = 0;
	radius = 0;
}

quadtree::quadtree(int x0, int y0, int radius0)
{
	// cout << "making a new quadtree with some initial values" << endl;
	children = vector<quadtree*>(4);
	data = NULL;
	leaf = false;

	xpos = x0;
	ypos = y0;
	radius = radius0;

	// quadtree(); // can I pull the children and the leaf out and just call this?
}

// This constructor is used when creating a new leaf
quadtree::quadtree(int x0, int y0, int rad, entity2D ent)
{
	children = vector<quadtree*>(4);
	data = &ent;
	leaf = true;

	xpos = x0;
	ypos = y0;
	radius = rad;
}

quadtree::~quadtree()
{
	cout << "destroying!" << xpos << ypos << radius << endl;
}

// sanity check
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
	// what if point already exists?
	// cout << ent.to_string() << endl;

	// figure out in what quadrant the child should go
	int quad = get_quadrant(ent);
	quadtree** quad_ptr = &children[quad]; // pointer to child pointer

	// case 1: the entity goes in a spot that is currently empty
	if (*quad_ptr == nullptr)
	{
		// create a new tree aka leaf
		// TODO: validate all this integer math. Its proobably close enough
		int x_shift[] = { 1, 1, -1, -1 };
		int dx = xpos + (radius / 2) * x_shift[quad];

		int y_shift[] = { 1, -1, -1, 1 };
		int dy = ypos + (radius / 2) * y_shift[quad];

		quadtree new_leaf = quadtree(dx, dy, radius/2, ent);
		*quad_ptr = &new_leaf;
		return;
	}

	// case 2: the entity goes in a spot that has a child tree already
	// aka points to subtree with leaf == false
	if ((**quad_ptr).isleaf() == false)
	{
		// just move down the tree
		(**quad_ptr).add_entity(ent);
		return;
	}
	 
	// case 3: the entity goes in a spot that has an entity already
	// aka points to subtree with leaf == true
	if ((**quad_ptr).isleaf() == true)
	{
		// need to make space
	}
	
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
	
	for (int i = 0; i < 4; i++)
	{
		if (children[i] == NULL)
			last = last + "NULL\n";
		else
			last = last + "leaf: " + std::to_string((children[i])->isleaf());
	}

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
	std::string last = "{";
	last = last + "\"x\": " + std::to_string(xpos) + ",";
	last = last + "\"y\": " + std::to_string(ypos) + ",";
	last = last + "\"r\": " + std::to_string(radius) + ",";
	last = last + "\"leaf\": ";
	if (leaf)
	{
		last = last + "true,";
		last = last + "\"data\": " + data->to_json() + ",";
	}
	else
	{
		last = last + "false,";
		last = last + "\"data\": NULL,";
	}
	for (int i = 0; i < 4; i++) {
		// recursive part
		if (i >= children.size())
		{
			last = last + "\"child\": ERROR,";
		}
		else if (children[i] != nullptr)
		{
			last = last + (*children[i]).to_json();
		}
	}

	std::string closers = "}\n";
	return last + closers;
}