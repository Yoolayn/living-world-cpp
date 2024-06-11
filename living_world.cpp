#include "grass.hpp"
#include "historian.hpp"
#include "position.hpp"
#include "sheep.hpp"
#include "todo.hpp"
#include "world.hpp"
#include "wolf.hpp"
#include "dandelion.hpp"
#include <memory>

int main()
{
    TODO("make code work 🤓");

    World world{10, 10};
    world += std::make_unique<Grass>(Position{1, 1});
    world += std::make_unique<Grass>(Position{1, 2});
    world += std::make_unique<Grass>(Position{2, 1});
    world += std::make_unique<Grass>(Position{2, 2});

    world += std::make_unique<Dandelion>(Position{5, 1});
    world += std::make_unique<Dandelion>(Position{5, 2});
    world += std::make_unique<Dandelion>(Position{6, 1});
    world += std::make_unique<Dandelion>(Position{6, 2});

    world += std::make_unique<Wolf>(3, Position{1, 5});
    world += std::make_unique<Wolf>(3, Position{2, 5});
    world += std::make_unique<Wolf>(3, Position{1, 6});
    world += std::make_unique<Wolf>(3, Position{2, 6});

    world += std::make_unique<Sheep>(Position{5, 5});
    world += std::make_unique<Sheep>(Position{5, 5});
    world += std::make_unique<Sheep>(Position{6, 6});
    world += std::make_unique<Sheep>(Position{6, 6});

    for (int x = 0; x < 5; ++x)
        world();
}
