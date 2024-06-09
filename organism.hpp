#pragma once
#include "actions.hpp"
#include "position.hpp"
#include <ostream>
#include <string>

enum class Species { plant, animal, organism, grass, wolf, sheep, dandelion };

std::ostream &operator<<(std::ostream &os, Species &s);
std::string operator+(const std::string &str, Species species);
std::string operator+=(std::string &str, Species species);
std::string to_string(Species s);;

class Organism
{
  protected:
    int power_;
    int range_;
    Position position_;
    Species species_;

  public:
    Organism(int power, Position position)
        : power_(power), position_(position){};
    Organism(int power) : power_(power), range_(1), species_(Species::organism){};
    Organism() : power_(0), range_(1), position_(0, 0), species_(Species::organism){};
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
    Species species() const
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

    virtual std::optional<Organism> operator+(Organism o);
    virtual std::optional<Organism> clone();
    virtual Action act(Organism o);
    virtual void move(int dx, int dy);
};

std::ostream &operator<<(std::ostream &os, Organism &o);
