#include "TIELN.hpp"
const std::string TIELN::MODEL = "TIE/LN";
unsigned TIELN::id = 0;

TIELN::TIELN(): Ship(6,100, MODEL, id) {}
