#include <iomanip>
#include "LoadedShip.hpp"
#include "../Constants.hpp"

LoadedShip::LoadedShip(double weight, unsigned int speed, const std::string& model,
                       unsigned id, double maxLoad, double currentLoad) :
      Ship(weight, speed, model, id), maxLoad(maxLoad), currentLoad(currentLoad) {

    if (currentLoad > maxLoad) {
        throw std::runtime_error("The load of a ship cannot be greater than its max capacity");
    }
}

double LoadedShip::getWeight() const {
    return Ship::getWeight() + currentLoad;
}

std::ostream& LoadedShip::toStream(std::ostream& os) const {
    return Ship::toStream(os)
          << "   cargo : "
          << std::fixed << std::setprecision(2) << currentLoad
          << " " << UNITS_WEIGHT << " (max : "
          << std::fixed << std::setprecision(2) << maxLoad
          << ")";
}
