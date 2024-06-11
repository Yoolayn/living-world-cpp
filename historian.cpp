#include "historian.hpp"
#include <sstream>

int Historian::operator+=(Record r)
{
    int size = m_Records.size();
    m_Records.push_back(r);
    return size;
}

std::optional<Record> Historian::operator[](size_t index)
{
    if (index >= m_Records.size())
        return std::optional<Record>();
    else
        return std::optional(m_Records[index]);
}

Historian::operator std::string()
{
    using namespace std::string_literals;

    std::stringstream ss;
    for (Record r : m_Records)
        ss << r << std::endl;

    if (std::string s = ss.str(); s == ""s)
        return "nothing"s;
    else
        return s;
}

std::ostream &operator<<(std::ostream &os, Historian h)
{
    return os << (std::string)h;
}
