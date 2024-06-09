#include "wolf.hpp"
#include "organism.hpp"
#include "todo.hpp"

Wolf::Wolf() : Animal()
{
    species_ = Species::wolf;
}

Wolf::Wolf(int power) : Animal(power)
{
    species_ = Species::wolf;
}

Wolf::Wolf(int power, Position position) : Animal(power, position)
{
    species_ = Species::wolf;
}

Action Wolf::act(Organism o)
{
    TODO("Wolf Action");
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

std::optional<Organism> Wolf::operator+(Organism o)
{
    return Wolf{power_ + o.power() / 2};
}
