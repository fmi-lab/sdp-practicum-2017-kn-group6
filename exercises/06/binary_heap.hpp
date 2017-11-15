#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <cassert>
#include "priority_queue.hpp"

using namespace std;

class BinaryHeap : public PriorityQueue<int> {
private:
    vector<int> items;

public:
    int size() const override {
        return items.size();
    }

    bool empty() const override {

    }

    int top() const override {
        assert(!empty());
        return items[0];
    }

    bool pop() override {
        if (empty())
            return false;
        items[0] = items[items.size() - 1];
        items.pop_back();
        bubble_down();

    }

    void bubble_down(int pos = 0) {
//        while(items[])
    }

    void bubble_up(size_t pos) {
        while (pos >= 0 && items[pos] > items[parent(pos)]) {
            std::swap(items[pos], items[parent(pos)]);
            pos = parent(pos);
        }
    }

    void push(const int &item) override {
        items.push_back(item);
        bubble_up(items.size() - 1);
    }

    int parent(int i) const {
        return i / 2 - 1;
    }

    bool is_min_heap() const {
        //int min_item = items.begin();
        for (size_t i = items.size() - 1; i >= 1; i--) {

            if (items[i] < items[parent(i)]) {
                return false;
            }
        }
        return true;
    }
};

#endif //BINARY_HEAP_H
