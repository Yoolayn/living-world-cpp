#include "plant.hpp"

class Dandelion : public Plant
{
  public:
    Dandelion();
    Dandelion(Position position);

    std::optional<Organism> clone();
};
