#include "animal.hpp"
#include "organism.hpp"
#include <optional>

Animal::Animal(int power, Position position) : Organism::Organism(power, position)
{
    species_ = Species::animal;
}

Animal::Animal(int power) : Organism::Organism(power)
{
    species_ = Species::animal;
}

Animal::Animal() : Organism::Organism()
{
    species_ = Species::animal;
}

Action Animal::act(Organism o)
{
    switch (o.species()) {
    case Species::plant:
    case Species::animal:
    case Species::organism:
    case Species::grass:
    case Species::wolf:
    case Species::sheep:
    case Species::dandelion:
        break;
    }
    return Action::breed;
}

std::optional<std::unique_ptr<Organism>> Animal::operator+(Organism *o)
{
    (void)o;
    return std::nullopt;
}

std::optional<std::unique_ptr<Organism>> Animal::clone()
{
    return std::nullopt;
}
