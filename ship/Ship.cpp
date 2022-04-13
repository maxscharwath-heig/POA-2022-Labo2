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
   os << "[" << getModel() << " #" << id << "]" << std::endl;
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

double Ship::getConsumption(double speedWanted, double distance) const {
   if (speedWanted <= 0 || distance <= 0) return 0;

   speedWanted = std::min(speedWanted, getSpeed());
   return (std::pow(getWeight(), 1.0 / 3.0) / 2.0)
          * std::log10(getWeight() * speedWanted)
          * std::log10(distance + 1.0);
}

Ship::Ship(unsigned id, const std::string& nickName) : id(id), nickName(nickName) {}
