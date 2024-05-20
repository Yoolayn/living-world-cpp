#include "organism.h"
#include "position.h"

Organism::Organism(int power, Position position)
{
    setPower(power);
    setPosition(position);
    setSpecies("O");
}

int Organism::getPower()
{
    return this->power;
}

void Organism::setPower(int power)
{
    this->power = power;
}

Position Organism::getPosition()
{
    return this->position;
}

void Organism::setPosition(Position position)
{
    this->position = position;
}

std::string Organism::getSpecies()
{
    return this->species;
}

void Organism::setSpecies(std::string species)
{
    this->species = species;
}

std::string Organism::toString()
{
    return "{ species: " + this->getSpecies() +
    ", power: " + std::to_string(getPower()) +
    ", position: " + getPosition().toString() + "}";
}

void Organism::move(int dx, int dy)
{
    position.move(dx, dy);
}
