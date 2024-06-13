#pragma once
#include "organism.hpp"
#include <boost/signals2/signal.hpp>
#include <ctime>
#include <memory>
#include <ostream>
#include <vector>

using Signal = boost::signals2::signal<void(size_t)>;

class World
{
  private:
    int m_WorldX;
    int m_WorldY;
    int m_Turn;
    std::vector<std::unique_ptr<Organism>> m_Organisms;
    char separator = '.';
    Signal m_Sig;
    std::function<void(Organism&)> m_RegisterOrganism;

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
    void newRegisterFunc(std::function<void(Organism&)> func)
    {
        m_RegisterOrganism = func;
    }
    std::function<void(Organism&)> getRegisterFunc() const
    {
        return m_RegisterOrganism;
    }

    void operator+=(std::function<void(size_t)> &&func)
    {
        m_Sig.connect(func);
    }
    void sig(size_t idx)
    {
        m_Sig(idx);
    }

    std::vector<Position> getVectorOfPositionsAround(Position position, bool free, int range);
    void makeTurn();
    bool action(Action a, Organism &org, Organism *new_org);

    void operator()();
    void operator+=(std::unique_ptr<Organism> &organism);
    void operator+=(std::unique_ptr<Organism> &&organism);
    void operator-=(Organism *organism);

    void writeWorld(std::string filename);
    void readWorld(std::string filename);

    operator std::string();
};

std::ostream &operator<<(std::ostream &os, World &w);
