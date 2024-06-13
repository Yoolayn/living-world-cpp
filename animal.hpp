#pragma once
#include "organism.hpp"

class Animal : public Organism
{
  protected:
    Animal(int power, Position position);
    Animal(int power);
    Animal();

  public:
    virtual Action act(Organism &o) override;
    virtual std::optional<std::unique_ptr<Organism>> operator+(Organism &o) override;
    virtual std::optional<std::unique_ptr<Organism>> clone() override;

    virtual ~Animal() override = default;
};
