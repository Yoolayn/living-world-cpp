#include "wolf.hpp"
#include "organism.hpp"

Wolf::Wolf() : Animal()
{
    m_Species = Species::wolf;
}

Wolf::Wolf(int power) : Animal(power)
{
    m_Species = Species::wolf;
}

Wolf::Wolf(int power, Position position) : Animal(power, position)
{
    m_Species = Species::wolf;
}

Action Wolf::act(Organism &o)
{
    switch (o.species()) {
    case Species::wolf:
        return Action::breed;
    case Species::sheep:
        return Action::kill;
    default:
        return Action::nothing;
    }
}

std::optional<Organism> Wolf::operator+(Organism o)
{
    return Wolf{m_Power + o.power() / 2};
}
