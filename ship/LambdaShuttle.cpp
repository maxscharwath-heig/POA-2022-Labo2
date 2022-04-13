#include "LambdaShuttle.hpp"

const std::string LambdaShuttle::MODEL = "Lambda-class shuttle";
const double LambdaShuttle::WEIGHT = 360;
const double LambdaShuttle::SPEED = 54;
const double LambdaShuttle::MAX_LOAD = 80;
unsigned LambdaShuttle::id = 0;

LambdaShuttle::LambdaShuttle(double currentLoad, const std::string& nickName)
        : LoadedShip(++id, MAX_LOAD, currentLoad, nickName) {}


double LambdaShuttle::getSpeed() const {
   return SPEED;
}

double LambdaShuttle::getWeight() const {
   return LoadedShip::getWeight() + WEIGHT;
}

const std::string& LambdaShuttle::getModel() const {
   return MODEL;
}
