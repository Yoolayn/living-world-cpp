#include "animal.hpp"

Animal::Animal(int power, Position position) : Organism::Organism(power, position)
{
    species("A");
}

Animal::Animal() : Organism::Organism()
{
    species("A");
}
