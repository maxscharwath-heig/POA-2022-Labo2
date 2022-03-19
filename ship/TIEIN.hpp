#ifndef POA___LABO_2_TIEIN_HPP
#define POA___LABO_2_TIEIN_HPP

#include "Ship.hpp"

class TIEIN : public Ship {
public:
   TIEIN();

private:
   static const std::string MODEL;
   static const unsigned long long WEIGHT;
   static const unsigned SPEED;
   static unsigned id;
};

#endif //POA___LABO_2_TIEIN_HPP
