#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(int power, Position position) : Organism(power, position)
{
    setSpecies("P");
}

Plant::Plant() : Organism()
{
    setSpecies("P");
}

void Plant::move(int dx, int dy)
{
    (void)dx;
    (void)dy;
    Organism::move(0, 0);
}
