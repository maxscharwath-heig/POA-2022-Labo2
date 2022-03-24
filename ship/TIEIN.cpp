#include "TIEIN.hpp"

const std::string TIEIN::MODEL = "TIE/IN";
const double TIEIN::WEIGHT = 5;
const unsigned TIEIN::SPEED = 110;
unsigned TIEIN::id = 0;

TIEIN::TIEIN() : Ship(WEIGHT, SPEED, MODEL, ++id) {}
