#ifndef POA___LABO_2_LAMBDASHUTTLE_HPP
#define POA___LABO_2_LAMBDASHUTTLE_HPP

#include "Ship.hpp"
#include "LoadedShip.hpp"

class LambdaShuttle : public LoadedShip {
public:
    explicit LambdaShuttle(double currentLoad);

private:
    static const std::string MODEL;
    static const double WEIGHT;
    static const unsigned SPEED;
    static const double MAX_LOAD;
    static unsigned id;
};


#endif //POA___LABO_2_LAMBDASHUTTLE_HPP
