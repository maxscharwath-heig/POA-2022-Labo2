//
// Created by Maxime Scharwath on 18.03.2022.
//
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
    {
        cout << "Test 1: List with integers" << endl;
        LinkedList<int> list;
        list.add(1);
        list.add(2);
        list.add(3);
        cout << list << endl;
        cout << "list[0] = " << list[0] << endl;
        cout << "list[1] = " << list[1] << endl;
        cout << "list[2] = " << list[2] << endl;
        list.remove(2);
        cout << list << endl;
        list.remove(1);
        cout << list << endl;
        list.remove(3);
        cout << list << endl;
        list.add(1);
        list.add(2);
        list.add(3);
        cout << list << endl;
        cout << "Has 1: " << (list.contains(1) ? "True" : "False") << endl;
        cout << "Has 2: " << (list.contains(2) ? "True" : "False") << endl;
        cout << "Has 3: " << (list.contains(3) ? "True" : "False") << endl;
        cout << "Has 4: " << (list.contains(4) ? "True" : "False") << endl;
        list.clear();
        cout << list << endl;
    }
    {
        cout << "Test 2: List with strings" << endl;
        LinkedList<string> list;
        list.add("Hello");
        list.add("World");
        list.add("!");
        cout << list << endl;
        cout << "list[0] = " << list[0] << endl;
        cout << "list[1] = " << list[1] << endl;
        cout << "list[2] = " << list[2] << endl;
        list.remove("World");
        cout << list << endl;
        list.remove("Hello");
        cout << list << endl;
        list.remove("!");
        cout << list << endl;
        list.add("Hello");
        list.add("World");
        list.add("!");
        cout << list << endl;
        cout << "Has Hello: " << (list.contains("Hello") ? "True" : "False") << endl;
        cout << "Has World: " << (list.contains("World") ? "True" : "False") << endl;
        cout << "Has !: " << (list.contains("!") ? "True" : "False") << endl;
        cout << "Has Hello World: "
             << (list.contains("Hello World") ? "True" : "False") << endl;
        list.clear();
        cout << list << endl;
    }
    {
        cout << "Test 3: List with pointers" << endl;
        struct Test {
            int a;
            int b;
            int c;
        };
        LinkedList<Test*> list;
        Test* t1 = new Test{1, 2, 3};
        Test* t2 = new Test{4, 5, 6};
        Test* t3 = new Test{7, 8, 9};
        list.add(t1);
        list.add(t2);
        list.add(t3);
        cout << list << endl;
        cout << "list[0] = " << list[0] << endl;
        cout << "list[1] = " << list[1] << endl;
        cout << "list[2] = " << list[2] << endl;
        cout << "Has " << t1 << ": " << (list.contains(t1) ? "True" : "False")
             << endl;
        cout << "Has " << t2 << ": " << (list.contains(t2) ? "True" : "False")
             << endl;
        cout << "Has " << t3 << ": " << (list.contains(t3) ? "True" : "False")
             << endl;
        cout << list << endl;
        cout << "Has " << t1 << ": " << (list.contains(t1) ? "True" : "False")
             << endl;
        cout << "Get t1 a:" << list.get(0)->a << endl;
        cout << "Get t2 b:" << list.get(1)->b << endl;
        cout << "Get t3 c:" << list.get(2)->c << endl;
        //catch out of range
        try {
            cout << "Get index 3 (Out of range):" << list.get(3) << endl;
        } catch (const std::out_of_range& oor) {
            cout << "test Pass" << endl;
        }
        try {
            cout << "Get index -1 (Out of range):" << list.get(-1) << endl;
        } catch (const std::out_of_range& oor) {
            cout << "test Pass" << endl;
        }
        list.clear();
        try {
            cout << "Get index 0 (empty) (Out of range):" << list.get(0) << endl;
        } catch (const std::out_of_range& oor) {
            cout << "test Pass" << endl;
        }
    }
    return 0;
}