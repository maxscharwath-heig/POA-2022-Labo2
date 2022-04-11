#ifndef POA___LABO_2_LINKEDLIST_HPP
#define POA___LABO_2_LINKEDLIST_HPP

#include <ostream>

/**
 * Class LinkedList
 * @brief Represents a linked list for storing elements of type T
 * @tparam T
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @warning operator== needs to be implemented for T for example if T is a
 * reference to an object
 * @date 2022-04-07
 * @version 1.0
 */
template<typename T>
class LinkedList;

template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);

template<typename T>
class LinkedList {
private :
    /**
     * @brief The private internal Node struct
     */
    struct Node;

    /**
     * @brief The private internal Iterator class
     */
    class Iterator;

    /**
     * @brief the head Node of the list
     */
    Node* head;

    /**
     * @brief the tail Node of the list
     */
    Node* tail;

public:
    LinkedList();

    ~LinkedList();

    /**
     * @brief Add an element to the end of the list
     * @param value - the value to add
     */
    void add(T value);

    /**
     * @brief Remove the first value of the list;
     * @param value - the value to remove
     * @return true if the value was removed, false otherwise
     */
    bool remove(T value);

    /**
     * @brief Check if the list contains a value
     * @return true if the list contains the value, false otherwise
     */
    bool contains(T value);

    /**
     * @brief Clear the list
     */
    void clear();

    /**
     * @brief Get the element at the given index
     * @param index - the index of the element
     * @return the element at the given index
     */
    T get(int index);

    /**
     * @brief Get an iterator of the list
     * @return the iterator of the list
     */
    Iterator getIterator() const;
};

#endif //POA___LABO_2_LINKEDLIST_HPP
