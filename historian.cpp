#include "historian.hpp"
#include <sstream>

int Historian::operator+=(Record r)
{
    int size = records_.size();
    records_.push_back(r);
    return size;
}

std::optional<Record> Historian::operator[](size_t index)
{
    if (index >= records_.size())
        return std::optional<Record>();
    else
        return std::optional(records_[index]);
}

Historian::operator std::string()
{
    using namespace std::string_literals;
    std::stringstream ss;
    for (Record r : records_)
        ss << (std::string) r << std::endl;

    return ss.str();
}
