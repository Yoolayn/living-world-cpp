#include "plant.hpp"
#include "organism.hpp"

Plant::Plant(int power, Position position) : Organism(power, position)
{
    species("P");
}

Plant::Plant() : Organism()
{
    species("P");
}

void Plant::move(int dx, int dy)
{
    (void)dx;
    (void)dy;
    Organism::move(0, 0);
}
