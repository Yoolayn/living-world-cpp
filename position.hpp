#pragma once
#include <cmath>
#include <ostream>
#include <string>

class Position
{
  private:
    int m_X;
    int m_Y;

  public:
    Position(int x, int y);
    Position() : m_X(0), m_Y(0){};

    int x() const
    {
        return m_X;
    };
    void x(int x)
    {
        m_X = x;
    };
    int y() const
    {
        return m_Y;
    };
    void y(int y)
    {
        m_Y = y;
    };

    operator std::string();

    double distance(Position position);
    double distance_sq(Position position);
    void move(int dx, int dy);
    void move(Position p);

    bool operator==(Position p);
};

std::ostream &operator<<(std::ostream &os, Position &p);
std::string operator+(const std::string &str, Position position);
