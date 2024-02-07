// BasicOctree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "octree.h"
#include "quadtree.h"
#include "entity2D.h"
#include "ray.h"

void batch_random_rays(quadtree* qtree, int count);
bool random_ray(quadtree* qtree);
void batch_add_random_ent(quadtree* qtree, int count);
bool add_random_ent(quadtree *tree);

int main()
{
    std::cout << "Hello World!\n\n";
    srand(static_cast <unsigned> (time(0)));

    quadtree qtree(512, 512, 512); // 0 to 1024
    // theres some edge cases where small boxes can fail to correctly hold an object
    //   by having their children miss certain coordinates
    // I think the solution is to either change the coords to floats
    //   or drop the radius system for an extent system
    // sticking to multiples of 2 should kick the can for a bit

    // Add one object
    //entity2D alpha(500, 500, 2);
    //qtree.add_entity(alpha);

    // TEST: two points super close together, this can still fail for some points
    //entity2D alpha(500, 500, 2);
    //entity2D betah(501, 500, 2);
    //qtree.add_entity(alpha);
    //qtree.add_entity(betah);
    //std::cout << std::endl << qtree.to_json() << std::endl;

    // TEST: force a ray to hit an object
    // entity2D alpha(500, 500, 2);
    // entity2D alpha(700, 700, 2); // or miss
    //ray* gee = new ray(500, 500, -1000, 0, 0, 1);
    //entity2D* last = gee->intersects_quadtree(&qtree);
    //if (last != nullptr)
    //   std::cout << last->to_string();
 
    // Main test: batch add objects, shoot a bunch of rays, print the results
    batch_add_random_ent(&qtree, 100000);
    // std::cout << std::endl << qtree.to_json() << std::endl; // warning: big
    batch_random_rays(&qtree, 1000); // 10k rays takes about 4 seconds

    std::cout << "\n\n\n\n";
}


void batch_random_rays(quadtree* qtree, int count)
{
    std::cout << "Firing " << count << " rays...\n";
    int misses = 0;
    for (int i = 0; i < count; i++)
    {
        if (not random_ray(qtree))
            misses = misses + 1;
    }
    std::cout << "\n" << misses << " rays hit nothing.\n";
}

bool random_ray(quadtree* qtree)
{
    int rx = rand() % 1000;
    int ry = rand() % 1000;
    float dx = (rand() % 100) - 5;
    float dy = (rand() % 100) - 5;
    // std::cout << dx << " " << dy << "\n";
    ray* ree = new ray(rx, ry, -513, dx, dy, 10);
    entity2D* last = ree->intersects_quadtree(qtree);
    
    if (last != NULL)
    {
        std::cout << "Ray " << ree->to_string() << " \thits: ";
        std::cout << last->to_json() << std::endl;
        return true;
    }
    else
        return false;
}

void batch_add_random_ent(quadtree *qtree, int count)
{
    std::cout << "Adding " << count << " objects to tree...\n";
    int fails = 0;
    bool last = true;
    for (int i = 0; i < count; i++)
    {
        last = add_random_ent(qtree);
        if (not last)
            fails = fails + 1;
    }
    std::cout << "Failed to add " << fails << " objects.\n\n";
}

bool add_random_ent(quadtree *qtree)
{
    int rx = rand() % 1000;
    int ry = rand() % 1000;
    entity2D* ent = new entity2D(rx, ry, 1);
    // std::cout << "adding " << ent->to_json() << " to tree..." << std::endl;
    bool last = qtree->add_entity(*ent);
    if (not last)
    {
        std::cout << "failed to add " << ent->to_json() << " to tree...\n";
    }
    return last;
}
