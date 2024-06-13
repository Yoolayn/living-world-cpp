#pragma once
#include "actions.hpp"
#include "position.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

enum class Species { plant, animal, organism, grass, wolf, sheep, fern };

std::string operator+(const std::string &str, Species species);
std::string species_to_string(const Species &s);

class Organism
{
  protected:
    size_t m_Index;
    int m_Power;
    int m_Range;
    Position m_Position;
    Species m_Species;
    Organism(int power, Position position)
        : m_Power(power), m_Range(1), m_Position(position), m_Species(Species::organism){};
    Organism(int power) : m_Power(power), m_Range(1), m_Position(-1, -1), m_Species(Species::organism){};
    Organism() : m_Power(0), m_Range(1), m_Position(-1, -1), m_Species(Species::organism){};

  public:
    virtual ~Organism();

    int power() const
    {
        return m_Power;
    };
    void power(int power)
    {
        m_Power = power;
    };
    Position position() const
    {
        return m_Position;
    };
    void position(Position position)
    {
        m_Position = position;
    };
    const Species &species() const
    {
        return m_Species;
    };
    int range() const
    {
        return m_Range;
    }
    size_t index()
    {
        return m_Index;
    }
    void index(size_t x)
    {
        m_Index = x;
    }

    operator std::string();
    bool operator==(Species s);
    bool operator==(Organism o);

    virtual std::optional<std::unique_ptr<Organism>> operator+(Organism &o);
    virtual std::optional<std::unique_ptr<Organism>> clone();
    virtual Action act(Organism &o);
    virtual void move(int x, int y);
    virtual void move(Position p);
};

std::ostream &operator<<(std::ostream &os, Organism &o);
