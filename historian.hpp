#include "record.hpp"
#include <vector>

class Historian
{
private:
    std::vector<Record> records_;
public:
    Historian() : records_() {};
    Record record(int index) { return records_[index]; };

    int operator+=(Record record); // add a record
    void updateRecord(int index, Record record);
};
