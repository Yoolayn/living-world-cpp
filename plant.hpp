#pragma once
#include "organism.hpp"

class Plant : public Organism
{
  public:
    Plant(Position position);
    Plant();

    virtual std::optional<Organism> clone();
    void move(int dx, int dy);
};
