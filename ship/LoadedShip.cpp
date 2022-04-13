#include <iomanip>
#include "LoadedShip.hpp"
#include "../Constants.hpp"

std::ostream& LoadedShip::toStream(std::ostream& os) const {
   return Ship::toStream(os)
           << "   cargo : "
           << std::fixed << std::setprecision(2) << currentLoad
           << " " << UNITS_WEIGHT << " (max : "
           << std::fixed << std::setprecision(2) << maxLoad
           << ")";
}

double LoadedShip::getWeight() const {
   return Ship::getWeight() + currentLoad;
}

void LoadedShip::setLoad(double load) {
   if (currentLoad < 0) {
      throw std::runtime_error("The load of a ship cannot be negative");
   }

   if (currentLoad > maxLoad) {
      throw std::runtime_error("The load of a ship cannot be bigger than its max capacity");
   }

   this->currentLoad = load;
}

LoadedShip::LoadedShip(double weight, double speed, const std::string& model,
                       unsigned id, double maxLoad, double currentLoad) :
        Ship(weight, speed, model, id), maxLoad(maxLoad) {

   setLoad(currentLoad);
}
