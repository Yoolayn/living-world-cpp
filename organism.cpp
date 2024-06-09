#include "organism.hpp"
#include "position.hpp"
#include "todo.hpp"
#include <ostream>
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
    case Species::grass:
        return "G";
        break;
    case Species::wolf:
        return "W";
        break;
    case Species::sheep:
        return "S";
        break;
    case Species::dandelion:
        return "D";
        break;
    default:
        TODO("cry");
        return "?";
        break;
    }
}

std::ostream &operator<<(std::ostream &os, Species &s)
{
    return os << to_string(s);
}

std::string operator+=(std::string &str, Species species)
{
    return str + to_string(species);
}

bool Organism::operator==(Species s)
{
    return species_ == s;
}

bool Organism::operator==(Organism o)
{
    return power_ == o.power_ && position_ == o.position_ && species_ == o.species_;
}

Organism::operator std::string()
{
    return "{ species: " + to_string(species()) + ", power: " + std::to_string(power()) + ", position: " + position()
           + "}";
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
    case Species::grass:
    case Species::wolf:
    case Species::sheep:
    case Species::dandelion:
        break;
    }
    return Action::breed;
}

std::ostream &operator<<(std::ostream &os, Organism &o)
{
    return os << (std::string)o;
}

std::optional<Organism> Organism::operator+(Organism o)
{
    (void)o;
    return std::optional<Organism>();
}

std::optional<Organism> Organism::clone()
{
    return std::optional<Organism>();
}
