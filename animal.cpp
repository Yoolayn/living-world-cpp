#include "animal.hpp"

Animal::Animal(int power, Position position)
    : Organism::Organism(power, position)
{
    species(animal);
}

Animal::Animal() : Organism::Organism()
{
    species(animal);
}

Action Animal::act(Organism o)
{
    switch (o.species()) {
    case plant:
    case animal:
    case organism:
        break;
    }
    return Action::breed;
}
