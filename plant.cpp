#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(int power, Position position) : Organism(power, position)
{
    species_ = Species::plant;
}

Plant::Plant(int power) : Organism(power)
{
    species_ = Species::plant;
}

Plant::Plant() : Organism()
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
    return Plant{0};
}
