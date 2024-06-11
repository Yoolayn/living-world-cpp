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

void Plant::move(Position p)
{
    (void)p;
    m_Position.move(0, 0);
}

void Plant::move(int x, int y)
{
    (void)x;
    (void)y;
    m_Position.move(0, 0);
}

std::optional<std::unique_ptr<Organism>> Plant::clone()
{
    return std::nullopt;
}
