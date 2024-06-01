#include "record.hpp"

Record::Record() {
    birth_ = 0;
}

Record::Record(int birth)
{
    birth_ = birth;
}

Record::Record(int birth, int death)
{
    birth_ = birth;
    death_ = death;
}

Record::Record(int birth, std::vector<int> ancestors)
{
    birth_ = birth;
    ancestors_ = ancestors;
}

Record::Record(int birth, int death, std::vector<int> ancestors)
{
    birth_ = birth;
    death_ = death;
    ancestors_ = ancestors;
}

Record::operator std::string()
{
    auto d = death_;
    std::string d_str = (d) ? std::to_string(d.value()) : "not dead yet";

    return "date of birth: " + std::to_string(birth_) + ", date of death: " + d_str;
}

void Record::operator+=(const int& rhs)
{
    ancestors_.push_back(rhs);
}
