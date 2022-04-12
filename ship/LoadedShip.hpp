#ifndef POA_LABO_2_LOADEDSHIP_HPP
#define POA_LABO_2_LOADEDSHIP_HPP

#include "Ship.hpp"

class LoadedShip : public Ship {
public:
    std::ostream& toStream(std::ostream& os) const override;
    double getWeight() const override;

protected:
    LoadedShip(double weight, double speed, const std::string& model, unsigned id,
               double maxLoad,
               double currentLoad = 0);

private:
    const double maxLoad;
    double currentLoad;
};


#endif //POA_LABO_2_LOADEDSHIP_HPP
