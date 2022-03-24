#include "LambdaShuttle.hpp"

const std::string LambdaShuttle::MODEL = "Lambda-class shuttle";
const double LambdaShuttle::WEIGHT = 360;
const unsigned LambdaShuttle::SPEED = 54;
const double LambdaShuttle::MAX_LOAD = 80;
unsigned LambdaShuttle::id = 0;

LambdaShuttle::LambdaShuttle(double currentLoad) : LoadedShip(WEIGHT, SPEED, MODEL,
                                                              ++id, MAX_LOAD,
                                                              currentLoad) {}
