// quadtree.cpp
#include "quadtree.h"
#include <iostream>
#include <string>

using namespace QT;
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

void quadtree::add_entity()
{
	return;
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
		last = last + "leaf: " + std::to_string(child0->isleaf());
	if (child1 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(child1->isleaf());
	if (child2 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(child2->isleaf());
	if (child3 == NULL)
		last = last + "NULL\n";
	else
		last = last + "leaf: " + std::to_string(child3->isleaf());

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