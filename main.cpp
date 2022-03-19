#include <iostream>
#include "ship/TIELN.hpp"
#include "ship/TIEIN.hpp"
#include "ship/StarDestroyer.hpp"
#include "ship/LambdaShuttle.hpp"

using namespace std;

int main() {
   TIELN blackLeader;
   TIEIN test1;
   StarDestroyer st1(23.0);
   LambdaShuttle lb1(30.0);

   TIELN blackLeader2;
   TIEIN test2;
   StarDestroyer st2(33.0);
   LambdaShuttle lb2(40.0);


   cout << blackLeader << endl;
   cout << test1 << endl;
   cout << st1 << endl;
   cout << lb1 << endl;

   cout << blackLeader2 << endl;
   cout << test2 << endl;
   cout << st2 << endl;
   cout << lb2 << endl;

   //blackLeader.setNickname("Black leader");
   //TIE blackTwo;
   //Shuttle shuttle(23.4); // 23.4 tonnes de marchandises
   //Squadron squad("Black Squadron");
   //squad += blackLeader;
   //squad += blackTwo;
   //squad += shuttle;
   //squad.setLeader(blackLeader);
//    cout << squad << endl;
}