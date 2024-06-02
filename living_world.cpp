#include "boost/signals2/signal.hpp"
#include <iostream>
#include "position.hpp"
#include "organism.hpp"
#include "plant.hpp"
#include "animal.hpp"
#include "world.hpp"
#include "historian.hpp"
#include "record.hpp"

int main()
{
    World world{};
    Historian hist{};
    Record r{};
    hist += r;

    auto v = hist[0];
    if (v)
        std::cout << (std::string) *v << std::endl;
    else
        std::cout << "not found\n";

    auto v2 = hist[1];

    if (v2)
        std::cout << (std::string) *v << std::endl;
    else
        std::cout << "not found\n";
}
