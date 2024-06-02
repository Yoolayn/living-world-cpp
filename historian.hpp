#include "record.hpp"
#include <ostream>
#include <vector>
#include <optional>

class Historian
{
private:
    std::vector<Record> records_;
public:
    Historian() : records_() {};
    std::optional<Record> operator[](size_t index); // get a record

    void updateRecord(int index, Record record);
    int operator+=(Record record); // add a record
    operator std::string();
};

std::ostream& operator<<(std::ostream& os, Historian h);
