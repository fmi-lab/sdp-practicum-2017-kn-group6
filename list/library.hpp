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

template<typename T>
Node<T> *concat(Node<T> *l1, Node<T> *l2) {
    // TODO: implement
    return nullptr;
}

Node<int> *map(Node<int> *list, int (*fn)(int)) {
    // TODO: implement
    return nullptr;
}

template<typename T>
void reverse(Node<T> *&head) {
    // TODO: implement
}

#endif //LIST_LIBRARY_H
