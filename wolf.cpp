#include "wolf.hpp"
#include "organism.hpp"
#include <memory>

Wolf::Wolf() : Animal(), m_Lifetime(2)
{
    m_Species = Species::wolf;
}

Wolf::Wolf(int power) : Animal(power), m_Lifetime(2)
{
    m_Species = Species::wolf;
}

Wolf::Wolf(int power, Position position) : Animal(power, position), m_Lifetime(2)
{
    m_Species = Species::wolf;
}

Action Wolf::act(Organism &o)
{
    if (m_Lifetime == 0)
        return Action::die;

    switch (o.species()) {
    case Species::wolf:
        return Action::breed;
    case Species::sheep:
        return Action::kill;
    default:
        return Action::nothing;
    }
}

std::optional<std::unique_ptr<Organism>> Wolf::operator+(Organism &o)
{
    return std::make_unique<Wolf>(m_Power + o.power() / 2);
}

void Wolf::move(int x, int y)
{
    m_Lifetime -= 1;
    Animal::move(x, y);
}

void Wolf::move(Position p)
{
    m_Lifetime -= 1;
    Animal::move(p);
}
