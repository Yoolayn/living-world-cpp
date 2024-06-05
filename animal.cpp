#include "animal.hpp"

Animal::Animal(int power, Position position)
    : Organism::Organism(power, position)
{
    species(Species::animal);
}

Animal::Animal() : Organism::Organism()
{
    species(Species::animal);
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
