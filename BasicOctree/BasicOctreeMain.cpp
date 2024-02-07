// BasicOctree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "octree.h"
#include "quadtree.h"
#include "entity2D.h"
#include "ray.h"

void batch_add_random_ent(quadtree* qtree, int count);
bool add_random_ent(quadtree *tree);

int main()
{
    std::cout << "Hello World!\n\n";

    //octree tree;
    //tree.hello_world();

    //quadtree qtree;
    quadtree qtree(512, 512, 512); // 0 to 1024
    // theres some edge cases where small boxes can fail to correctly hold an object
    //   by having their children miss certain coordinates
    // I think the solution is to either change the coords to floats
    //   or drop the radius system for an extent system
    // sticking to multiples of 2 should kick the can for a bit

    entity2D alpha(500, 500, 2);
    //entity2D betah(128, 128, 2);
    qtree.add_entity(alpha);
    //bool last = qtree.add_entity(betah);
    //if (not last)
    //    std::cout << "failed to add " << betah.to_json() << " to tree..." << std::endl;

    // batch add
    // batch_add_random_ent(&qtree, 500);

    // std::cout << std::endl << qtree.to_json() << std::endl;

    ray* ree = new ray();
    ray* gee = new ray(500, 500, -1000, 0, 0, 1);

    entity2D* last;
    last = gee->intersects_quadtree(&qtree);
    
    std::cout << "\n\n\n\n";
}

void batch_add_random_ent(quadtree *qtree, int count)
{
    int fails = 0;
    bool last = true;
    for (int i = 0; i < count; i++)
    {
        last = add_random_ent(qtree);
        if (not last)
            fails = fails + 1;
    }
    std::cout << "Failed to add " << fails << " objects." << std::endl;
}

bool add_random_ent(quadtree *qtree)
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
    return last;
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
