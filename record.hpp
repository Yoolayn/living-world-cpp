#pragma once
#include <string>
#include <optional>

class Record
{
private:
    int birth;
    std::optional<int> death;
public:
    Record();
    Record(int birth);
    Record(int birth, int death);
    void setDeath(int death);
    std::string toString();
    int getBirth();
    std::optional<int> getDeath();
};
