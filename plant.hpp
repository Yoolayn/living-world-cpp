#pragma once
#include "organism.hpp"
#include <memory>

class Plant : public Organism
{
  protected:
    Plant(Position position);
    Plant();

  public:
    std::optional<std::unique_ptr<Organism>> clone() override;
    void move(Position p) override;
    void move(int x, int y) override;
    Action act(Organism &o) override;
};
