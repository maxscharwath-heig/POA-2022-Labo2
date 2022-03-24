#include <iomanip>
#include <valarray>
#include "Ship.hpp"
#include "../Constants.hpp"

Ship::Ship(double weight, unsigned int speed, const std::string& model, unsigned id)
      : weight(weight), speed(speed), model(model), id(id) {}

void Ship::setNickname(const std::string& name) {
    this->nickName = name;
}

std::ostream& operator<<(std::ostream& os, const Ship& ship) {
    return ship.toStream(os);
}

std::ostream& Ship::toStream(std::ostream& os) const {
    if (!nickName.empty()) {
        os << nickName << " ";
    }

    os << "[" << model << " #" << id << "]" << std::endl;
    os << "   weight : " << std::fixed << std::setprecision(2) << getWeight()
       << " " << UNITS_WEIGHT << std::endl;
    os << "   max speed : " << std::fixed << std::setprecision(2) << getSpeed()
       << " " << UNITS_SPEED << std::endl;
    return os;
}

unsigned Ship::getSpeed() const {
    return speed;
}

double Ship::getWeight() const {
    return weight;
}

double Ship::getConsumption(unsigned speedWanted, unsigned long distance) const {
    speedWanted = std::min(speedWanted, getSpeed());
    return (std::pow(getWeight(), 1.0 / 3.0) / 2)
           * std::log10(getWeight() * speedWanted)
           * std::log10(distance + 1.0);
}
