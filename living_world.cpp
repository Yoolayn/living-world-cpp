#include "grass.hpp"
#include "historian.hpp"
#include "position.hpp"
#include "sheep.hpp"
#include "todo.hpp"
#include "wolf.hpp"
#include "world.hpp"
#include <boost/signals2/signal.hpp>

int main()
{
    TODO("make code work 🤓");

    World world{10, 10};
    world += std::make_unique<Grass>(Position{1, 1});
    world += std::make_unique<Grass>(Position{1, 2});
    world += std::make_unique<Grass>(Position{2, 1});
    world += std::make_unique<Grass>(Position{2, 2});

    for (int x = 0; x < 5; ++x)
        world();
}
