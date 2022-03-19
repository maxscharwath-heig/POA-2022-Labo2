#ifndef POA___LABO_2_TIELN_HPP
#define POA___LABO_2_TIELN_HPP

#include "Ship.hpp"

class TIELN : public Ship {
public:
   TIELN();

private:
   static const std::string MODEL;
   static const unsigned long long WEIGHT;
   static const unsigned SPEED;
   static unsigned id;
};


#endif //POA___LABO_2_TIELN_HPP
