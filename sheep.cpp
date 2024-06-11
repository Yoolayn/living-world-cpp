#include "sheep.hpp"
#include "organism.hpp"
#include <optional>

Sheep::Sheep(Position p) : Animal(3, p)
{
    m_Species = Species::sheep;
}

Sheep::Sheep() : Animal(3)
{
    m_Species = Species::sheep;
}

Action Sheep::act(Organism o)
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

std::optional<Organism> Sheep::operator+(Sheep s)
{
    (void)s;
    return Sheep{};
}
