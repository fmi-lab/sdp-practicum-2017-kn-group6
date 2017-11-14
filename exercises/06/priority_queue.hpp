#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template <typename T>
class PriorityQueue {
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual T top() const = 0;
    virtual bool pop() = 0;
    virtual void push(const T&) = 0;
};

#endif //PRIORITY_QUEUE_H
