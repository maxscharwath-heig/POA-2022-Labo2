#include <iostream>
#include "ship/TIELN.hpp"
#include "ship/LambdaShuttle.hpp"
#include "Squadron.hpp"
#include "Constants.hpp"

using namespace std;

int main() {
    TIELN blackLeader;
    blackLeader.setNickname("Black leader");
    TIELN blackTwo;
    LambdaShuttle shuttle(23.4); // 23.4 tonnes de marchandises
    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    //squad.removeLeader();
    cout << squad << endl;

    unsigned long distance = 1000000;
    cout << "The consumption for " << distance << " " << UNITS_DISTANCE << " "
         << squad.getConsumption(squad.getMaxSpeed(), distance) << " "
         << UNITS_CONSUMPTION << " for a speed of " << squad.getMaxSpeed() << " " <<
         UNITS_SPEED <<
         endl;
}