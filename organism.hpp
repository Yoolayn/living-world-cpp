#pragma once
#include <string>
#include "position.hpp"

class Organism
{
private:
    int power;
    Position position;
    std::string species;
public:
    Organism(int power, Position position);
    Organism() : power(0), position(0, 0), species("O") {};

    int getPower();
    void setPower(int power);
    Position getPosition();
    void setPosition(Position position);
    std::string getSpecies();
    void setSpecies(std::string species);

    std::string toString();

    virtual void move(int dx, int dy);
};
