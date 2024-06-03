#pragma once
#include "position.hpp"
#include <ostream>
#include <string>

enum Species { plant, animal, organism };

std::string to_string(Species);

class Organism
{
  private:
    int power_;
    Position position_;
    Species species_;

  public:
    Organism(int power, Position position);
    Organism() : power_(0), position_(0, 0), species_(organism){};
    virtual ~Organism();

    int power() const
    {
        return power_;
    };
    void power(int power)
    {
        power_ = power;
    };
    Position position() const
    {
        return position_;
    };
    void position(Position position)
    {
        position_ = position;
    };
    Species species() const
    {
        return species_;
    };
    void species(Species species)
    {
        species_ = species;
    };

    operator std::string();

    virtual void move(int dx, int dy);
};

std::ostream &operator<<(std::ostream &os, Organism &o);
