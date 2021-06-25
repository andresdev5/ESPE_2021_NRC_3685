#pragma once
#include "doubly_linked_list.h"
#include "node.h"
#include <exception>
#include <stdexcept>
#include <functional>

template <typename T>
class Stack {
public:
    /**
     * @brief inserta un elemento a la pila
     * 
     * @param value valor a ser insertado en la pila
     */
    
    void push(T value);

    /**
     * @brief remueve un elemento de la pila
     * 
     */
    void pop();

    /**
     * @brief obtiene un elemento de la pila
     * 
     * @return T elemento obtenido
     */
    T peek();

    /**
     * @brief iterate over stack
     * 
     * @param callback 
     */
    void for_each(std::function<void(T)> callback);

    /**
     * @brief comprueba si la pila esta vacia
     * 
     * @return true en caso de que este vacio
     * @return false en caso de que no este vacio
     */
    bool empty();

    /**
     * @brief obtiene el total de elementos de la pila
     * 
     * @return int total de elementos de la pila
     */
    int count();
    
private:
    DoublyLinkedList<T> elements;
};

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void Stack<T>::push(T value) {
    elements.push_front(value);
}

template <typename T>
void Stack<T>::pop() {
    if (!empty()) {
        elements.remove_at(0);
    }
}

template <typename T>
T Stack<T>::peek() {
    if (empty()) {
        throw std::runtime_error("attempt to get elemento from empty stack");
    }

    return elements.at(0);
}

template <typename T>
void Stack<T>::for_each(std::function<void(T)> callback) {
    elements.for_each(callback);
}

template <typename T>
bool Stack<T>::empty() {
    return elements.empty();
}

template <typename T>
int Stack<T>::count() {
    return elements.size();
}