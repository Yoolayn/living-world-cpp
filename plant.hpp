#pragma once
#include "organism.hpp"
#include <memory>

class Plant : public Organism
{
  public:
    Plant(Position position);
    Plant();

    std::optional<std::unique_ptr<Organism>> clone() override;
    void move(Position p) override;
    void move(int x, int y) override;
};
