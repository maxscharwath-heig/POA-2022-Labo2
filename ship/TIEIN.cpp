#include "TIEIN.hpp"
const std::string TIEIN::MODEL = "TIE/IN";
unsigned TIEIN::id = 0;

TIEIN::TIEIN(): Ship(5, 110, MODEL, id) {}
