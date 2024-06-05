#include "organism.hpp"
#include "position.hpp"

Organism::Organism(int power, Position position)
{
    this->power(power);
    this->position(position);
    this->species(organism);
}

bool Organism::operator==(Species s)
{
    return species_ == s;
}

std::string to_string(Species s)
{
    switch (s) {
    case animal:
        return "A";
        break;
    case plant:
        return "P";
        break;
    case organism:
        return "O";
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

Organism::~Organism(){};

Action Organism::act(Organism o)
{
    switch (o.species()) {
    case plant:
    case animal:
    case organism:
        break;
    }
    return Action::breed;
}

std::ostream &operator<<(std::ostream &os, Organism &o)
{
    return os << (std::string)o;
}
