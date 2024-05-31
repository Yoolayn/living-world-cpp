#include "animal.hpp"

Animal::Animal(int power, Position position) : Organism::Organism(power, position)
{
    setSpecies("A");
}

Animal::Animal() : Organism::Organism()
{
    setSpecies("A");
}
