#pragma once
#include <cmath>
#include <ostream>
#include <string>

class Position
{
  private:
    int x_;
    int y_;

  public:
    Position(int x, int y);
    Position() : x_(0), y_(0){};

    int x() const
    {
        return x_;
    };
    void x(int x)
    {
        x_ = x;
    };
    int y() const
    {
        return y_;
    };
    void y(int y)
    {
        y_ = y;
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
