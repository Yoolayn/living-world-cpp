#pragma once
#include "animal.hpp"

class Wolf : public Animal
{
  private:
    int m_Lifetime;

  public:
    Wolf();
    Wolf(int power);
    Wolf(int power, Position position);

    Action act(Organism &o) override;
    std::optional<std::unique_ptr<Organism>> operator+(Organism &o) override;
    void move(int x, int y) override;
    void move(Position p) override;
};
