//
// Created by Maxime Scharwath on 18.03.2022.
//

#ifndef POA___LABO_2_LINKEDLIST_HPP
#define POA___LABO_2_LINKEDLIST_HPP

#include <ostream>

template<typename T>
class LinkedList;

template<typename T>
class LinkedList {
private :
    struct Node {
        T value;
        Node* next;
    };
    Node* head;
public:
    LinkedList<T>();

    ~LinkedList<T>();

    void add(T value);

    bool remove(T value);

    bool contains(T value);

    void clear();

    T get(int index);

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        Node* current = list.head;
        os << "[";
        while (current != nullptr) {
            os << current->value << " ";
            current = current->next;
        }
        os << "]";
        return os;
    }
};

#endif //POA___LABO_2_LINKEDLIST_HPP
