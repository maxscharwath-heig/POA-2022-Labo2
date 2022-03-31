#include <iomanip>
#include <climits>
#include "Squadron.hpp"
#include "Constants.hpp"

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

Squadron::Squadron(const std::string& name) : name(name), leader(nullptr) {}

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
    if (!it.hasNext()) {
        return 0;
    }
    while (it.hasNext()) {
        const Ship& ship = *it.next();
        if (ship.getSpeed() < maxSpeed) {
            maxSpeed = ship.getSpeed();
        }
    }
    return maxSpeed;
}

double Squadron::getTotalWeight() const {
    double totalWeight = 0;
    auto it = members.getIterator();
    while (it.hasNext()) {
        const Ship& ship = *it.next();
        totalWeight += ship.getWeight();
    }
    return totalWeight;
}

std::ostream& operator<<(std::ostream& os, const Squadron& squadron) {
    os << "Squadron: " << squadron.name << std::endl
       << "   max speed: " << std::fixed << std::setprecision(2)
       << squadron.getMaxSpeed() << " " << UNITS_SPEED << std::endl
       << "   total weight: " << std::fixed << std::setprecision(2)
       << squadron.getTotalWeight() << " " << UNITS_WEIGHT << std::endl
       << std::endl;
    if (squadron.leader == nullptr) {
        os << "-- No leader" << std::endl;
    } else {
        os << "-- Leader :" << std::endl
           << *squadron.leader << std::endl;
    }
    auto it = squadron.members.getIterator();
    if (!it.hasNext()) {
        os << "-- No members" << std::endl;
    } else {
        os << "-- Members :" << std::endl;
        while (it.hasNext()) {
            const Ship* ship = it.next();
            if (ship == squadron.leader) continue;
            os << *ship << std::endl;
        }
    }
    return os;
}

double Squadron::getConsumption(unsigned int speedWanted, unsigned long distance)
const {
    double consumption = 0;
    auto it = members.getIterator();
    while (it.hasNext()) {
        const Ship& ship = *it.next();
        consumption += ship.getConsumption(speedWanted, distance);
    }
    return consumption;
}

void Squadron::removeLeader() {
    leader = nullptr;
}
