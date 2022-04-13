#include "LinkedList.hpp"

/**
 * Node structure
 * @internal
 * @tparam T
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date   2022-04-13
 * @version 1.0
 */
template <typename T>
struct LinkedList<T>::Node {
   T value;
   Node* next;
};

/**
 * Class Iterator
 * @internal
 * @tparam T
 * @author Nicolas Crausaz
 * @author Maxime Scharwath
 * @date   2022-04-13
 * @version 1.0
 */
template <typename T>
class LinkedList<T>::Iterator {
public:
   explicit Iterator(Node* head) {
      this->current = head;
   }

   /**
    * @brief Checks if the iterator is at the end of the list
    * @return
    */
   bool hasNext() {
      return current != nullptr;
   }

   /**
    * @brief Get the current value and move the iterator to the next node
    * @return
    */
   T next() {
      Node* tmp = current;
      current = current->next;
      return tmp->value;
   }

private:
   Node* current;
};

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::getIterator() const {
   return Iterator(head);
}

template <typename T>
LinkedList<T>::LinkedList() {
   head = nullptr;
   tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
   clear();
}

template <typename T>
void LinkedList<T>::add(T value) {
   Node* newNode = new Node{value, nullptr};
   if (head == nullptr) {
      head = newNode;
      tail = newNode;
   }
   else {
      tail->next = newNode;
      tail = newNode;
   }
}

template <typename T>
bool LinkedList<T>::remove(T value) {
   Node* current = head;
   Node* previous = nullptr;
   while (current != nullptr) {
      if (current->value == value) {
         if (current == head && current == tail) {
            head = nullptr;
            tail = nullptr;
         }
         else if (current == head) {
            head = head->next;
         }
         else if (current == tail) {
            tail = previous;
            tail->next = nullptr;
         }
         else {
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

template <typename T>
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

template <typename T>
T LinkedList<T>::get(std::size_t index) {
   if (head == nullptr || tail == nullptr) {
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

template <typename T>
void LinkedList<T>::clear() {
   while (head != nullptr) {
      Node* current = head;
      head = head->next;
      delete current;
   }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
   auto current = list.head;
   os << "[";
   while (current != nullptr) {
      if (current->next != nullptr) {
         os << current->value << ", ";
      }
      else {
         os << current->value;
      }
      current = current->next;
   }
   return os << "]";
}
