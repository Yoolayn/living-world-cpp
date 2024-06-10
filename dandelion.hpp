#include "plant.hpp"
#include <memory>

class Dandelion : public Plant
{
  public:
    Dandelion();
    Dandelion(Position position);

    std::optional<std::unique_ptr<Organism>> clone() override;
};
