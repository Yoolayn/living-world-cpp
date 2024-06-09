#include "grass.hpp"
#include "historian.hpp"
#include "position.hpp"
#include "sheep.hpp"
#include "todo.hpp"
#include "wolf.hpp"
#include "world.hpp"
#include <boost/signals2/signal.hpp>
#include <iostream>

int main()
{
    TODO("make code work 🤓");

    World world{10, 10};
    world += Grass{Position{1, 1}};
    world += Grass{Position{2, 2}};
    world += Grass{Position{3, 3}};
    world += Grass{Position{4, 1}};
    world += Grass{Position{5, 2}};
    world += Grass{Position{6, 3}};

    world += Wolf{10, Position{3, 4}};
    world += Wolf{20, Position{3, 5}};

    world += Sheep{Position{4, 3}};
    world += Sheep{Position{4, 4}};

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
