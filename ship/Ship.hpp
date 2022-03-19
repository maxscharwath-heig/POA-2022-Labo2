#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>

class Ship;

std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:
    virtual std::ostream& toStream(std::ostream& os) const;

    void setNickname(const std::string& name);

    unsigned getSpeed() const;

    unsigned long long getWeight() const;
    // virtual ~Ship();

protected:
    Ship(unsigned long long weigth, unsigned speed, const std::string& model,
         unsigned id);

private:
    std::string nickName;
    const unsigned long long weigth;
    const unsigned speed;
    const std::string model;
    const unsigned id;
};

#endif /* SHIP_HPP */
