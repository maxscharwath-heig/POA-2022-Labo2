#include "Ship.hpp"

Ship::Ship(unsigned long long int weigth, unsigned int speed, const std::string &model, unsigned id) :
        weigth(weigth), speed(speed), model(model), id(id) {}

void Ship::setNickname(const std::string &name) {
    this->nickName = name;
}

std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    return ship.toStream(os);
}

std::ostream &Ship::toStream(std::ostream &os) const {
    if (!nickName.empty()) {
        os << nickName << " ";
    }

    os << "[" << model << " #" << id << "]" << std::endl;
    os << "   weigth : " << weigth << "tons" << std::endl;
    os << "   max speed : " << speed << "MGLT" << std::endl;
    return os;
}

unsigned Ship::getSpeed() const {
    return speed;
}

unsigned long long Ship::getWeight() const {
    return weigth;
}
