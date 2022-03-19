#include "StarDestroyer.hpp"

const std::string StarDestroyer::MODEL = "Super-class Star Destroyer";
unsigned StarDestroyer::id = 0;

StarDestroyer::StarDestroyer(double currentLoad) : LoadedShip(9000000000, 40, MODEL, id, 250000, currentLoad) {}
