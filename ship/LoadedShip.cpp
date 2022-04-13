#include <iomanip>
#include "LoadedShip.hpp"
#include "../Constants.hpp"

std::ostream& LoadedShip::toStream(std::ostream& os) const {
   return Ship::toStream(os)
           << "   cargo : "
           << std::fixed << std::setprecision(2) << currentLoad
           << " " << UNITS_WEIGHT << " (max : "
           << std::fixed << std::setprecision(2) << maxLoad << ")";
}

double LoadedShip::getWeight() const {
   return currentLoad;
}

void LoadedShip::setLoad(double load) {
   if (load < 0) {
      throw std::runtime_error("The load of a ship cannot be negative");
   }

   if (load > maxLoad) {
      throw std::runtime_error("The load of a ship cannot be bigger than its max capacity");
   }

   this->currentLoad = load;
}

LoadedShip::LoadedShip(unsigned int id, double maxLoad, double currentLoad, const std::string& nickName)
        : Ship(id, nickName), maxLoad(maxLoad) {
   setLoad(currentLoad);
}
