#include "record.hpp"
#include <memory>
#include <optional>
#include <vector>

class Historian
{
  private:
    std::vector<std::shared_ptr<Record>> m_Records;

  public:
    Historian() : m_Records(){};
    std::optional<std::shared_ptr<Record>> operator[](size_t index); // get a record

    void updateRecord(size_t index, std::shared_ptr<Record> record);
    size_t operator+=(std::shared_ptr<Record> record); // add a record
    std::vector<std::shared_ptr<Record>>& records()
    {
        return m_Records;
    }
};
