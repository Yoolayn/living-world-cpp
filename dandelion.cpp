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

std::optional<std::unique_ptr<Organism>> Dandelion::clone()
{

    return std::make_unique<Dandelion>();
}
