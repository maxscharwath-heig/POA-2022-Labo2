#include "LoadedShip.hpp"

LoadedShip::LoadedShip(double weight, unsigned int speed, const std::string& model,
                       unsigned id, double maxLoad, double currentLoad) :
      Ship(weight, speed, model, id), maxLoad(maxLoad), currentLoad(currentLoad) {}

double LoadedShip::getWeight() const {
    return Ship::getWeight() + currentLoad;
}

std::ostream& LoadedShip::toStream(std::ostream& os) const {
    return Ship::toStream(os) << "   cargo : " << currentLoad << " tons (max : "
                              << maxLoad << ")";
}
