#pragma once
#include <optional>
#include <string>
#include <vector>

class Record
{
  private:
    int birth_;
    std::optional<int> death_;
    std::vector<int> ancestors_;

  public:
    Record() : Record(0, 0, {}){};
    Record(int birth) : Record(birth, 0, {}){};
    Record(int birth, int death) : Record(birth, death, {}){};
    Record(int birth, std::vector<int> ancestors)
        : Record(birth, 0, ancestors){};
    Record(int birth, int death, std::vector<int> ancestors);

    operator std::string();

    void death(int d)
    {
        death_ = std::optional(d);
    };
    int birth() const
    {
        return birth_;
    };
    std::optional<int> death()
    {
        return death_;
    };
    std::vector<int> ancestors()
    {
        return ancestors_;
    };

    void operator+=(const int &b); // add ancestors
};

std::ostream &operator<<(std::ostream &os, Record &r);
std::string operator+(const std::string &str, Record record);
