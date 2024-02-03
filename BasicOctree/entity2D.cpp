// entity2D.cpp
#include "entity2D.h" // header in local directory
#include <iostream> // header in standard library
#include <string>

using namespace std;

entity2D::entity2D()
{
	xpos = 0;
	ypos = 0;
	radius = 0;
}

entity2D::entity2D(int x0, int y0, int radius0)
{
	xpos = x0;
	ypos = y0;
	radius = radius0;
}

// return a new copy of self
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

std::string entity2D::to_json()
{
	string last = "{";
	last = last + "\"x\": " + std::to_string(xpos) + ",";
	last = last + "\"y\": " + std::to_string(ypos) + ",";
	last = last + "\"r\": " + std::to_string(radius) + ",";
	string closer = "}";
	return last + closer;
}