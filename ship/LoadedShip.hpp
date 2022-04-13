#ifndef POA_LABO_2_LOADEDSHIP_HPP
#define POA_LABO_2_LOADEDSHIP_HPP

#include "Ship.hpp"

/**
 * Class representing a loaded Ship
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date 2022-04-13
 * @version 1.0
 */
class LoadedShip : public Ship {
public:
   std::ostream& toStream(std::ostream& os) const override;

   double getWeight() const override;

   /**
    * Set the load weigth of Loaded ship
    * @param load weigth of load
    */
   void setLoad(double load);

protected:
   explicit LoadedShip(unsigned id, double maxLoad, double currentLoad = 0, const std::string& nickName = "");

private:
   double currentLoad;
   double maxLoad;
};


#endif //POA_LABO_2_LOADEDSHIP_HPP
