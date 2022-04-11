#define CATCH_CONFIG_FAST_COMPILE

#include <iostream>
#include "catch.hpp"
#include "../utility/Utils.hpp"
#include "../ship/LambdaShuttle.hpp"
#include "../Squadron.hpp"
#include "../ship/TIELN.hpp"
#include "../ship/StarDestroyer.hpp"

TEST_CASE("LinkedList") {
    SECTION("LinkedList<int>") {
        SECTION("Add and Get") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            REQUIRE(list.get(0) == 1);
            REQUIRE(list.get(1) == 2);
            REQUIRE(list.get(2) == 3);
        }

        SECTION("Remove") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            list.remove(2);
            REQUIRE(list.get(0) == 1);
            REQUIRE(list.get(1) == 3);
        }

        SECTION("Clear") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            list.clear();
            REQUIRE_THROWS(list.get(0));
            REQUIRE_THROWS(list.get(1));
            REQUIRE_THROWS(list.get(2));
        }

        SECTION("Contain") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            REQUIRE(list.contains(1));
            REQUIRE(list.contains(2));
            REQUIRE(list.contains(3));
            REQUIRE_FALSE(list.contains(4));
            list.remove(2);
            REQUIRE_FALSE(list.contains(2));
        }
    }

    SECTION("LinkedList<Pointer>") {
        struct Test {
            int a;
            int b;
            int c;
        };
        Test* t1 = new Test{1, 2, 3};
        Test* t2 = new Test{4, 5, 6};
        Test* t3 = new Test{7, 8, 9};
        SECTION("Add and Get") {
            LinkedList<Test*> list;
            list.add(t1);
            list.add(t2);
            list.add(t3);
            REQUIRE(list.get(0)->a == 1);
            REQUIRE(list.get(0)->b == 2);
            REQUIRE(list.get(0)->c == 3);
            REQUIRE(list.get(1)->a == 4);
            REQUIRE(list.get(1)->b == 5);
            REQUIRE(list.get(1)->c == 6);
            REQUIRE(list.get(2)->a == 7);
            REQUIRE(list.get(2)->b == 8);
            REQUIRE(list.get(2)->c == 9);
        }

        SECTION("Remove") {
            LinkedList<Test*> list;
            list.add(t1);
            list.add(t2);
            list.add(t3);
            list.remove(t2);
            REQUIRE(list.get(0)->a == 1);
            REQUIRE(list.get(0)->b == 2);
            REQUIRE(list.get(0)->c == 3);
            REQUIRE(list.get(1)->a == 7);
            REQUIRE(list.get(1)->b == 8);
            REQUIRE(list.get(1)->c == 9);
        }

        SECTION("Clear") {
            LinkedList<Test*> list;
            list.add(t1);
            list.add(t2);
            list.add(t3);
            list.clear();
            REQUIRE_THROWS(list.get(0));
            REQUIRE_THROWS(list.get(1));
            REQUIRE_THROWS(list.get(2));
        }

        SECTION("Contain") {
            LinkedList<Test*> list;
            list.add(t1);
            list.add(t2);
            list.add(t3);
            REQUIRE(list.contains(t1));
            REQUIRE(list.contains(t2));
            REQUIRE(list.contains(t3));
            REQUIRE_FALSE(list.contains(nullptr));
            list.remove(t2);
            REQUIRE_FALSE(list.contains(t2));
        }
        delete t1;
        delete t2;
        delete t3;
    }

    SECTION("LinkedList<const string&>") {
        LinkedList<const std::string&> list;
        list.add("Hello");
        list.add("World");
        list.add("!");
        REQUIRE(list.get(0) == "Hello");
        REQUIRE(list.get(1) == "World");
        REQUIRE(list.get(2) == "!");
        REQUIRE(list.contains("Hello"));
        REQUIRE(list.contains("World"));
        REQUIRE(list.contains("!"));
        REQUIRE_FALSE(list.contains(""));
        REQUIRE_FALSE(list.contains("Hello World !"));
        list.remove("World");
        REQUIRE_FALSE(list.contains("World"));
    }

    SECTION("Iterator") {
        LinkedList<int> list;
        list.add(1);
        list.add(2);
        list.add(3);
        auto it = list.getIterator();
        REQUIRE(it.hasNext());
        REQUIRE(it.next() == 1);
        REQUIRE(it.hasNext());
        REQUIRE(it.next() == 2);
        REQUIRE(it.hasNext());
        REQUIRE(it.next() == 3);
        REQUIRE_FALSE(it.hasNext());
    }
}

TEST_CASE("Labo2 Test") {
    SECTION("Invalid load - LambaShuttle") {
        try {
            LambdaShuttle lbs(85);
        }
        catch (const std::runtime_error&) {
            SUCCEED("Ok");
            return;
        }
        FAIL("Should throw");
    }

    SECTION("Invalid load - StarDestroyer") {
        try {
            LambdaShuttle lbs(250001);
        }
        catch (const std::runtime_error&) {
            SUCCEED("Ok");
            return;
        }
        FAIL("Should throw");
    }

    SECTION("Set nickname") {
        TIELN test;
        test.setNickname("Test");
        REQUIRE(test.getNickname() == "Test");
    }

    SECTION("Create squadron") {
        Squadron squad("Squad");
        REQUIRE(squad.getName() == "Squad");
    }

    SECTION("Set squadron leader") {
        Squadron squad("Squad");
        StarDestroyer star;
        squad.setLeader(star);

        const Ship test = squad[0];

        REQUIRE(&test == &star);
    }

    SECTION("Remove squadron leader") {
        Squadron squad("Squad");
        StarDestroyer star;
        squad.setLeader(star);
        squad.removeLeader();

        squad.getLeader();

        //REQUIRE( == nullptr);
    }

    SECTION("Add ship to squadron") {
        Squadron s("MySquadron");
        LambdaShuttle lbs(40);
        lbs.setNickname("Lambda");
        s += lbs;
        REQUIRE(&s[0] == &lbs);
    }

    SECTION("Remove ship from squadron") {
    }

    SECTION("Get ship at index") {
        Squadron s("MySquadron");
        LambdaShuttle lbs(40);
        lbs.setNickname("Lambda");
        s += lbs;
        REQUIRE(&s[0] == &lbs);
    }

    SECTION("Get ship at invalid index") {
        Squadron s("MySquadron");
        try {
            const Ship test = s[0];
        }
        catch (const std::out_of_range&) {
            SUCCEED("Ok");
            return;
        }
        FAIL("Should throw");


    }

    SECTION("Get squadron consumption") {

    }

    SECTION("Get squadron max speed") {

    }

    SECTION("Get squadron total weight") {

    }
}