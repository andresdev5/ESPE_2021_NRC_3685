#pragma once
#include <iostream>
#include <functional>
#include "node.h"

template<typename T>
class LinkedList {
    public:
        LinkedList() = default;
        void push_back(const T& value);
        void push_front(const T& value);
        void push_at(const T& value, int index);
        void remove_at(int index);
        Node<T> *at(int index);
        void clear();
        int size();
        bool empty();

        void for_each(std::function<void(Node<T> *, int)> callback);
        void for_each(std::function<void(Node<T>*)> callback);
        void for_each(std::function<void(T, int)> callback);
        void for_each(std::function<void(T)> callback);
        
        void until(std::function<bool(Node<T>*)> callback);
        void until(std::function<bool(T)> callback);

        Node<T> *find(std::function<bool(Node<T> *, int)> callback);
        Node<T>* find(std::function<bool(Node<T>*)> callback);
        Node<T> *find(std::function<bool(T, int)> callback);
        Node<T>* find(std::function<bool(T)> callback);

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
