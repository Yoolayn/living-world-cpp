#include "record.hpp"
#include <optional>
#include <ostream>
#include <vector>

class Historian
{
  private:
    std::vector<Record> m_Records;

  public:
    Historian() : m_Records(){};
    std::optional<Record> operator[](size_t index); // get a record

    void updateRecord(int index, Record record);
    int operator+=(Record record); // add a record
    operator std::string();
};

std::ostream &operator<<(std::ostream &os, Historian h);
