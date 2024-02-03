
// entity2D.h
#pragma once
#include <string>
namespace ETwo
{
    class entity2D
    {
    public:
        entity2D(int, int, int);
        int xpos;
        int ypos;
        int radius;
        std::string to_string();
    };

}