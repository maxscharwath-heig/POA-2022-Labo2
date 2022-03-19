#include "TIELN.hpp"

const std::string TIELN::MODEL = "TIE/LN";
const unsigned long long TIELN::WEIGHT = 6;
const unsigned TIELN::SPEED = 100;
unsigned TIELN::id = 0;

TIELN::TIELN() : Ship(WEIGHT, SPEED, MODEL, ++id) {}
