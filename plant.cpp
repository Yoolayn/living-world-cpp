#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(Position position) : Organism(0, position)
{
    species_ = Species::plant;
    range_ = 2;
}

Plant::Plant() : Organism(0)
{
    species_ = Species::plant;
    range_ = 2;
}

void Plant::move(Position p)
{
    (void)p;
    position_.move(0, 0);
}

void Plant::move(int x, int y)
{
    (void)x;
    (void)y;
    position_.move(0, 0);
}

std::optional<std::unique_ptr<Organism>> Plant::clone()
{
    return std::make_unique<Plant>();
}
