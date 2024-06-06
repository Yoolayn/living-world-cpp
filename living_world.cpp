#include "animal.hpp"
#include "historian.hpp"
#include "organism.hpp"
#include "plant.hpp"
#include "position.hpp"
#include "record.hpp"
#include "todo.hpp"
#include "world.hpp"
#include <boost/signals2/signal.hpp>
#include <iostream>

int main()
{
    TODO("make code work 🤓");

    World world{5, 5};
    world += Animal{10, Position{1, 1}};
    world += Animal{10, Position{2, 2}};
    world += Animal{10, Position{3, 3}};
    world += Animal{10, Position{4, 1}};
    world += Animal{10, Position{5, 2}};
    world += Animal{10, Position{6, 3}};

    std::cout << world;
    world();
    std::cout << world;
    world();
    std::cout << world;
    world();
    std::cout << world;
    world();
    std::cout << world;
}
