#pragma once
#include "organism.hpp"
#include <ctime>
#include <memory>
#include <ostream>
#include <vector>

class World
{
  private:
    int m_WorldX;
    int m_WorldY;
    int m_Turn;
    std::vector<std::unique_ptr<Organism>> m_Organisms;
    char separator = '.';

    std::optional<Organism *> getOrganismFromPosition(Position position);
    bool isPositionOnWorld(Position position);
    bool isPositionFree(Position position);

  public:
    World() : World(6, 6){};
    World(int worldX, int worldY);

    int worldX() const
    {
        return m_WorldX;
    };
    void worldX(int x)
    {
        m_WorldX = x;
    };
    int worldY() const
    {
        return m_WorldY;
    };
    void worldY(int y)
    {
        m_WorldY = y;
    };
    int turn() const
    {
        return m_Turn;
    };
    std::vector<std::unique_ptr<Organism>> &organisms()
    {
        return m_Organisms;
    }

    std::vector<Position> getVectorOfPositionsAround(Position position, bool free, int range);
    void makeTurn();
    bool action(Action a, Organism &org, Organism *new_org);

    void operator()(); // void makeTurn()
    void operator+=(std::unique_ptr<Organism> organism);
    void operator-=(Organism *organism);
    // void operator-=(int o);

    void writeWorld(std::string filename);
    void readWorld(std::string filename);

    operator std::string();
};

std::ostream &operator<<(std::ostream &os, World &w);
