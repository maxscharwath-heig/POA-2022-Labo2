#ifndef POA___LABO_2_LINKEDLIST_HPP
#define POA___LABO_2_LINKEDLIST_HPP

#include <ostream>

template<typename T>
class LinkedList {
public:
    LinkedList<T>();

    ~LinkedList();

    void add(T value);

    bool remove(T value);

    bool contains(T value);

    void clear();

    T operator[](int i);

    T get(int index);

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        Node* current = list.head;
        os << "[";
        while (current != nullptr) {
            if(current->next != nullptr) {
                os << current->value << ", ";
            } else {
                os << current->value;
            }
            current = current->next;
        }
        os << "]";
        return os;
    }

private :
    struct Node {
        T value;
        Node* next;
    };
    Node* head;

    class Iterator {
    public:
        explicit Iterator(Node* head) {
            this->current = head;
        }

        bool hasNext() {
            return current != nullptr;
        }

        T next() {
            Node* tmp = current;
            current = current->next;
            return tmp->value;
        }

    private:
        Node* current;
    };

public:
    Iterator getIterator() const {
        return Iterator(head);
    }
};

#endif //POA___LABO_2_LINKEDLIST_HPP
