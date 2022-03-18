#include "Squadron.hpp"

void Squadron::setLeader(const Ship& ship) {
 //todo
}

Ship& Squadron::operator[](size_t i) {
    //todo
}

Squadron& Squadron::operator+=(const Ship& ship) {
    Ship* tempArr = new Ship[size + 1];
    for (size_t i = 0; i < size; ++i) {
        tempArr[i] = ships[i];
    }
    tempArr[size] = ship;
    delete[] ships;
    ships = tempArr;
}

Squadron& Squadron::operator-=(const Ship& ship) {
    Ship* tempArr = new Ship[size - 1];
    for (size_t i = 0; i < size; ++i) {
        if (ships[i] != ship) {
            tempArr[i] = ships[i];
        }
    }
    delete[] ships;
    ships = tempArr;
}

Squadron operator+(const Squadron& lhs, const Squadron& rhs) {
    //todo
}

Squadron operator-(const Squadron& lhs, const Squadron& rhs) {
    //todo
}

std::ostream& operator<<(std::ostream& os, const Squadron& squadron) {
    //todo
}
