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

Squadron::Squadron(std::string name) : name(std::move(name)) {
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

unsigned Squadron::getMaxSpeed() const {
    unsigned maxSpeed = UINT_MAX;
    auto it = members.getIterator();
    while (it.hasNext()) {
        const Ship& ship = *it.next();
        if (ship.getSpeed() < maxSpeed) {
            maxSpeed = ship.getSpeed();
        }
    }
    return maxSpeed;
}

unsigned long long Squadron::getTotalWeight() const {
    unsigned long long totalWeight = 0;
    auto it = members.getIterator();
    while (it.hasNext()) {
        const Ship& ship = *it.next();
        totalWeight += ship.getWeight();
    }
    return totalWeight;
}

std::ostream& operator<<(std::ostream& os, const Squadron& squadron) {
    os << "Squadron: " << squadron.name << std::endl
       << "\t max speed: " << squadron.getMaxSpeed() << " MGLT" << std::endl
       << "\t total weight: " << squadron.getTotalWeight() << " tons"
       << std::endl
       << "-- Leader :" << std::endl
       << *squadron.leader << std::endl
       << "-- Members :" << std::endl;
    auto it = squadron.members.getIterator();
    while (it.hasNext()) {
        os << *it.next() << std::endl;
    }
    return os;
}
