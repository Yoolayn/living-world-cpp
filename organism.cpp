#include "organism.hpp"
#include "position.hpp"

Organism::Organism(int power, Position position)
{
    this->power(power);
    this->position(position);
    this->species(organism);
}

std::string to_string(Species s)
{
    switch (s) {
    case animal:
        return "animal";
        break;
    case plant:
        return "plant";
        break;
    case organism:
        return "organism";
        break;
    }
}

Organism::operator std::string()
{
    return "{ species: " + to_string(species()) +
           ", power: " + std::to_string(power()) +
           ", position: " + (std::string)position() + "}";
}

void Organism::move(int dx, int dy)
{
    position_.move(dx, dy);
}

Organism::~Organism()
{
}

std::ostream &operator<<(std::ostream &os, Organism &o)
{
    return os << (std::string)o;
}
