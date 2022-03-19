#ifndef POA___LABO_2_SQUADRON_HPP
#define POA___LABO_2_SQUADRON_HPP

#include <string>
#include "utility/LinkedList.hpp"
#include "ship/Ship.hpp"

class Squadron;

//Squadron operator+(const Squadron& lhs, const Ship& rhs);
//Squadron operator-(const Squadron& lhs, const Ship& rhs);
//std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

class Squadron {

public:
    Squadron(const std::string& name);
    void setLeader(const Ship& ship);
    const Ship& operator[](int i);
    Squadron& operator+=(const Ship& ship);
    Squadron& operator-=(const Ship& ship);
private:
    const std::string name;
    LinkedList<const Ship*> ships;
    const Ship* leader; // can be nullptr
};


#endif //POA___LABO_2_SQUADRON_HPP
