#pragma once
#include "organism.hpp"

class Plant : public Organism
{
  public:
    Plant(int power, Position position);
    Plant(int power);
    Plant();

    std::optional<Organism> clone();
    void move(int dx, int dy);
};
