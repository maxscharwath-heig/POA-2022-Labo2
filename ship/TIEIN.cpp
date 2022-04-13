#include "TIEIN.hpp"

const std::string TIEIN::MODEL = "TIE/IN";
const double TIEIN::WEIGHT = 5;
const double TIEIN::SPEED = 110;
unsigned TIEIN::id = 0;

TIEIN::TIEIN(const std::string& nickName) : Ship(++id, nickName) {}

double TIEIN::getSpeed() const {
   return SPEED;
}

double TIEIN::getWeight() const {
   return WEIGHT;
}

const std::string& TIEIN::getModel() const {
   return MODEL;
}
