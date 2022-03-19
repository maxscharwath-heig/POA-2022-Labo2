#ifndef POA___LABO_2_SQUADRON_HPP
#define POA___LABO_2_SQUADRON_HPP

#include <string>
#include "ship/Ship.hpp"
#include "utility/LinkedList.cpp" //todo: pourquoi cpp et pas hpp?

class Squadron {
public:
    explicit Squadron(std::string name);

    void setLeader(const Ship& ship);

    const Ship& operator[](int i);

    Squadron& operator+=(const Ship& ship);

    Squadron& operator-=(const Ship& ship);

    friend std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

private:
    const std::string name;
    LinkedList<const Ship*> members;
    const Ship* leader; // can be nullptr
    double getMaxSpeed() const;

    double getTotalWeight() const;
};

Squadron operator+(const Squadron& lhs, const Ship& rhs);

Squadron operator-(const Squadron& lhs, const Ship& rhs);

#endif //POA___LABO_2_SQUADRON_HPP
