#include "StarDestroyer.hpp"

const std::string StarDestroyer::MODEL = "Super-class Star Destroyer";
const unsigned long long StarDestroyer::WEIGHT = 9000000000;
const unsigned StarDestroyer::SPEED = 40;
const double StarDestroyer::MAX_LOAD = 250000;
unsigned StarDestroyer::id = 0;

StarDestroyer::StarDestroyer(double currentLoad) : LoadedShip(WEIGHT, SPEED, MODEL, ++id, MAX_LOAD, currentLoad) {}
