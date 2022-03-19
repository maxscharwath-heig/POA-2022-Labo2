#ifndef POA_LABO_2_LOADEDSHIP_HPP
#define POA_LABO_2_LOADEDSHIP_HPP

#include "Ship.hpp"

class LoadedShip : public Ship {
public:
   std::ostream& toStream(std::ostream& os) const override;

protected:
   LoadedShip(unsigned long long weigth, unsigned speed, const std::string& model, unsigned id, double maxLoad,
              double currentLoad = 0);

private:
   const double maxLoad;
   double currentLoad;
};


#endif //POA_LABO_2_LOADEDSHIP_HPP
