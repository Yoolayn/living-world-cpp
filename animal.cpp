#include "animal.hpp"
#include "organism.hpp"
#include <optional>

Animal::Animal(int power, Position position) : Organism::Organism(power, position)
{
    m_Species = Species::animal;
}

Animal::Animal(int power) : Organism::Organism(power)
{
    m_Species = Species::animal;
}

Animal::Animal() : Organism::Organism()
{
    m_Species = Species::animal;
}

Action Animal::act(Organism &o)
{
    switch (o.species()) {
    case Species::plant:
    case Species::animal:
    case Species::organism:
    case Species::grass:
    case Species::wolf:
    case Species::sheep:
    case Species::fern:
        break;
    }
    return Action::breed;
}

std::optional<std::unique_ptr<Organism>> Animal::operator+(Organism *)
{
    return std::nullopt;
}

std::optional<std::unique_ptr<Organism>> Animal::clone()
{
    return std::nullopt;
}
