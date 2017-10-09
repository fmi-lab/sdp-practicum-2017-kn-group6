#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <cassert>
#include "list.hpp"

template <typename T>
class Node {
public:
    T _value;
    Node *_next;

    Node(int value = T(), Node *next = nullptr)
            : _value(value), _next(next) {}
};

template <typename T>
class LinkedList : public List<T> {
private:
    Node<T> *_head;
    std::size_t _size;

    /**
     * @param position
     * @return the node preceding the given position
     */
    Node<T>* find_predecessor(int position) {
        assert(position > 0);
        assert(position < _size + 1);

        Node<T> *curr = _head;
        int i = 0;
        while (i < position - 1) {
            curr = curr->_next;
            ++i;
        }
        return curr;
    }
public:
    Node<T>* head() const {
        return _head;
    }

    LinkedList() : _head(nullptr), _size(0) {}

    LinkedList(std::initializer_list<T> list) : LinkedList() {
        if (list.size() == 0) {
            return;
        }

        const T *iter = list.begin();
        const T *const end = list.end();

        Node<T> *head = new Node<T>(*iter);
        _head = head;

        // TODO: what if we just did push_back N times? O(N^2)
        ++iter;
        while (iter != end) {
            Node<T> *new_node = new Node<T>(*iter);
            _head->_next = new_node;
            _head = _head->_next;
            ++iter;
        }

        _head = head;
        _size = list.size();
    }

    LinkedList(const LinkedList &other) : LinkedList() {
        if (other.empty()) {
            return;
        }

        Node<T> *new_head = new Node<T>(*other._head);
        _head = new_head;
        Node<T> *curr = other._head->_next;

        while (curr != nullptr) {
            Node<T> *new_node = new Node<T>(*curr);
            _head->_next = new_node;
            _head = _head->_next;

            curr = curr->_next;
        }

        _head = new_head;
        _size = other._size;
    }

    ~LinkedList() {
        clear();
    }

    const std::size_t size() const override {
        return _size;
    }

    bool empty() const override {
        return _head == nullptr;
    }

    T& front() const override {
        // TODO: return nullptr when no value
        return _head->_value;
    }

    T& back() const override {
        Node<T> *curr = _head;

        while (curr->_next != nullptr) {
            curr = curr->_next;
        }

        return curr->_value;
    }

    T& get(int position) const override {
        if (position < 0 || _size <= position) {
            // TODO: return nullptr
        }

        Node<T> *curr = _head;
        int i = 0;

        while (i < position && curr->_next != nullptr) {
            curr = curr->_next;
            ++i;
        }

        return curr->_value;
    }

    void push_front(const T& value) override {
        if (empty()) {
            _head = new Node<T>(value);
        } else {
            Node<T> *new_head = new Node<T>(value, _head);
            _head = new_head;
        }

        ++_size;
    }

    bool pop_front() override {
        if (empty()) {
            return false;
        }

        Node<T> *old_head = _head;
        _head = _head->_next;
        delete old_head;
        --_size;
        return true;
    }

    void push_back(const T& value) override {
        if (empty()) {
            _head = new Node<T>(value);
        } else {
            Node<T> *last = find_predecessor(static_cast<int>(_size));
            last->_next = new Node<T>(value);
        }
        ++_size;
    }

    bool pop_back() override {
        if (empty()) {
            return false;
        } else if (size() == 1) {
            delete _head;
            _head = nullptr;
        } else {
            Node<T> *predecessor = find_predecessor(static_cast<int>(_size - 1));
            Node<T> *last = predecessor->_next;
            predecessor->_next = nullptr;
            delete last;
        }

        --_size;
        return true;
    }

    void insert(int position, const T& value) override {
        if (position < 0 || _size < position) {
            return;
        } else if (position == 0) {
            push_front(value);
        } else if (position == _size) {
            push_back(value);
        } else {
            Node<T> *predecessor = find_predecessor(position);
            Node<T> *next = predecessor->_next;

            // prev -> new_node -> next (can be NULL)
            Node<T> *new_node = new Node<T>(value, next);
            predecessor->_next = new_node;

            ++_size;
        }
    }

    bool erase(int position) override {
        if (_size == 0) {
            return false;
        } else if (position < 0 || _size <= position) {
            return false;
        } else if (position == 0) {
            return pop_front();
        } else if (position == _size - 1) {
            return pop_back();
        } else {
            Node<T> *predecessor = find_predecessor(position);
            Node<T> *to_be_removed = predecessor->_next;
            // from: predecessor -> to_be_removed -> next
            // to:   predecessor ------------------> next
            predecessor->_next = to_be_removed->_next;
            delete to_be_removed;
            --_size;
            return true;
        }
    }

    bool clear() override {
        if (empty()) {
            return false;
        }
        while (!empty()) {
            pop_front();
        }
        return true;
    }
};

#endif
