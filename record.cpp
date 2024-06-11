#include "record.hpp"

Record::Record(int birth, int death, std::vector<int> ancestors)
    : m_Birth(birth), m_Death(death), m_Ancestors(ancestors){};

Record::operator std::string()
{
    auto d = m_Death;
    std::string d_str = (d) ? std::to_string(d.value()) : "not dead yet";

    return "date of birth: " + std::to_string(m_Birth) + ", date of death: " + d_str;
}

void Record::operator+=(const int &rhs)
{
    m_Ancestors.push_back(rhs);
}

std::ostream &operator<<(std::ostream &os, Record &r)
{
    return os << (std::string)r;
}

std::string operator+(const std::string &str, Record record)
{
    return str + (std::string)record;
}
