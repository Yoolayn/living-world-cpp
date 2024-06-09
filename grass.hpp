#pragma once
#include "plant.hpp"

class Grass : public Plant
{
  public:
    Grass(Position position);
    Grass();

    std::optional<Organism> clone();
};
