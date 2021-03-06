#ifndef POA___LABO_2_LAMBDASHUTTLE_HPP
#define POA___LABO_2_LAMBDASHUTTLE_HPP

#include "Ship.hpp"
#include "LoadedShip.hpp"

/**
 * Class representing a loaded Lambda Shuttle
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date 2022-04-13
 * @version 1.0
 */
class LambdaShuttle : public LoadedShip {
public:
   explicit LambdaShuttle(double currentLoad = 0, const std::string& nickName = "");

   double getSpeed() const override;

   double getWeight() const override;

   const std::string& getModel() const override;

private:
   static const std::string MODEL;
   static const double WEIGHT;
   static const double SPEED;
   static const double MAX_LOAD;
   static unsigned id;
};

#endif //POA___LABO_2_LAMBDASHUTTLE_HPP
