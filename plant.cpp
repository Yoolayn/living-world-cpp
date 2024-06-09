#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(Position position) : Organism(0, position)
{
    species_ = Species::plant;
}

Plant::Plant() : Organism(0)
{
    species_ = Species::plant;
}

void Plant::move(int dx, int dy)
{
    (void)dx;
    (void)dy;
    Organism::move(0, 0);
}

std::optional<Organism> Plant::clone()
{
    return Plant{};
}
