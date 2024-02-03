// BasicOctree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "my_class.h"
#include "octree.h"
#include "quadtree.h"
#include "entity2D.h"

void add_random_ent(quadtree *tree);

int main()
{
    std::cout << "Hello World!\n\n";
    
    // my_class mc;
    // mc.do_something();

    //octree tree;
    //tree.hello_world();

    //quadtree qtree;
    quadtree qtree(500, 500, 500); // 0 to 1000

    entity2D alpha(40, 70, 2);
    entity2D betah(40, 71, 2);
    qtree.add_entity(alpha);
    bool last = qtree.add_entity(betah);
    if (not last)
        std::cout << "failed to add " << betah.to_json() << " to tree..." << std::endl;
    for (int i = 0; i < 10; i++)
    {
        //add_random_ent(&qtree);
    }

    std::cout << std::endl << qtree.to_json() << std::endl;

    std::cout << "\n\n\n\n";
}

void add_random_ent(quadtree *qtree)
{
    int rx = rand() % 1000;
    int ry = rand() % 1000;
    entity2D* ent = new entity2D(rx, ry, 1);
    std::cout << "adding " << ent->to_json() << " to tree..." << std::endl;
    bool last = qtree->add_entity(*ent);
    if (not last)
    {
        std::cout << "failed to add " << ent->to_json() << " to tree..." << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
