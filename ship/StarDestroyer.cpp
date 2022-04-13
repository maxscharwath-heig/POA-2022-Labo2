#include "StarDestroyer.hpp"

const std::string StarDestroyer::MODEL = "Super-class Star Destroyer";
const double StarDestroyer::WEIGHT = 9000000000;
const double StarDestroyer::SPEED = 40;
const double StarDestroyer::MAX_LOAD = 250000;
unsigned StarDestroyer::id = 0;

StarDestroyer::StarDestroyer(double currentLoad, const std::string& nickName)
        : LoadedShip(++id, MAX_LOAD, currentLoad, nickName) {}

double StarDestroyer::getSpeed() const {
   return SPEED;
}

double StarDestroyer::getWeight() const {
   return LoadedShip::getWeight() + WEIGHT;
}

const std::string& StarDestroyer::getModel() const {
   return MODEL;
}
