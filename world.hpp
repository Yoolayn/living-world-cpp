#pragma once
#include "organism.hpp"
#include <ctime>
#include <ostream>
#include <vector>

class World
{
  private:
    int worldX_;
    int worldY_;
    int turn_;
    std::vector<Organism> organisms_;
    char separator = '.';

    std::optional<Organism> getOrganismFromPosition(Position position);
    bool isPositionOnWorld(Position position);
    bool isPositionFree(Position position);

  public:
    World() : World(6, 6){};
    World(int worldX, int worldY);

    int worldX() const
    {
        return worldX_;
    };
    void worldX(int x)
    {
        worldX_ = x;
    };
    int worldY() const
    {
        return worldY_;
    };
    void worldY(int y)
    {
        worldY_ = y;
    };
    int turn() const
    {
        return turn_;
    };
    std::vector<Organism> organisms() const
    {
        return organisms_;
    }

    std::vector<Position> getVectorOfPositionsAround(Position position,
                                                     bool free, int range);
    void makeTurn();
    bool action(Organism *org, Organism *new_org);

    void operator()(); // void makeTurn()
    void operator+=(Organism organism);
    void operator-=(Organism organism);
    // void operator-=(int o);

    void writeWorld(std::string filename);
    void readWorld(std::string filename);

    operator std::string();
};

std::ostream &operator<<(std::ostream &os, World &w);
