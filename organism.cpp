#include "organism.hpp"
#include "position.hpp"
#include <ostream>

Organism::Organism(int power, Position position)
{
    this->power(power);
    this->position(position);
    this->species(Species::organism);
}

std::string to_string(Species s)
{
    switch (s) {
    case Species::animal:
        return "A";
        break;
    case Species::plant:
        return "P";
        break;
    case Species::organism:
        return "O";
        break;
    }
}

std::ostream &operator<<(std::ostream &os, Species &s)
{
    return os << to_string(s);
}

std::string operator+(const std::string &str, Species species)
{
    return str + to_string(species);
}

bool Organism::operator==(Species s)
{
    return species_ == s;
}

Organism::operator std::string()
{
    return "{ species: " + species() + ", power: " + std::to_string(power())
           + ", position: " + position() + "}";
}

void Organism::move(int dx, int dy)
{
    position_.move(dx, dy);
}

Organism::~Organism(){};

Action Organism::act(Organism o)
{
    switch (o.species()) {
    case Species::plant:
    case Species::animal:
    case Species::organism:
        break;
    }
    return Action::breed;
}

std::ostream &operator<<(std::ostream &os, Organism &o)
{
    return os << (std::string)o;
}
