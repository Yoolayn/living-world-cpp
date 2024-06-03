#include "world.hpp"
#include "organism.hpp"
#include "position.hpp"
#include "todo.hpp"
#include <iostream>
#include <optional>
#include <ranges>
// #include <fstream>

World::World(int worldX, int worldY)
    : worldX_(worldX), worldY_(worldY), turn_(0)
{
    organisms_ = std::vector<Organism>();
}

std::optional<Species> World::getOrganismFromPosition(Position target)
{
    for (Organism org : this->organisms_)
        if (org.position().x() == target.x() &&
            org.position().y() == target.y())
            return org.species();
    return std::optional<Species>();
}

bool World::isPositionOnWorld(Position p)
{
    return p.x() >= 0 && p.y() >= 0 && p.x() < worldX() && p.y() < worldY();
}

bool World::isPositionFree(Position position)
{
    return !(bool)this->getOrganismFromPosition(position);
}

void World::operator+=(Organism organism)
{
    organisms_.push_back(organism);
}

consteval auto offsets()
{
    namespace pipe = std::views;

    auto positions =
        pipe::iota(-1, 2) | pipe::transform([](int dx) {
            return pipe::iota(-1, 2) |
                   pipe::transform([=](int dy) { return std::pair{dx, dy}; });
        }) |
        pipe::join;

    return positions;
}

std::vector<Position> World::getVectorOfPositionsAround(Position position)
{
    namespace pipe = std::views;

    int pos_x = position.x(), pos_y = position.y();

    auto positions =
        offsets() |
        pipe::filter([](auto p) { return p.first != 0 || p.second != 0; }) |
        pipe::transform([&](std::pair<int, int> p) {
            return Position(pos_x + p.first, pos_y + p.second);
        }) |
        pipe::filter([this](Position pos) { return isPositionOnWorld(pos); }) |
        pipe::common;

    return std::vector<Position>(positions.begin(), positions.end());
}

void World::makeTurn()
{
    std::vector<Position> new_positions;
    int number_of_new_positions;
    int random_index;

    srand(time(NULL));
    for (auto &org : organisms_) {
        new_positions = getVectorOfPositionsAround(org.position());
        random_index = rand() % new_positions.size();
        auto pos = new_positions[random_index];
        if (auto new_org = getOrganismFromPosition(pos)) switch (*new_org) {
            case plant:
                break;
            case animal:
                break;
            case organism:
                break;
            }
        // org.position(new_positions[random_index]);
    }
    turn_++;
}

void World::operator()()
{
    makeTurn();
}

void World::writeWorld(std::string fileName)
{
    TODO("write world");
    (void)fileName;
}

void World::readWorld(std::string fileName)
{
    TODO("read world");
    (void)fileName;
}

World::operator std::string()
{
    std::string result = "\nturn: " + std::to_string(turn()) + "\n";
    std::optional<Species> spec;

    for (int wY = 0; wY < this->worldY_; ++wY) {
        for (int wX = 0; wX < this->worldX_; ++wX) {
            if ((spec = getOrganismFromPosition(Position{wX, wY})))
                result += *spec;
            else
                result += separator;
        }
        result += "\n";
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, World &w)
{
    return os << (std::string)w;
}
