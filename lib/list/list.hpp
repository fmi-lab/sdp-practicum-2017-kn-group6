#ifndef LIST_H
#define LIST_H

#include <cstdlib>

template <typename T>
class List {
public:
    virtual const std::size_t size() const = 0;
    virtual bool empty() const = 0;

    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual T get(int) const = 0;

    virtual void push_front(const T&) = 0;
    virtual bool pop_front() = 0;

    virtual void push_back(const T&) = 0;
    virtual bool pop_back() = 0;

    virtual void insert(int, const T&) = 0;
    virtual bool erase(int) = 0;

    virtual bool clear() = 0;
    virtual ~List() {}
};

#endif // LIST
