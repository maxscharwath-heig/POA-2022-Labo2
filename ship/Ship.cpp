#include <iomanip>
#include <valarray>
#include "Ship.hpp"
#include "../Constants.hpp"

// Functions
std::ostream& operator<<(std::ostream& os, const Ship& ship) {
   return ship.toStream(os);
}

// Methods
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

void Ship::setNickname(const std::string& name) {
   this->nickName = name;
}

const std::string& Ship::getNickname() const {
   return nickName;
}

double Ship::getSpeed() const {
   return speed;
}

double Ship::getConsumption(double speedWanted, double distance) const {
   if (speedWanted <= 0 || distance <= 0) return 0;

   speedWanted = std::min(speedWanted, speed);
   return (std::pow(getWeight(), 1.0 / 3.0) / 2.0)
          * std::log10(getWeight() * speedWanted)
          * std::log10(distance + 1.0);
}

double Ship::getWeight() const {
   return weight;
}

Ship::Ship(double weight, double speed, const std::string& model, unsigned id)
        : weight(weight), speed(speed), model(model), id(id) {}
