#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>

/**
 * Class representing a ship.
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date 2022-04-13
 * @version 1.0
 */
class Ship;

std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:
   /**
    * Prints the ship to the given output stream.
    * @param os The output stream to print to.
    * @return The output stream.
    */
   virtual std::ostream& toStream(std::ostream& os) const;

   /**
    * Set the name of the ship.
    * @param name - The name of the ship.
    */
   void setNickname(const std::string& name);

   /**
    * Get the name of the sjip
    * @return name of the ship
    */
   const std::string& getNickname() const;

   /**
    * Get speed of the ship.
    * @return The speed of the ship.
    */
   virtual double getSpeed() const = 0;

   /**
    * Get the consumption of the ship.
    * @param speedWanted - the desired speed.
    * @param distance - the distance to travel.
    * @warning if the speed is too high, it will be capped at the maximum speed of the ship.
    * @return The consumption of the ship.
    */
   double getConsumption(double speedWanted, double distance) const;

   /**
    * Get the weight of the ship.
    * @return The weight of the ship.
    */
   virtual double getWeight() const = 0;

   /**
    * Get the model of the ship
    * @return The model of the ship
    */
   virtual const std::string& getModel() const = 0;

   /**
    * Destructor with default behaviour
    */
   virtual ~Ship() = default;

protected:
   explicit Ship(unsigned id, const std::string& nickame = "");

private:
   std::string nickName;
   const unsigned id;
};

#endif /* SHIP_HPP */
