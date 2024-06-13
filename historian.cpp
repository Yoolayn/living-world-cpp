#include "historian.hpp"

size_t Historian::operator+=(std::shared_ptr<Record> record)
{
    size_t size = m_Records.size();
    m_Records.push_back(std::move(record));
    return size;
}

void Historian::updateRecord(size_t index, std::shared_ptr<Record> record)
{
    m_Records[index] = std::move(record);
}

std::optional<std::shared_ptr<Record>> Historian::operator[](size_t index)
{
    if (index >= m_Records.size()) {
        return std::optional<std::shared_ptr<Record>>();
    } else {
        return std::optional(m_Records[index]);
    }
}
