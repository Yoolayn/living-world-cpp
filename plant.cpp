#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(Position position) : Organism(0, position)
{
    m_Species = Species::plant;
    m_Range = 2;
}

Plant::Plant() : Organism(0)
{
    m_Species = Species::plant;
    m_Range = 2;
}

void Plant::move(Position)
{
    m_Position.move(0, 0);
}

void Plant::move(int, int)
{
    m_Position.move(0, 0);
}

std::optional<std::unique_ptr<Organism>> Plant::clone()
{
    return std::nullopt;
}

Action Plant::act(Organism &o)
{
    if (m_Species == o.species()) {
        return Action::breed;
    }
    return Action::nothing;
}
