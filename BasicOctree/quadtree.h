// quadtree.h
#pragma once
#include <string>
#include <vector>
#include "entity2D.h"

class quadtree
{
public:
	void hello_world();
	bool add_entity(entity2D ent);
		
	std::string to_string();
	std::string to_json();
		
	bool isleaf();
	int get_radius();
	std::vector<int> get_origin();
	entity2D* get_data();
	quadtree* get_child(int num);

	void set_data(entity2D ent);
	entity2D* pop_data();

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
	quadtree* new_subtree(int quad);

};