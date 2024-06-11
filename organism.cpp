#include "organism.hpp"
#include "position.hpp"
#include <ostream>

std::string species_to_string(const Species &s)
{
    switch (s) {
    case Species::plant:
        return "P";
        break;
    case Species::animal:
        return "A";
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
    }
}

bool Organism::operator==(Species s)
{
    return m_Species == s;
}

bool Organism::operator==(Organism o)
{
    return m_Power == o.m_Power && m_Position == o.m_Position && m_Species == o.m_Species;
}

Organism::operator std::string()
{
    return "{ species: " + species_to_string(species()) + ", power: " + std::to_string(power())
           + ", position: " + position() + "}";
}

void Organism::move(Position p)
{
    m_Position.move(p);
}

void Organism::move(int x, int y)
{
    m_Position.move(x, y);
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

std::optional<std::unique_ptr<Organism>> Organism::operator+(Organism *o)
{
    (void)o;
    return std::nullopt;
}

std::optional<std::unique_ptr<Organism>> Organism::clone()
{
    return std::nullopt;
}
