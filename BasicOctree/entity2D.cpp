// entity2D.cpp
#include "entity2D.h" // header in local directory
#include <iostream> // header in standard library
#include <string>

using namespace ETwo;
using namespace std;

entity2D::entity2D(int x0, int y0, int radius0)
{
	xpos = x0;
	ypos = y0;
	radius = radius0;
}

std::string entity2D::to_string()
{
	string last = "Entity 2D: \n";
	last = last + "(x, y) = (" + std::to_string(xpos) + ", " + std::to_string(ypos) + ")\n";
	last = last + "r: " + std::to_string(radius) + "\n";
	return last;
}