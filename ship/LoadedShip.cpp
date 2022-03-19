#include "LoadedShip.hpp"

LoadedShip::LoadedShip(unsigned long long int weigth, unsigned int speed, const std::string& model,
                       unsigned id, double maxLoad, double currentLoad) : Ship(weigth, speed, model, id),
                                                                          maxLoad(maxLoad),
                                                                          currentLoad(currentLoad) {}

std::ostream& LoadedShip::toStream(std::ostream& os) const {
   return Ship::toStream(os) << "   cargo : " << currentLoad << " tons (max : " << maxLoad << ")";
}
