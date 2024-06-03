#pragma once
#include <ostream>
#include <vector>
#include <ctime>
#include "organism.hpp"

class World
{
private:
    int worldX_;
    int worldY_;
    int turn_ = 0;
    std::vector<Organism> organisms_;
    char separator = '.';

    std::string getOrganismFromPosition(int x, int y);
    bool isPositionOnWorld(int x, int y);
    bool isPositionFree(Position position);
public:
    World(int worldX, int worldY);
    World() : World(6, 6) {};

    int worldX() const { return worldX_; };
    void worldX(int x) { worldX_ = x; };
    int worldY() const { return worldY_; };
    void worldY(int y) { worldY_ = y; };
    int turn() const { return turn_; };

    std::vector<Position> getVectorOfPositionsAround(Position position);
    void makeTurn();

    void operator()(); // void makeTurn()
    void operator+=(Organism organism);

    void writeWorld(std::string filename);
    void readWorld(std::string filename);

    operator std::string();
};

std::ostream& operator<<(std::ostream& os, World& w);
