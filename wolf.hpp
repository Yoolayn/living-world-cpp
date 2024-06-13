#pragma once
#include "animal.hpp"

class Wolf : public Animal
{
  public:
    Wolf();
    Wolf(int power);
    Wolf(int power, Position position);

    Action act(Organism &o);
    std::optional<Organism> operator+(Organism o);
};
