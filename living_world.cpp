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
    TODO("make code work");
    TODO("🤓");

    World world{};
    world += Animal{10, Position{1, 2}};
    world += Animal{10, Position{2, 2}};
    world += Animal{10, Position{3, 3}};
    world += Animal{10, Position{4, 3}};

    world();
    std::cout << world;

    world();
    std::cout << world;

    world();
    std::cout << world;

    world();
    std::cout << world;
}
