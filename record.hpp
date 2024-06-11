#pragma once
#include <optional>
#include <string>
#include <vector>

class Record
{
  private:
    int m_Birth;
    std::optional<int> m_Death;
    std::vector<int> m_Ancestors;

  public:
    Record() : Record(0, 0, {}){};
    Record(int birth) : Record(birth, 0, {}){};
    Record(int birth, int death) : Record(birth, death, {}){};
    Record(int birth, std::vector<int> ancestors) : Record(birth, 0, ancestors){};
    Record(int birth, int death, std::vector<int> ancestors);

    operator std::string();

    void death(int d)
    {
        m_Death = std::optional(d);
    };
    int birth() const
    {
        return m_Birth;
    };
    std::optional<int> death()
    {
        return m_Death;
    };
    std::vector<int> ancestors()
    {
        return m_Ancestors;
    };

    void operator+=(const int &b); // add ancestors
};

std::ostream &operator<<(std::ostream &os, Record &r);
std::string operator+(const std::string &str, Record record);
