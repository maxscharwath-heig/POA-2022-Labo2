#define CATCH_CONFIG_FAST_COMPILE

#include "catch.hpp"
#include "../utility/LinkedList.cpp"

TEST_CASE("LinkedList") {
    SECTION("INT") {
        SECTION("Add and Get") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            REQUIRE(list.get(0) == 1);
            REQUIRE(list.get(1) == 2);
            REQUIRE(list.get(2) == 3);
        }SECTION("Accessor") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            REQUIRE(list[0] == 1);
            REQUIRE(list[1] == 2);
            REQUIRE(list[2] == 3);
        }SECTION("Remove") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            list.remove(2);
            REQUIRE(list.get(0) == 1);
            REQUIRE(list.get(1) == 3);
        }SECTION("Clear") {
            LinkedList<int> list;
            list.add(1);
            list.add(2);
            list.add(3);
            list.clear();
            REQUIRE_THROWS(list.get(0));
            REQUIRE_THROWS(list.get(1));
            REQUIRE_THROWS(list.get(2));
        }SECTION("Contain") {
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
    }SECTION("POINTER") {
        struct Test {
            int a;
            int b;
            int c;
        };
        SECTION("Add and Get") {
            LinkedList<Test*> list;
            Test* t1 = new Test{1, 2, 3};
            Test* t2 = new Test{4, 5, 6};
            Test* t3 = new Test{7, 8, 9};
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
            delete t1;
            delete t2;
            delete t3;
        }

        SECTION("Remove") {
            LinkedList<Test*> list;
            Test* t1 = new Test{1, 2, 3};
            Test* t2 = new Test{4, 5, 6};
            Test* t3 = new Test{7, 8, 9};
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
            delete t1;
            delete t2;
            delete t3;
        }SECTION("Clear") {
            LinkedList<Test*> list;
            Test* t1 = new Test{1, 2, 3};
            Test* t2 = new Test{4, 5, 6};
            Test* t3 = new Test{7, 8, 9};
            list.add(t1);
            list.add(t2);
            list.add(t3);
            list.clear();
            REQUIRE_THROWS(list.get(0));
            REQUIRE_THROWS(list.get(1));
            REQUIRE_THROWS(list.get(2));
            delete t1;
            delete t2;
            delete t3;
        }SECTION("Contain") {
            LinkedList<Test*> list;
            Test* t1 = new Test{1, 2, 3};
            Test* t2 = new Test{4, 5, 6};
            Test* t3 = new Test{7, 8, 9};
            list.add(t1);
            list.add(t2);
            list.add(t3);
            REQUIRE(list.contains(t1));
            REQUIRE(list.contains(t2));
            REQUIRE(list.contains(t3));
            REQUIRE_FALSE(list.contains(new Test{1, 2, 3}));
            list.remove(t2);
            REQUIRE_FALSE(list.contains(t2));
            delete t1;
            delete t2;
            delete t3;
        }
    }
}