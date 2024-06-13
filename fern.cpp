#include "fern.hpp"
#include "organism.hpp"

Fern::Fern() : Plant()
{
    m_Species = Species::fern;
}

Fern::Fern(Position position) : Plant(position)
{
    m_Species = Species::fern;
}

std::optional<std::unique_ptr<Organism>> Fern::clone()
{

    return std::make_unique<Fern>();
}
