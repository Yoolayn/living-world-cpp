#pragma once
#include "organism.h"

class Animal : public Organism
{
public:
    Animal(int power, Position position);
    Animal();
};
