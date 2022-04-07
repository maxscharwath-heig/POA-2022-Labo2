#ifndef POA___LABO_2_SQUADRON_HPP
#define POA___LABO_2_SQUADRON_HPP

#include <string>
#include "utility/Utils.hpp."
#include "ship/Ship.hpp"

class Squadron;

/**
 * Add a ship to a squadron and get a copy of the updated squadron
 * @param lhs squadron where the ship will be added
 * @param rhs ship to add to squadron
 * @return Copy of squadron
 */
Squadron operator+(const Squadron& lhs, const Ship& rhs);

/**
 * Remove a ship from a squadron and get a copy of the updated squadron
 * @param lhs squadron where the ship will be removed
 * @param rhs ship to remove from squadron
 * @return Copy of squadron
 */
Squadron operator-(const Squadron& lhs, const Ship& rhs);

/**
 * Class representing a squadron of ships
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date 2022-04-07
 * @version 1.0
 */
class Squadron {
    friend std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

public:
    explicit Squadron(const std::string& name);

    /**
     * Set a ship as a leader of the squadron
     * The ship will be added as a member if it is not already
     * @param ship Ship to set as squadron's leader
     */
    void setLeader(const Ship& ship);

    /**
     * Remove the leader of the squadron
     * The leader will still remain as a member of the squadron
     */
    void removeLeader();

    /**
     * Calculate the total fuel consumption of a squadron flying at speed for a distance
     * @param speedWanted flight speed of squadron
     * @param distance distance to fly
     * @return Total fuel consumption of squadron
     */
    double getConsumption(double speedWanted, double distance) const;

    /**
     * Calculate the max speed of a squadron. Every ship of a squadron fly at the speed
     * of the slowest ship.
     * @return Max fly speed os squadron
     */
    double getMaxSpeed() const;

    /**
     * Calculate the total weight of a squadron
     * @return Total weight of squadron
     */
    double getTotalWeight() const;

    /**
     * Get the ship of squadron at position
     * @param i position of wanted ship
     * @return Ship at position i
     */
    const Ship& operator[](int i);

    /**
     * Add a ship to a squadron. No effect if the ship is already in the squadron
     * @param ship Ship to add
     * @return the squadron
     */
    Squadron& operator+=(const Ship& ship);

    /**
     * Remove ship from a squadron. No effect if ship is not in the squadron.
     * If removed ship is the leader, the squadron will no longer have a leader.
     * @param ship Ship to remove
     * @return the squadron
     */
    Squadron& operator-=(const Ship& ship);

private:
    const std::string name;

    LinkedList<const Ship*> members;

    const Ship* leader; // can be nullptr
};

#endif //POA___LABO_2_SQUADRON_HPP
