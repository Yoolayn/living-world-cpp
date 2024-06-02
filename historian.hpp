#include "record.hpp"
#include <vector>
#include <optional>

class Historian
{
private:
    std::vector<Record> records_;
public:
    Historian() : records_() {};
    // Record record(int index) { return records_[index]; };
    std::optional<Record> operator[](size_t index); // get a record

    void updateRecord(int index, Record record);
    int operator+=(Record record); // add a record
    operator std::string();
};
