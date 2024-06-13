#include "plant.hpp"
#include <memory>

class Fern : public Plant
{
  public:
    Fern();
    Fern(Position position);

    std::optional<std::unique_ptr<Organism>> clone() override;
};
