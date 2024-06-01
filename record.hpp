#pragma once
#include <string>
#include <vector>
#include <optional>

class Record
{
private:
    int birth_;
    std::optional<int> death_;
    std::vector<int> ancestors_;
public:
    Record();
    Record(int birth);
    Record(int birth, int death);
    Record(int birth, std::vector<int> ancestors);
    Record(int birth, int death, std::vector<int> ancestors);

    operator std::string();

    void death(int d) { death_ = std::optional(d); };
    int birth() const { return birth_; };
    std::optional<int> death() { return death_; };
    std::vector<int> ancestors() { return ancestors_; };

    void operator +=(const int& b); // add ancestors
};