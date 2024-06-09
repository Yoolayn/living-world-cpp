#include "dandelion.hpp"
#include "organism.hpp"
#include "plant.hpp"

Dandelion::Dandelion() : Plant()
{
    species_ = Species::dandelion;
}

Dandelion::Dandelion(Position position) : Plant(position)
{
    species_ = Species::dandelion;
}

std::optional<Organism> Dandelion::clone()
{
    return Dandelion{};
}
