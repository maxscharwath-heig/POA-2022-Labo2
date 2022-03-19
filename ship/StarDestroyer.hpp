#ifndef POA___LABO_2_STARDESTROYER_HPP
#define POA___LABO_2_STARDESTROYER_HPP

#include "Ship.hpp"
#include "LoadedShip.hpp"

class StarDestroyer : public LoadedShip {
public:
   explicit StarDestroyer(double currentLoad);

private:
   static const std::string MODEL;
   static unsigned id;
};


#endif //POA___LABO_2_STARDESTROYER_HPP
