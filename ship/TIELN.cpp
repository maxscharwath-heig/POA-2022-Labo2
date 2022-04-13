#include "TIELN.hpp"

const std::string TIELN::MODEL = "TIE/LN";
const double TIELN::WEIGHT = 6;
const double TIELN::SPEED = 100;
unsigned TIELN::id = 0;

TIELN::TIELN(const std::string& nickName) : Ship(++id, nickName) {}

double TIELN::getSpeed() const {
   return SPEED;
}

double TIELN::getWeight() const {
   return WEIGHT;
}

const std::string& TIELN::getModel() const {
   return MODEL;
}
