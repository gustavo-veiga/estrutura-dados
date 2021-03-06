#include <lesson/linked/list.h>
#include <iostream>
#include <stdexcept>

namespace lesson {
namespace linked {
/*
 * Constructor
 */

template <typename T>
list<T>::list() {
  this->ptr_front = nullptr;
}

/*
 * Destructors
 */

template <typename T>
list<T>::~list() {
  auto aux = this->ptr_front;
  while (aux != nullptr) {
    auto to_remove = aux;
    aux = aux->next;
    delete to_remove;
  }
}

/*
 * Public Methods
 */

// Element Access

template <typename T>
T list<T>::front() {
  return this->ptr_front->element;
}

template <typename T>
void list<T>::show() {
  auto aux = this->ptr_front;
  while (aux != nullptr) {
    std::cout << aux->element << std::endl;
    aux = aux->next;
  }
}

// Modifiers

template <typename T>
void list<T>::pop(T element) {
  if (this->ptr_front->element == element) {
    // Primero nó
    auto to_remove = this->ptr_front;
    this->ptr_front = this->ptr_front->next;
    delete to_remove;
  } else {
    // Demais nós
    auto aux = this->ptr_front;
    while (aux != nullptr) {
      if (aux->next->element == element) {
        auto to_remove = aux->next;
        aux->next = aux->next->next;
        delete to_remove;
        break;
      }
      aux = aux->next;
    }
  }
}

template <typename T>
void list<T>::push_front(T element) {
  if (this->empty()) {
    this->ptr_front = new node::single<T>(element);
  } else {
    this->ptr_front = new node::single<T>(element, this->ptr_front);
  }
}

template <typename T>
void list<T>::push_back(T element) {
  if (this->empty()) {
    this->ptr_front = new node::single<T>(element);
  } else {
    auto aux = this->ptr_front;
    while (aux != nullptr) {
      if (aux->next == nullptr) {
        aux->next = new node::single<T>(element);
        break;
      }
      aux = aux->next;
    }
  }
}

// Capacity

template <typename T>
bool list<T>::empty() {
  return this->ptr_front == nullptr;
}
}  // namespace linked
}  // namespace lesson

template class lesson::linked::list<int>;
