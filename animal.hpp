#pragma once
#include "organism.hpp"

class Animal : public Organism
{
  public:
    Animal(int power, Position position);
    Animal(int power);
    Animal();

    virtual Action act(Organism o) override;
    virtual std::optional<std::unique_ptr<Organism>> operator+(Organism *o) override;
    virtual std::optional<std::unique_ptr<Organism>> clone() override;

    virtual ~Animal() override = default;
};
