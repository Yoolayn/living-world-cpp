#pragma once
#include <string>
#include "position.hpp"

class Organism
{
private:
    int power_;
    Position position_;
    std::string species_;
public:
    Organism(int power, Position position);
    Organism() : power_(0), position_(0, 0), species_("O") {};

    int power() const { return power_; };
    void power(int power) { power_ = power; };
    Position position() const { return position_; };
    void position(Position position) { position_ = position; };
    std::string species() const { return species_; };
    void species(std::string species) { species_ = species; };

    operator std::string();

    virtual void move(int dx, int dy);
};
