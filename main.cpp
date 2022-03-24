#include <iostream>
#include "ship/TIELN.hpp"
#include "ship/TIEIN.hpp"
#include "ship/StarDestroyer.hpp"
#include "ship/LambdaShuttle.hpp"
#include "Squadron.hpp"

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
    cout << squad << endl;

    unsigned long distance = 1000000;
    cout << "The consumption for " << distance << " mio. km: is "
         << squad.getConsumption(squad.getMaxSpeed(), distance)
         << " tons for a speed of " << squad.getMaxSpeed() << " MGLT" << endl;
}