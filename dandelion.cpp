#include "dandelion.hpp"
#include "organism.hpp"
#include "plant.hpp"

Dandelion::Dandelion() : Plant()
{
    m_Species = Species::dandelion;
}

Dandelion::Dandelion(Position position) : Plant(position)
{
    m_Species = Species::dandelion;
}

std::optional<std::unique_ptr<Organism>> Dandelion::clone()
{

    return std::make_unique<Dandelion>();
}
