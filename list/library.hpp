#ifndef LIST_LIBRARY_H
#define LIST_LIBRARY_H

#include "linked_list.hpp"

template<typename T>
int count(Node<T> *list, T x) {
    Node<T> *curr = list;

    int occurrences = 0;
    while (curr->_next != nullptr) {
        if (curr->_value == x) {
            ++occurrences;
        }
        curr = curr->_next;
    }

    return occurrences;
}

template <typename T>
void append(Node<T> *&head1, Node<T> *head2) {
    if (head1 == nullptr) {
        head1 = head2;
    }

    Node<T>* curr = head1;
    while (curr->_next != nullptr) {
        curr = curr->_next;
    }
    curr->_next = head2;
}

template <typename T>
Node<T>* deepCopy(Node<T>* list) {
    return nullptr;
}

template<typename T>
Node<T> *concat(Node<T> *l1, Node<T> *l2) {
    return nullptr;
}

Node<int> *map(Node<int> *list, int (*fn)(int)) {
    // TODO: implement
    return nullptr;
}

template<typename T>
void reverse(Node<T> *&head) {
    Node<T> *curr = head, *prev = nullptr, *next = nullptr;

    while (curr != nullptr) {
        next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

#endif //LIST_LIBRARY_H
