#include "animal.hpp"
#include "organism.hpp"
#include "position.hpp"
#include <optional>

class Sheep : public Animal
{
  public:
    Sheep();
    Sheep(Position p);

    Action act(Organism &o);
    std::optional<Organism> operator+(Sheep s);
};
