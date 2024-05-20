#pragma once

#include <vector>
#include <ctime>
#include "organism.h"

class World
{
private:
    int worldX;
    int worldY;
    int turn = 0;
    std::vector<Organism> organism;
    char separator = ".";

    std::string getOrganismFromPosition(int x, int y);
    bool isPositionWorld(int x, int y);
    bool isPositionFree(Position position);
public:
    World(int worldX, int worldY);
    World() : World(6, 6) {};

    int getWorldX();
    void setWorldX(int worldX);
    int getWorldY();
    void setWorldY(int worldY);

    int getTurn();

    void addOrganism(Organism *organism);
    std::vector<Position> getVectorOfFreePositionsAround(Position position);
    void makeTurn();

    void writeWorld(std::string filename);
    void readWorld(std::string filename);

    std::string toString();
}
