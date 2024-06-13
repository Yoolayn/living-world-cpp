#include "world.hpp"
#include "macros.hpp"
#include "organism.hpp"
#include "position.hpp"
#include <cstddef>
#include <iostream>
#include <optional>

World::World(int worldX, int worldY) : m_WorldX(worldX), m_WorldY(worldY), m_Turn(0), m_Organisms(){};

std::optional<Organism *> World::getOrganismFromPosition(Position target)
{
    for (auto &org : this->m_Organisms)
        if (org->position().x() == target.x() && org->position().y() == target.y()) return org.get();
    return std::nullopt;
}

bool World::isPositionOnWorld(Position p)
{
    return p.x() >= 0 && p.y() >= 0 && p.x() < worldX() && p.y() < worldY();
}

bool World::isPositionFree(Position position)
{
    return !(bool)this->getOrganismFromPosition(position);
}

void World::operator+=(std::unique_ptr<Organism> organism)
{
    m_Organisms.push_back(std::move(organism));
}

void World::operator-=(Organism *organism)
{
    auto it = std::find_if(m_Organisms.begin(), m_Organisms.end(),
                           [organism](const std::unique_ptr<Organism> &x) { return x.get() == organism; });
    if (it != m_Organisms.end()) m_Organisms.erase(it);
}

std::vector<Position> World::getVectorOfPositionsAround(Position position, bool free, int range)
{
    int pos_x = position.x(), pos_y = position.y();
    std::vector<Position> result;

    for (int x = -range; x < range + 1; ++x)
        for (int y = -range; y < range + 1; ++y)
            if ((x != 0 || y != 0) && isPositionOnWorld(Position{pos_x + x, pos_y + y}))
                result.push_back(Position{pos_x + x, pos_y + y});

    if (free) {
        auto iter = std::remove_if(result.begin(), result.end(), [this](Position p) { return !isPositionFree(p); });
        result.erase(iter, result.end());
    }

    return result;
}

void World::makeTurn()
{
    std::vector<Position> new_positions;
    int random_index;
    srand(time(NULL));

    size_t s = organisms().size();

    for (size_t i = s - 1; i > 0; --i) {
        if (i >= organisms().size()) break;
        Organism *org = m_Organisms[i].get();
        new_positions = getVectorOfPositionsAround(org->position(), false, org->range());
        random_index = rand() % new_positions.size();
        Position pos = new_positions[random_index];

        if (auto new_org = getOrganismFromPosition(pos)) {
            if (std::find_if(m_Organisms.begin(), m_Organisms.end(),
                             [org](const std::unique_ptr<Organism> &x) { return x.get() == org; })
                != m_Organisms.end()) {
                Action a = org->act(**new_org);
                action(a, *org, *new_org);
                if (a == Action::die) continue;
            }
            org->move(pos);
        } else {
            org->move(pos);
        }
    }
    m_Turn++;
}

bool World::action(Action a, Organism &org, Organism *new_org)
{
    switch (a) {
    case Action::breed: {
        auto child = org + new_org;
        if (!child) return true;
        auto free_positions = getVectorOfPositionsAround(org.position(), true, org.range());
        (*child)->move(free_positions[rand() & free_positions.size()]);
        *this += std::move(*child);
        return true;
    } break;
    case Action::clone: {
        auto child = org.clone();
        if (!child) return true;
        auto free_positions = getVectorOfPositionsAround(org.position(), true, org.range());
        (*child)->move(free_positions[rand() & free_positions.size()]);
        *this += std::move(*child);
        return true;
    } break;
    case Action::die:
        *this -= &org;
        TODO("report death");
        return false;
        break;
    case Action::kill:
        *this -= new_org;
        TODO("report death");
        return true;
        break;
    case Action::eat:
        LOG("eating");
        *this -= new_org;
        return true;
        TODO("report death");
        break;
    default:
        return true;
        break;
    }
}

void World::operator()()
{
    makeTurn();
    std::cout << *this;
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
    std::optional<Organism *> spec;

    for (int wY = 0; wY < this->m_WorldY; ++wY) {
        for (int wX = 0; wX < this->m_WorldX; ++wX) {
            if ((spec = getOrganismFromPosition(Position{wX, wY}))) {
                result += species_to_string((*spec)->species());
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
