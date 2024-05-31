#pragma once
#include "organism.hpp"

class Plant : public Organism
{
public:
    Plant(int power, Position position);
    Plant();

    void move(int dx, int dy);
};
