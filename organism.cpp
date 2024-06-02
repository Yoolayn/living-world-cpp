#include "organism.hpp"
#include "position.hpp"

Organism::Organism(int power, Position position)
{
    this->power(power);
    this->position(position);
    this->species("O");
}

Organism::operator std::string()
{
    return "{ species: " + species() +
    ", power: " + std::to_string(power()) +
    ", position: " + (std::string) position() + "}";
}

void Organism::move(int dx, int dy)
{
    position_.move(dx, dy);
}

Organism::~Organism() {}
