#pragma once
#include "organism.hpp"

class Animal : public Organism
{
  public:
    Animal(int power, Position position);
    Animal(int power);
    Animal();

    Action act(Organism o);
    // Animal operator+(Animal o);
    std::optional<Organism> operator+(Organism o);
    std::optional<Organism> clone();
};
