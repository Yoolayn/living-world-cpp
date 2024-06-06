#include "animal.hpp"
#include "organism.hpp"
#include <optional>

Animal::Animal(int power, Position position)
    : Organism::Organism(power, position)
{
    species_ = Species::animal;
}

Animal::Animal() : Organism::Organism()
{
    species_ = Species::animal;
}

Animal::Animal(int power) : Organism::Organism(power)
{
    species_ = Species::animal;
}

Action Animal::act(Organism o)
{
    switch (o.species()) {
    case Species::plant:
    case Species::animal:
    case Species::organism:
        break;
    }
    return Action::breed;
}

std::optional<Organism> Animal::operator+(Organism o)
{
    return Animal{this->power_ + o.power()};
}

std::optional<Organism> Animal::clone()
{
    return std::optional<Organism>();
}
