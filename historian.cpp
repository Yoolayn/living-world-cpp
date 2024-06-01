#include "historian.hpp"
#include "record.hpp"

int Historian::operator+=(Record r)
{
    int size = records_.size();
    records_.push_back(r);
    return size;
}
