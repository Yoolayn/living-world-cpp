#include "sheep.hpp"
#include "organism.hpp"
#include "macros.hpp"
#include <optional>

Sheep::Sheep(Position p) : Animal(3, p)
{
    m_Species = Species::sheep;
}

Sheep::Sheep() : Animal(3)
{
    m_Species = Species::sheep;
}

Action Sheep::act(Organism &o)
{
    switch (o.species()) {
    case Species::grass:
        return Action::eat;
    case Species::wolf:
        return Action::die;
    case Species::sheep:
        return Action::breed;
    case Species::fern:
        return Action::eat;
    default:
        return Action::nothing;
    }
}

std::optional<Organism> Sheep::operator+(Sheep)
{
    return Sheep{};
}
