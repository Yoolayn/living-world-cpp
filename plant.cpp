#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(int power, Position position) : Organism(power, position)
{
    species(Species::plant);
}

Plant::Plant() : Organism()
{
    species(Species::plant);
}

void Plant::move(int dx, int dy)
{
    (void)dx;
    (void)dy;
    Organism::move(0, 0);
}
