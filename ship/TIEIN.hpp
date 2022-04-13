#ifndef POA___LABO_2_TIEIN_HPP
#define POA___LABO_2_TIEIN_HPP

#include "Ship.hpp"

/**
 * Class representing a TIE Interceptor
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date 2022-04-13
 * @version 1.0
 */
class TIEIN : public Ship {
public:
   explicit TIEIN(const std::string& nickName = "");

   double getSpeed() const override;

   double getWeight() const override;

   const std::string& getModel() const override;

private:
   static const std::string MODEL;
   static const double WEIGHT;
   static const double SPEED;
   static unsigned id;
};

#endif //POA___LABO_2_TIEIN_HPP
