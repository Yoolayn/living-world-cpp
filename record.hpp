#pragma once
#include <optional>
#include <string>
#include <vector>

class Record
{
  private:
    int m_Birth;
    std::optional<int> m_Death;
    std::vector<size_t> m_Ancestors;

  public:
    Record() : Record(0, std::optional<int>(), {}){};
    Record(int birth) : Record(birth, std::optional<int>(), {}){};
    Record(int birth, std::optional<int> death) : Record(birth, death, {}){};
    Record(int birth, std::vector<size_t> ancestors) : Record(birth, std::optional<int>(), ancestors){};
    Record(int birth, std::optional<int> death, std::vector<size_t> ancestors);

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
    std::vector<size_t> ancestors()
    {
        return m_Ancestors;
    };

    void operator+=(size_t b); // add ancestors
};

std::ostream &operator<<(std::ostream &os, Record &r);
std::string operator+(const std::string &str, Record record);
