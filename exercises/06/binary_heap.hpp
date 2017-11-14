#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <cassert>
#include <iostream>

// min-heap
class BinaryHeap {
private:
    std::vector<int> _nodes;
    std::size_t _size;

    static int parent(int k) { return k == 1 ? -1 : k / 2; }
    static int left(int k) { return k * 2; }
    static int right(int k) { return k * 2 + 1; }

    void sift_up(int k) {
        assert(k > 0);
        if (k == 1) {
            return;
        }

        int p = _nodes[parent(k)];
        if (p > _nodes[k]) {
            std::swap(_nodes[k], p);
            sift_up(parent(k));
        }
    }

    void sift_down(int k) {
//        assert(k <= _size);
        int min_index = k;
        int child = left(k);

        for (int i = 0; i < 2; ++i) {
            if ((child + i) <= _size) {
                if (_nodes[child + i] < _nodes[min_index]) {
                    min_index = child + i;
                }
            }
        }

        if (min_index != k) {
            std::swap(_nodes[k], _nodes[min_index]);
            sift_down(min_index);
        }
    }
public:
    BinaryHeap() : _size(0) {}

    // make_heap
    BinaryHeap(const std::vector<int> items) : _size(items.size()) {
        _nodes.resize(items.size() + 1);
        for (int i = 0; i < _size; ++i) {
            _nodes[i + 1] = items[i];
        }

        for (int i = (int)_size; i > 0; --i) {
            sift_down(i);
        }
    }

    std::size_t size() const { return _size; }

    bool empty() const { return _size == 0; }

    int top() const { return _nodes[1]; }

    void push(int item) {
        _nodes.push_back(item);
        _size++;
        sift_up((int)_size);
    }

    bool pop() {
        if (empty()) {
            return false;
        }
        _nodes[1] = _nodes[_size];
        --_size;
        _nodes.pop_back();
        sift_down(1);
        return true;
    }

    friend std::ostream& operator<<(std::ostream& out, const BinaryHeap& heap) {
        for (int i = 0; i < heap.size() + 1; ++i) {
            out << heap._nodes[i] << " ";
        }

        return out;
    }

    bool is_min_heap() const {
        for (int i = 2; i <= _size; ++i) {
            if (_nodes[parent(i)] > _nodes[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif //BINARY_HEAP_H
