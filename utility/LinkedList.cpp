//
// Created by Maxime Scharwath on 18.03.2022.
//

#include "LinkedList.hpp"


template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void LinkedList<T>::add(T value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<typename T>
bool LinkedList<T>::remove(T value) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

template<typename T>
bool LinkedList<T>::contains(T value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
T LinkedList<T>::get(int index) {
    if (index < 0) {
        throw std::out_of_range("Index must be positive");
    }
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
    }
    return current->value;
}

template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current;
    }
}

template<typename T>
T LinkedList<T>::operator[](int  i) {
    return get(i);
}
