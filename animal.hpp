#pragma once
#include "organism.hpp"

class Animal : public Organism
{
public:
    Animal(int power, Position position);
    Animal();
};
