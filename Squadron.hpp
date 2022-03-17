#ifndef POA___LABO_2_SQUADRON_HPP
#define POA___LABO_2_SQUADRON_HPP

#include <string>
#include "ship/Ship.hpp"

class Squadron;

Squadron operator+(const Squadron& lhs, const Squadron& rhs);
Squadron operator-(const Squadron& lhs, const Squadron& rhs);
std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

class Squadron {

public:
    void setLeader(const Ship& ship);
    Ship& operator[](size_t i);
    Squadron& operator+=(const Ship& ship);
    Squadron& operator-=(const Ship& ship);
private:
    const std::string name;
    Ship* ships;
    size_t size;
    Ship* leader; // can be nullptr
};


#endif //POA___LABO_2_SQUADRON_HPP
