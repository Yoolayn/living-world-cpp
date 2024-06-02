#include "world.hpp"
#include "organism.hpp"
#include "todo.hpp"
#include <fstream>
#include <iostream>
#include <ranges>

World::World(int worldX, int worldY) : worldX_(worldX), worldY_(worldY), turn_(0)
{
    organisms_ = std::vector<Organism>();
}

std::string World::getOrganismFromPosition(int x, int y)
{
    for (Organism org : this->organisms_)
        if (org.position().x() == x && org.position().y() == y)
            return org.species();
    return "";
}

bool World::isPositionOnWorld(int x, int y)
{
    return x >= 0 && y >= 0 && x < worldX() && y < worldY();
}

bool World::isPositionFree(Position position)
{
    return this->getOrganismFromPosition(position.x(), position.y()).empty();
}

void World::operator+=(Organism *organism)
{
    organisms_.push_back(*organism);
}

std::vector<Position> World::getVectorOfFreePositionsAround(Position position)
{
    namespace pipe = std::views;

    int pos_x = position.x(), pos_y = position.y();
    auto positions = pipe::iota(-1, 2)
        | pipe::transform([](int dx) {
            return pipe::iota(-1, 2)
                | pipe::transform([=](int dy) { return std::pair{dx, dy}; });
        })
        | pipe::join
        | pipe::filter([](auto p) { return p.first != 0 || p.second != 0; })
        | pipe::transform([&](std::pair<int, int> p) {
            return Position(pos_x + p.first, pos_y + p.second);
        })
        | pipe::filter([this](Position pos) {
            return isPositionOnWorld(pos.x(), pos.y()) && isPositionFree(pos);
        })
        | pipe::common;
    return std::vector<Position>(positions.begin(), positions.end());
}

void World::makeTurn()
{
    std::vector<Position> new_positions;
    int number_of_new_positions;
    int random_index;

    srand(time(NULL));
    for (auto& org : organisms_) {
        new_positions = getVectorOfFreePositionsAround(org.position());
        number_of_new_positions = new_positions.size();
        if (number_of_new_positions > 0) {
            random_index = rand() % number_of_new_positions;
            org.position(new_positions[random_index]);
        }
    }
    turn_++;
}

void World::writeWorld(std::string fileName)
{
    TODO("write world");
    (void) fileName;
}

void World::readWorld(std::string fileName)
{
    TODO("read world");
	(void) fileName;
}

World::operator std::string()
{
    std::string result = "\nturn: " + std::to_string(turn()) + "\n";
    std::string spec;

    for (int wY = 0; wY < this->worldY_; ++wY) {
        for (int wX = 0; wX < this->worldX_; ++wX) {
            spec = getOrganismFromPosition(wX, wY);
            if (spec != "")
                result += spec;
            else
                result += separator;
        }
        result += "\n";
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, World& w)
{
    return os << (std::string) w;
}
