#pragma once
#include "plant.hpp"
#include <memory>

class Grass : public Plant
{
  public:
    Grass(Position position);
    Grass();

    std::optional<std::unique_ptr<Organism>> clone() override;
};
