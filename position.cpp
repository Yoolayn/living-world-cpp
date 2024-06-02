#include "position.hpp"

Position::Position(int x, int y)
{
    this->x(x);
    this->y(y);
}

Position::operator std::string()
{
    return "(" + std::to_string(x()) + ", " + std::to_string(y()) + ")";
}

double Position::distance(Position position)
{
    return std::sqrt(Position::distance_sq(position));
}

double Position::distance_sq(Position position)
{
    double dx = (double)this->x() - (double)position.x();
    double dy = (double)this->y() - (double)position.y();
    return (dx * dx) + (dy * dy);
}

void Position::move(int dx, int dy)
{
    x(x() + dx);
    y(y() + dy);
}

std::ostream& operator<<(std::ostream& os, Position& p)
{
    return os << (std::string) p;
}
