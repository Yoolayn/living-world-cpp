#include "world.hpp"
#include "organism.hpp"
#include "position.hpp"
#include "todo.hpp"
#include <cstddef>
#include <iostream>
#include <optional>
#include <ranges>
// #include <fstream>

World::World(int worldX, int worldY) : worldX_(worldX), worldY_(worldY), turn_(0), organisms_(){};

std::optional<Organism> World::getOrganismFromPosition(Position target)
{
    for (Organism org : this->organisms_)
        if (org.position().x() == target.x() && org.position().y() == target.y()) return org;
    return std::optional<Organism>();
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

void World::operator-=(Organism organism)
{
    auto it = std::find(organisms_.begin(), organisms_.end(), organism);
    if (it != organisms_.end()) organisms_.erase(it);
}

constexpr auto offsets(int range)
{
    namespace pipe = std::views;

    auto positions
        = pipe::iota(-range, range + 1) | pipe::transform([range](int dx) {
              return pipe::iota(-range, range + 1) | pipe::transform([dx](int dy) { return std::pair{dx, dy}; });
          })
          | pipe::join;

    return positions;
}

std::vector<Position> World::getVectorOfPositionsAround(Position position, bool free, int range)
{
    namespace pipe = std::views;

    int pos_x = position.x(), pos_y = position.y();

    auto positions
        = offsets(range) | pipe::filter([](auto p) { return p.first != 0 || p.second != 0; })
          | pipe::transform([&](std::pair<int, int> p) { return Position(pos_x + p.first, pos_y + p.second); })
          | pipe::filter(
              [this, free](Position pos) { return isPositionOnWorld(pos) && free ? isPositionFree(pos) : true; })
          | pipe::common;

    return std::vector<Position>(positions.begin(), positions.end());
}

void World::makeTurn()
{
    std::vector<Position> new_positions;
    int random_index;
    srand(time(NULL));

    std::vector<Organism> copy;
    size_t s = organisms().size();

    for (size_t i = s; i > 0; --i) {
        if (i >= organisms().size()) break;
        Organism *org = &organisms_[i];
        new_positions = getVectorOfPositionsAround(org->position(), false, 1);
        random_index = rand() % new_positions.size();
        Position pos = new_positions[random_index];

        if (auto new_org = getOrganismFromPosition(pos)) {
            if (std::find(organisms_.begin(), organisms_.end(), *org) != organisms_.end())
                if (!action(org, &*new_org)) continue;
            org->position(pos);
        } else {
            org->position(pos);
        }
    }
    turn_++;
}

bool World::action(Organism *org, Organism *new_org)
{
    switch (org->act(*new_org)) {
    case Action::breed: {
        auto child = *org + *new_org;
        if (!child) return true;
        auto free_positions = getVectorOfPositionsAround(org->position(), true, 1);
        child->position(free_positions[rand() & free_positions.size()]);
        *this += *child;
        return true;
    } break;
    case Action::clone: {
        auto child = org->clone();
        if (!child) return true;
        auto free_positions = getVectorOfPositionsAround(org->position(), true, 1);
        child->position(free_positions[rand() & free_positions.size()]);
        *this += *child;
        return true;
    } break;
    case Action::die:
        *this -= *org;
        TODO("report death");
        return false;
        break;
    case Action::kill:
        *this -= *new_org;
        TODO("report death");
        return true;
        break;
    case Action::eat:
        TODO("nom nom");
        *this -= *new_org;
        return true;
        TODO("report death");
        break;
    default:
        TODO("DEFAULT");
        return true;
        break;
    }
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
    std::optional<Organism> spec;

    for (int wY = 0; wY < this->worldY_; ++wY) {
        for (int wX = 0; wX < this->worldX_; ++wX) {
            if ((spec = getOrganismFromPosition(Position{wX, wY}))) {
                result += to_string(spec->species());
            } else
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
