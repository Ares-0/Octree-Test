// entity2D.cpp
// Standin for an object that could be put into a quadtree.
// It mostly just stores a position for placement in the tree 
//   and a radius that I thought would be for the final intersection
// An Entity3D would just have the extra position dimension.
#include "entity2D.h"
#include <iostream>
#include <string>

using namespace std;

// Blank constructor
entity2D::entity2D()
{
	xpos = 0;
	ypos = 0;
	radius = 0;
}

// Specific constructor
entity2D::entity2D(int x0, int y0, int radius0)
{
	xpos = x0;
	ypos = y0;
	radius = radius0;
}

// return a new copy of self
// I feel like its easy to lose track of this copy on the heap, have to make sure
entity2D* entity2D::copy()
{
	entity2D* new_copy = new entity2D(xpos, ypos, radius);
	return new_copy;
}

std::string entity2D::to_string()
{
	string last = "Entity 2D: \n";
	last = last + "(x, y) = (" + std::to_string(xpos) + ", " + std::to_string(ypos) + ")\n";
	last = last + "r: " + std::to_string(radius) + "\n";
	return last;
}

// Returns a json representation of the entity that is used to fill the json of
//   the enclosing tree
// 
// return: string
std::string entity2D::to_json()
{
	string last = "{";
	last = last + "\"x\": " + std::to_string(xpos) + ",";
	last = last + "\"y\": " + std::to_string(ypos) + ",";
	last = last + "\"r\": " + std::to_string(radius) + ",";
	string closer = "}";
	return last + closer;
}