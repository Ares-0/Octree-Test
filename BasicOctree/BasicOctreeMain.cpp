// BasicOctree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "my_class.h"
#include "octree.h"
#include "quadtree.h"
#include "entity2D.h"

// surely this is awful practice
using namespace N;
using namespace OT;
using namespace QT;
using namespace ETwo;

int main()
{
    std::cout << "Hello World!\n";
    
    //my_class mc;
    //mc.do_something();

    //octree tree;
    //tree.hello_world();

    //quadtree qtree;
    quadtree qtree(5, 5, 5);
    qtree.hello_world();
    std::cout << qtree.to_string();

    std::cout << "\n\n\n\n";

    // entity2D alpha(1, 2, 3);
    // std::cout << alpha.to_string();
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