#ifndef POA___LABO_2_TIELN_HPP
#define POA___LABO_2_TIELN_HPP

#include "Ship.hpp"

/**
 * Class representing a TIE Star Fighter
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date 2022-04-07
 * @version 1.0
 */
class TIELN : public Ship {
public:
    TIELN();

private:
    static const std::string MODEL;
    static const double WEIGHT;
    static const double SPEED;
    static unsigned id;
};


#endif //POA___LABO_2_TIELN_HPP
