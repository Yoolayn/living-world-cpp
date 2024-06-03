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
