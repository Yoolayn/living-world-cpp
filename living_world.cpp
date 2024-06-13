#include "fern.hpp"
#include "grass.hpp"
#include "historian.hpp"
#include "macros.hpp"
#include "position.hpp"
#include "sheep.hpp"
#include "wolf.hpp"
#include "world.hpp"
#include <memory>

int main()
{
    TODO("make code work 🤓");

    World world{10, 10};
    Historian historian{};

    std::unique_ptr<Organism> organisms[16] = {
        // grasses
        std::make_unique<Grass>(Position{1, 1}),
        std::make_unique<Grass>(Position{1, 2}),
        std::make_unique<Grass>(Position{2, 1}),
        std::make_unique<Grass>(Position{2, 2}),

        // Ferns
        std::make_unique<Fern>(Position{5, 1}),
        std::make_unique<Fern>(Position{5, 2}),
        std::make_unique<Fern>(Position{6, 1}),
        std::make_unique<Fern>(Position{6, 2}),

        // Wolves
        std::make_unique<Wolf>(3, Position{1, 5}),
        std::make_unique<Wolf>(3, Position{2, 5}),
        std::make_unique<Wolf>(3, Position{1, 6}),
        std::make_unique<Wolf>(3, Position{2, 6}),

        // Sheep
        std::make_unique<Sheep>(Position{5, 5}),
        std::make_unique<Sheep>(Position{5, 6}),
        std::make_unique<Sheep>(Position{6, 5}),
        std::make_unique<Sheep>(Position{6, 6}),
    };

    for (auto &x : organisms)
        if (x) {
            x->index(historian += std::make_shared<Record>(0));
            world += x;
        }

    world += [&historian, &world](size_t x) {
        (*historian[x])->death(world.turn());
    };

    world.newRegisterFuncClone([&historian, &world](Organism& o, Organism& p){
        auto r = std::make_shared<Record>(world.turn());
        *r.get() += p.index();
        o.index(historian += r);
    });

    world.newRegisterFuncBreed([&historian, &world](Organism& o, Organism& p1, Organism& p2){
        auto r = std::make_shared<Record>(world.turn());
        *r.get() += p1.index();
        *r.get() += p2.index();
        o.index(historian += r);
    });

    for (int x = 0; x < 10; ++x)
        world();

    for (auto x : historian.records())
        std::cout << *x << std::endl;
}
