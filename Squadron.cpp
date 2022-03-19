#include "Squadron.hpp"

void Squadron::setLeader(const Ship& ship) {
    if (!members.contains(&ship)) {
        members.add(&ship);
    }
    leader = &ship;
}

const Ship& Squadron::operator[](int i) {
    return *members[i];
}

Squadron& Squadron::operator+=(const Ship& ship) {
    members.add(&ship);
    return *this;
}

Squadron& Squadron::operator-=(const Ship& ship) {
    if (members.remove(&ship)) {
        //if correctly removed, check if leader is removed
        if (leader == &ship) {
            leader = nullptr;
        }
    }
    return *this;
}

Squadron::Squadron(std::string name): name(std::move(name)) {
    leader = nullptr;
}

Squadron operator+(const Squadron& lhs, const Ship& rhs) {
    Squadron result = lhs;
    result += rhs;
    return result;
}

Squadron operator-(const Squadron& lhs, const Ship& rhs) {
    Squadron result = lhs;
    result -= rhs;
    return result;
}

double Squadron::getMaxSpeed() const {
    return 0;
}

double Squadron::getTotalWeight() const {
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Squadron& squadron) {
    return os << "Squadron: " << squadron.name << std::endl
              << "\t max speed: " << squadron.getMaxSpeed() << " MGLT" << std::endl
              << "\t total weight: " << squadron.getTotalWeight() << " tons"
              << std::endl
              << std::endl
              << "-- Leader :" << std::endl
              << squadron.leader << std::endl
              << std::endl
              << "-- Members :" << std::endl;
    auto it = squadron.members.getIterator();
    while (it.hasNext()) {
        os << it.next() << std::endl;
    }
}
