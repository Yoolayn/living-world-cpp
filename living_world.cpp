#include "animal.hpp"
#include "boost/signals2/signal.hpp"
#include "historian.hpp"
#include "organism.hpp"
#include "plant.hpp"
#include "position.hpp"
#include "record.hpp"
#include "todo.hpp"
#include "world.hpp"
#include <iostream>

int main()
{
    TODO("make code work 🤓");

    World world{5, 5};
    world += Animal{10, Position{1, 2}};
    world += Animal{10, Position{2, 3}};
    world += Animal{10, Position{3, 3}};

    Position p{2, 2};
    std::cout << "all\n";
    for (auto x : world.getVectorOfPositionsAround(p, false))
        std::cout << x << std::endl;

    std::cout << "free\n";
    for (auto x : world.getVectorOfPositionsAround(p, true))
        std::cout << x << std::endl;
}
