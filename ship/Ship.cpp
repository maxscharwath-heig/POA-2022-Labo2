#include "Ship.hpp"

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
    os << "   weight : " << getWeight() << " tons" << std::endl;
    os << "   max speed : " << getSpeed() << " MGLT" << std::endl;
    return os;
}

unsigned Ship::getSpeed() const {
    return speed;
}

double Ship::getWeight() const {
    return weight;
}
