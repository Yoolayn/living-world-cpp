#include "record.hpp"

Record::Record() {
    birth = 0;
}

Record::Record(int birth)
{
    this->birth = birth;
}

Record::Record(int birth, int death)
{
    this->birth = birth;
    this->death = death;
}

int Record::getBirth()
{
    return birth;
}

std::optional<int> Record::getDeath()
{
    return death;
}

void Record::setDeath(int death)
{
    this->death = death;
}

std::string Record::toString()
{
    auto d = getDeath();
    std::string d_str = (d) ? std::to_string(d.value()) : "not dead yet";

    return "date of birth: " + std::to_string(getBirth()) + ", date of death: " + d_str;
}
