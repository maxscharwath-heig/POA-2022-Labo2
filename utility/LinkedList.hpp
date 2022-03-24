#ifndef POA___LABO_2_LINKEDLIST_HPP
#define POA___LABO_2_LINKEDLIST_HPP

#include <ostream>

template<typename T>
class LinkedList;

template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);

template<typename T>
class LinkedList {
private :
    struct Node;

    class Iterator;

public:
    LinkedList();

    ~LinkedList();

    void add(T value);

    bool remove(T value);

    bool contains(T value);

    void clear();

    T operator[](int i);

    T get(int index);

    Iterator getIterator() const;

private :
    Node* head;
};

#endif //POA___LABO_2_LINKEDLIST_HPP
