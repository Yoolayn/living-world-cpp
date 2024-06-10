#include "grass.hpp"
#include "organism.hpp"
#include "plant.hpp"

Grass::Grass(Position position) : Plant(position)
{
    species_ = Species::grass;
};

Grass::Grass() : Plant()
{
    species_ = Species::grass;
};

std::optional<std::unique_ptr<Organism>> Grass::clone()
{
    return std::optional(std::make_unique<Grass>());
}
