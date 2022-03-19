#include "LambdaShuttle.hpp"

const std::string LambdaShuttle::MODEL = "Lambda-class shuttle";
unsigned LambdaShuttle::id = 0;

LambdaShuttle::LambdaShuttle(double currentLoad) : LoadedShip(360, 54, MODEL, id, 80, currentLoad) {}
