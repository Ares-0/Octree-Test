// quadtree.h
#pragma once
#include <string>
namespace QT
{
	class quadtree
	{
	public:
		void hello_world();
		void add_entity();
		
		std::string to_string();
		std::string to_json();
		
		bool isleaf();

		quadtree();
		quadtree(int x0, int y0, int radius0);
	private:
		quadtree* child0; // Northeast child
		quadtree* child1; // Southeast child
		quadtree* child2; // Southwest child
		quadtree* child3; // Northwest child

		int xpos, ypos; // coordinates
		int radius; // size of square

		bool leaf; // if leaf or not
	};
}