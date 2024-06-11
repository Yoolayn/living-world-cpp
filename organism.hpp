#pragma once
#include "actions.hpp"
#include "position.hpp"
#include <memory>
#include <ostream>
#include <string>

enum class Species { plant, animal, organism, grass, wolf, sheep, dandelion };

std::string operator+(const std::string &str, Species species);
std::string species_to_string(const Species &s);

class Organism
{
  protected:
    int power_;
    int range_;
    Position position_;
    Species species_;
    Organism(int power, Position position)
        : power_(power), range_(1), position_(position), species_(Species::organism){};
    Organism(int power) : power_(power), range_(1), position_(-1, -1), species_(Species::organism){};
    Organism() : power_(0), range_(1), position_(-1, -1), species_(Species::organism){};

  public:
    virtual ~Organism();

    int power() const
    {
        return power_;
    };
    void power(int power)
    {
        power_ = power;
    };
    Position position() const
    {
        return position_;
    };
    void position(Position position)
    {
        position_ = position;
    };
    const Species& species() const
    {
        return species_;
    };
    int range() const
    {
        return range_;
    }

    operator std::string();
    bool operator==(Species s);
    bool operator==(Organism o);

    virtual std::optional<std::unique_ptr<Organism>> operator+(Organism *o);
    virtual std::optional<std::unique_ptr<Organism>> clone();
    virtual Action act(Organism o);
    virtual void move(int x, int y);
    virtual void move(Position p);
};

std::ostream &operator<<(std::ostream &os, Organism &o);
