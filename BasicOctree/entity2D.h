// entity2D.h
#pragma once
#include <string>

class entity2D
{
public:
    entity2D();
    entity2D(int, int, int);
    int xpos;
    int ypos;
    int radius;
    std::string to_string();
    std::string to_json();
};