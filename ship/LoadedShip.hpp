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

   void setLoad(double load);

protected:
   LoadedShip(double weight, double speed, const std::string& model,
              unsigned id,
              double maxLoad,
              double currentLoad = 0);

private:
   const double maxLoad;
   double currentLoad;
};


#endif //POA_LABO_2_LOADEDSHIP_HPP
