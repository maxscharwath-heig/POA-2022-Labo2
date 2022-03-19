#ifndef POA___LABO_2_LAMBDASHUTTLE_HPP
#define POA___LABO_2_LAMBDASHUTTLE_HPP

#include "Ship.hpp"
#include "LoadedShip.hpp"

class LambdaShuttle: public LoadedShip {
public:
    explicit LambdaShuttle(double currentLoad);

private:
   static const std::string MODEL;
   static unsigned id;
};


#endif //POA___LABO_2_LAMBDASHUTTLE_HPP
