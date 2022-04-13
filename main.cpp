#include <iostream>
#include "ship/TIELN.hpp"
#include "ship/LambdaShuttle.hpp"
#include "Squadron.hpp"
#include "Constants.hpp"
#include "ship/StarDestroyer.hpp"
#include "ship/TIEIN.hpp"

using namespace std;

void more_tests() {
   cout << "TESTS" << endl << endl;
   {
      cout << "LinkedList<int> - 1:";
      LinkedList<int> list;
      list.add(1);
      list.add(2);
      list.add(3);
      cout << (list.get(0) == 1 && list.get(1) == 2 && list.get(2) == 3 ? "Ok" : "Fail") << endl;

      cout << "LinkedList<int> - 2:";
      list.remove(2);
      cout << (list.get(0) == 1 && list.get(1) == 3 ? "Ok" : "Fail") << endl;

      cout << "LinkedList<int> - 3:";
      list.clear();
      try {
         list.get(0);
      }
      catch (const std::out_of_range&) {
         cout << "Ok" << endl;
      }

      cout << "LinkedList<int> - 4:";
      list.add(1);
      cout << (list.contains(1) && !list.contains(0) ? "Ok" : "Fail") << endl;
   }
   {
      struct Test {
         int a;
         int b;
         int c;
      };
      Test* t1 = new Test{1, 2, 3};
      Test* t2 = new Test{4, 5, 6};
      Test* t3 = new Test{7, 8, 9};

      cout << "LinkedList<Test*> - 1:";
      LinkedList<Test*> list;
      list.add(t1);
      list.add(t2);
      list.add(t3);

      cout << (list.get(0)->a == 1 && list.get(0)->b == 2 && list.get(2)->a == 7 ? "Ok" : "Fail") << endl;

      cout << "LinkedList<Test*> - 2:";
      list.remove(t2);
      cout << (list.get(0)->a == 1 && list.get(1)->a == 7 ? "Ok" : "Fail") << endl;

      cout << "LinkedList<Test*> - 3:";
      list.clear();
      try {
         list.get(0);
      }
      catch (const std::out_of_range&) {
         cout << "Ok" << endl;
      }

      cout << "LinkedList<Test*> - 4:";
      list.add(t1);
      list.add(t2);
      cout << (list.contains(t1) && list.contains(t2)
               && !list.contains(nullptr) ? "Ok" : "Fail") << endl;

      delete t1;
      delete t2;
      delete t3;
   }

   {
      cout << "LinkedList<const string&> - 1:";
      LinkedList<const std::string&> list;
      list.add("Hello");
      list.add("World");
      list.add("!");
      cout << (list.get(0) == "Hello" && list.get(1) == "World" && list.get(2) == "!" ? "Ok" : "Fail") << endl;

      cout << "LinkedList<const string&> - 2:";
      list.remove("World");
      cout << (list.get(0) == "Hello" && list.get(1) == "!" ? "Ok" : "Fail") << endl;

      cout << "LinkedList<const string&> - 3:";
      list.clear();
      try {
         list.get(0);
      }
      catch (const std::out_of_range&) {
         cout << "Ok" << endl;
      }

      cout << "LinkedList<const string&> - 4:";
      list.add("Test");
      cout << (list.contains("Test") && !list.contains("bla") ? "Ok" : "Fail") << endl;
   }

   {
      cout << "Iterator - 1:";
      LinkedList<int> list;
      list.add(1);
      list.add(2);
      list.add(3);
      auto it = list.getIterator();
      cout << (it.next() == 1 ? "Ok" : "Fail") << endl;

      cout << "Iterator - 2:";
      cout << (it.hasNext() ? "Ok" : "Fail") << endl;

      cout << "Iterator - 3:";
      it.next();
      cout << (it.next() == 3 ? "Ok" : "Fail") << endl;

      cout << "Iterator - 4";
      cout << (!it.hasNext()? "Ok" : "Fail") << endl;
   }

   cout << "Ships - 1 :";
   try {
      LambdaShuttle lbs(85);
   }
   catch (const std::runtime_error&) {
      cout << "Ok" << endl;
   }

   cout << "Ships - 2 :";
   try {
      StarDestroyer st(250001);
   }
   catch (const std::runtime_error&) {
      cout << "Ok" << endl;
   }

   cout << "Ships - 3 :";
   TIELN t;
   cout << (t.getNickname() == "" ? "Ok" : "Fail") << endl;

   cout << "Ships - 4 :";
   TIELN test;
   test.setNickname("Test");
   cout << (test.getNickname() == "Test" ? "Ok" : "Fail") << endl;

   cout << "Ships - 5 :";
   {
      TIELN t1;
      TIEIN t2;
      LambdaShuttle ls;
      StarDestroyer sd;
      cout << (t1.getSpeed() == 100 && t2.getSpeed() == 110
               && ls.getSpeed() == 54 && sd.getSpeed() == 40 ? "Ok" : "Fail") << endl;
   }

   cout << "Ships - 6 :";
   {
      TIELN t1;
      TIEIN t2;
      LambdaShuttle ls; // No cargo
      StarDestroyer sd; // No cargo
      cout << (t1.getWeight() == 6 && t2.getWeight() == 5
               && ls.getWeight() == 360 && sd.getWeight() == 9000000000 ? "Ok" : "Fail") << endl;
   }

   cout << "Ships - 7 :";
   {
      LambdaShuttle ls(30);
      StarDestroyer sd(10000);
      cout << (ls.getWeight() == 390 && sd.getWeight() == 9000010000 ? "Ok" : "Fail") << endl;
   }

   cout << "Ships - 8 :";
   LambdaShuttle ls(30);
   cout << ls << endl;


   cout << "Squadron - 1:";
   {
      Squadron squad("Squad");
      cout << (squad.getName() == "Squad" ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 2:";
   {
      Squadron squad("Squad");
      StarDestroyer leader;
      squad.setLeader(leader);
      cout << (&squad[0] == &leader ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 3:";
   {
      Squadron squad("Squad");
      StarDestroyer leader;
      squad += leader;
      squad.setLeader(leader);
      cout << (&squad[0] == &leader ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 4: output";
   {
      Squadron squad("Squad");
      StarDestroyer star;
      squad.setLeader(star);
      squad.removeLeader();
      squad.getLeader();
      std::cout << squad << endl; // Must display "No leader"
   }

   cout << "Squadron - 5:";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      lbs.setNickname("Lambda");
      s += lbs;
      cout << (&s[0] == &lbs ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 6:";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      lbs.setNickname("Lambda");
      Squadron s2 = s + lbs;
      cout << (&s2[0] == &lbs ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 7: output";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      lbs.setNickname("Lambda");
      s += lbs;
      s -= lbs;
      std::cout << s << endl; // Should not be displayed
   }

   cout << "Squadron - 8: output";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      LambdaShuttle lbs2(40);
      s += lbs;
      s += lbs2;
      Squadron s2 = s - lbs;
      std::cout << s2 << endl; // Should not be displayed
   }

   cout << "Squadron - 9: output";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      s -= lbs;
      std::cout << s << endl; // Should not be displayed
   }


   cout << "Squadron - 10:";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      lbs.setNickname("Lambda");
      s += lbs;
      cout << (&s[0] == &lbs ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 11:";
   {
      Squadron s("MySquadron");
      try {
         s[0];
      }
      catch (const std::out_of_range&) {
         cout << "Ok" << endl;
      }
   }

   cout << "Squadron - 12:";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs; // Slowest
      TIELN tie;
      s += lbs;
      s += tie;
      cout << (s.getMaxSpeed() == lbs.getSpeed() ? "Ok" : "Fail") << endl;
   }

   cout << "Squadron - 13:";
   {
      Squadron s("MySquadron");
      LambdaShuttle lbs(40);
      TIELN tie;
      s += lbs;
      s += tie;
      const double weigth = lbs.getWeight() + tie.getWeight();
      cout << (s.getTotalWeight() == weigth ? "Ok" : "Fail") << endl;
   }
}

int main() {
   TIELN blackLeader;
   blackLeader.setNickname("Black leader");
   TIELN blackTwo;

   StarDestroyer test;
   LambdaShuttle shuttle(23.4); // 23.4 tonnes de marchandises

   Squadron squad("Black Squadron");
   squad += blackLeader;
   squad += blackTwo;
   squad += shuttle;
   squad.setLeader(blackLeader);
   cout << squad << endl;

   double distance = 1000000;
   cout << "The consumption for " << distance << " " << UNITS_DISTANCE << ", "
        << squad.getConsumption(squad.getMaxSpeed(), distance) << " "
        << UNITS_CONSUMPTION << " for a speed of " << squad.getMaxSpeed() << " " <<
        UNITS_SPEED <<
        endl;

   squad.removeLeader();
   cout << squad << endl;

   // Run specific tests
   more_tests();

   return EXIT_SUCCESS;
}