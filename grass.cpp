#include "grass.hpp"
#include "organism.hpp"
#include "plant.hpp"

Grass::Grass(Position position) : Plant(position)
{
    m_Species = Species::grass;
};

Grass::Grass() : Plant()
{
    m_Species = Species::grass;
};

std::optional<std::unique_ptr<Organism>> Grass::clone()
{
    return std::optional(std::make_unique<Grass>());
}
