// quadtree.h
#pragma once
#include <string>
#include <vector>
#include "entity2D.h"

class quadtree
{
public:
	void hello_world();
	void add_entity(entity2D ent);
		
	std::string to_string();
	std::string to_json();
		
	bool isleaf();

	quadtree();
	quadtree(int x0, int y0, int radius0);
	quadtree(int x0, int y0, int rad, entity2D ent);
	~quadtree();
private:
	std::vector<quadtree*> children;
	entity2D* data;
	bool leaf; // if leaf or not. iff true, data has value

	int xpos, ypos; // coordinates
	int radius; // size of square

	int get_quadrant(entity2D);
};