#pragma once
#include <iostream>
#include <functional>
#include "node.h"

template<typename T>
class LinkedList {
    public:
        LinkedList() = default;

        /**
         * @brief inserta un elemento al final de la lista
         * @param value valor del elemento
         */
        void push_back(const T& value);

        /**
         * @brief inserta un elemento al inicio de la lista
         * @param value valor del elemento
         */
        void push_front(const T& value);

        /**
         * @brief inserta un elemento en una posicion especifica
         * @param value valor del elemento
         * @param index indice en donde se insertara el elemento
         */
        void push_at(const T& value, int index);

        /**
         * @brief elimina un elemento en una posicion especifica
         * @param index indice del elemento a eliminar
         */
        void remove_at(int index);

        /**
         * @brief obtiene el puntero del nodo dado un indice
         * @param index indice del nodo a obtener
         * @return 
         */
        Node<T> *at(int index);

        /**
         * @brief elimina todos los elementos de la lista
         */
        void clear();

        /**
         * @brief obtiene el tamaño de la lista
         */
        int size();

        /**
         * @brief verifica si la lista esta vacia
         * @return true si esta vacia, false si no esta vacia
         */
        bool empty();

        /**
         * @brief recorre la lista y ejecuta una expresion lambda en cada iteracion
         * @param callback
        */
        void for_each(std::function<void(Node<T> *, int)> callback);
        void for_each(std::function<void(Node<T>*)> callback);
        void for_each(std::function<void(T, int)> callback);
        void for_each(std::function<void(T)> callback);

        /**
         * @brief recorre la lista y ejecuta una expresion lambda en cada iteracion hasta que la
         * expresion lambda regrese falso, si regresa falso, el recorrido se detiene.
         * @param callback
         */
        void until(std::function<bool(Node<T>*)> callback);
        void until(std::function<bool(T)> callback);

        /**
         * @brief busca un elemento en la lista dado una expresion lambda
         * @param callback expresion lambda que regresara true o false, si es true se indica que
         * el elemento fue encontrado, caso contrario devuelve false
         * @return un puntero al nodo encontrado o nullptr si no se encontró
         */
        Node<T> *find(std::function<bool(Node<T> *, int)> callback);
        Node<T>* find(std::function<bool(Node<T>*)> callback);
        Node<T> *find(std::function<bool(T, int)> callback);
        Node<T>* find(std::function<bool(T)> callback);

        /**
         * @brief obtiene el puntero del ultimo nodo de la lista
         * @return 
         */
        Node<T>* last();

    private:
        Node<T> *head = nullptr;
        int _size = 0;
};

template<typename T>
void LinkedList<T>::push_back(const T& value) {
    _size++;

    if (head == nullptr) {
        head = new Node<T>(value);
        return;
    }

    Node<T> *last = head;
    Node<T> *node = new Node<T>(value);

    while (last->get_next() != nullptr) {
        last = last->get_next();
    }

    last->set_next(node);
}

template<typename T>
void LinkedList<T>::push_front(const T& value) {
    _size++;

    if (head == nullptr) {
        head = new Node<T>(value);
        return;
    }

    Node<T> *temp = head;
    head = new Node<T>(value);
    head->set_next(temp);
}

template<typename T>
void LinkedList<T>::push_at(const T& value, int index) {
    if (index < 0 || index >= _size) {
        throw std::invalid_argument("index out of bounds");
    }

    if (index == 0 || _size == 0) {
        return push_front(value);
    }

    Node<T> *target = at(index);
    Node<T> *previous = at(index - 1);
    Node<T> *node = new Node<T>(value);

    previous->set_next(node);
    node->set_next(target);
    _size++;
}

template<typename T>
Node<T> *LinkedList<T>::at(int index) {
    if (index < 0 || index >= _size) {
        throw std::invalid_argument("index out of bounds");
    }

    if (index == 0) {
        return head;
    }

    int current_index = 0;
    Node<T> *last = head;

    while (last->get_next() != nullptr) {
        if (current_index == index) {
            break;
        }

        current_index++;
        last = last->get_next();
    }

    return last;
}

template <typename T>
void LinkedList<T>::remove_at(int index) {
    if (index < 0 || index >= _size) {
        throw std::invalid_argument("index out of bounds");
    }
    
    if (index == 0) {
        Node<T> *tmp = head;
        head = head->get_next();
        delete tmp;
    } else if (index == _size - 1) {
        Node<T> *node = last();
        Node<T> *previous = at(index - 1);
        
        previous->set_next(nullptr);
        delete node;
    } else {
        Node<T> *current = at(index);
        Node<T> *previous = at(index - 1);
        Node<T> *next = at(index + 1);
        
        previous->set_next(next);
        delete current;
    }

    _size--;
}

template <typename T>
void LinkedList<T>::clear() {
    while (!empty()) {
        remove_at(0);
    }
}

template<typename T>
int LinkedList<T>::size() {
    return _size;
}

template <typename T>
bool LinkedList<T>::empty() {
    return _size == 0;
}

template<typename T>
void LinkedList<T>::for_each(std::function<void(Node<T>*, int)> callback) {
    Node<T> *current = head;
    int index = 0;

    while (current != nullptr) {
        callback(current, index);
        current = current->get_next();
        index++;
    }
}

template<typename T>
void LinkedList<T>::for_each(std::function<void(Node<T>*)> callback) {
    for_each([&](Node<T> *node, int index) {
        callback(node->get_data());
    });
}

template<typename T>
void LinkedList<T>::for_each(std::function<void(T)> callback) {
    for_each([&](Node<T> *node, int index) {
        callback(node->get_data());
    });
}

template<typename T>
void LinkedList<T>::for_each(std::function<void(T, int)> callback) {
    for_each([&](Node<T> *node, int index) {
        callback(node->get_data(), index);
    });
}

template<typename T>
void LinkedList<T>::until(std::function<bool(Node<T>*)> callback) {
    Node<T> *current = head;

    while (current != nullptr) {
        if (!callback(current)) break;
        current = current->get_next();
    }
}

template<typename T>
void LinkedList<T>::until(std::function<bool(T)> callback) {
    until([&](Node<T> *node) {
        return callback(node->get_data());
    });
}

template<typename T>
Node<T> *LinkedList<T>::find(std::function<bool(Node<T> *, int)> callback) {
    Node<T> *current = head;
    int index = 0;

    while (current != nullptr) {
        if (callback(current, index++)) {
            return current;
        }

        current = current->get_next();
    }

    return nullptr;
}

template<typename T>
Node<T> *LinkedList<T>::find(std::function<bool(Node<T> *)> callback) {
    return find([&](Node<T> *node, int index) -> bool {
        return callback(node->get_data());
    });
}

template<typename T>
Node<T> *LinkedList<T>::find(std::function<bool(T)> callback) {
    return find([&](Node<T> *node, int index) -> bool {
        return callback(node->get_data());
        });
}

template<typename T>
Node<T> *LinkedList<T>::find(std::function<bool(T, int)> callback) {
    return find([&](Node<T> *node, int index) -> bool {
        return callback(node->get_data(), index);
    });
}

template<typename T>
Node<T> *LinkedList<T>::last() {
    Node<T> *last = head;

    while (last->get_next() != nullptr) {
        last = last->get_next();
    }

    return last;
}
