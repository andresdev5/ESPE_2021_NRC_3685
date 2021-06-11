#pragma once
#include "linked_list.h"
#include "node.h"
#include <stdexcept>

template<typename T>
class DoubleLinkedList {
    public:
        DoubleLinkedList() = default;
        void push_back(const T& value);
        void push_front(const T& value);

        void for_each(std::function<void(Node<T>*)> callback);
        void for_each(std::function<void(T)> callback);

        Node<T>* find(std::function<bool(Node<T>*)> callback);
        Node<T>* find(std::function<bool(T)> callback);

        Node<T> *last();

        int size();

    private:
        Node<T> *head = nullptr;
        int _size = 0;
};

template<typename T>
void DoubleLinkedList<T>::push_back(const T& value) {
    // increment size
    _size++;

    // create new node instance
    Node<T> *node = new Node<T>(value);

    // head is nullptr, so replace new node with head
    if (head == nullptr) {
        head = node;
        return;
    }

    // get last node
    Node<T> *last_node = last();

    // add new node and link to the last list node
    last_node->set_next(node);
    node->set_previous(last_node);
}

template<typename T>
void DoubleLinkedList<T>::push_front(const T& value) {
    
}

template<typename T>
void DoubleLinkedList<T>::for_each(std::function<void(Node<T>*)> callback) {
    Node<T> *current = head;

    while (current != nullptr) {
        callback(current);
        current = current->get_next();
    }
}

template<typename T>
void DoubleLinkedList<T>::for_each(std::function<void(T)> callback) {
    for_each([&](Node<T> *node) {
        callback(node->get_data());
    });
}

template<typename T>
Node<T> *DoubleLinkedList<T>::find(std::function<bool(Node<T>*)> callback) {
    Node<T> *current = head;

    while (current != nullptr) {
        if (callback(current)) {
            return current;
        }

        current = current->get_next();
    }

    return nullptr;
}

template<typename T>
Node<T> *DoubleLinkedList<T>::find(std::function<bool(T)> callback) {
    return find([&](Node<T> *node) -> bool {
        return callback(node->get_data());
    });
}

template<typename T>
Node<T> *DoubleLinkedList<T>::last() {
    Node<T> *last = head;

    while (last->get_next() != nullptr) {
        last = last->get_next();
    }

    return last;
}

template<typename T>
int DoubleLinkedList<T>::size() {
    return _size;
}
