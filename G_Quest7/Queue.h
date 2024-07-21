// Student ID: 20586501
// Queue.h
// 2B-GreenLab-07

#ifndef Queue_h
#define Queue_h

#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
    vector<T> _data;
    size_t _head, _tail;
    static T _sentinel;

public:
    static const int MAX_DISP_ELEMS = 100;

    explicit Queue(size_t size);

    static void set_sentinel(const T& elem) { _sentinel = elem; }
    static T get_sentinel() { return _sentinel; }

    bool is_empty() const { return _head == _tail; }
    size_t size() const { return _tail - _head; }
    void resize(size_t size);

    const T& peek() const;
    bool dequeue();
    bool enqueue(const T& elem);

    string to_string(size_t limit = MAX_DISP_ELEMS) const;

    friend class Tests; // Don't remove this line
};

template <typename T> T Queue<T>::_sentinel = T();

template <typename T> Queue<T>::Queue(size_t size) : _head(0), _tail(0) {
    _data.resize(size + 1);
}

template <typename T> bool Queue<T>::enqueue(const T& elem) {
    if (_head == ((_tail + 1) % _data.size())) {
        return false;
    }
    _data[_tail % _data.size()] = elem;
    _tail++;
    return true;
}

template <typename T> bool Queue<T>::dequeue() {
    if (is_empty()) {
        return false;
    }
    _head++;
    return true;
}

template <typename T> const T& Queue<T>::peek() const {
    if (is_empty()) {
        return _sentinel;
    }
    return _data[_head % _data.size()];
}

template <typename T> void Queue<T>::resize(size_t size) {
    Queue newQueue(size);
    size_t max_size = (size < this->size()) ? size : this->size();
    for (size_t i = 0; i < max_size; i++) {
        newQueue.enqueue(this->peek());
        this->dequeue();
    }
    *this = newQueue;
}

template <typename T> void popalot(Queue<T>& q) {
    while (q.dequeue());
}

template <typename T> string Queue<T>::to_string(size_t limit) const {
    stringstream s_size;
    s_size << this->size();
    string result = "# Queue - size = " + s_size.str() + "\n";
    result += "data :";
    
    for (size_t i = _head; i < _tail; i++) {
        stringstream temp;
        temp << _data[i % _data.size()];
        result += temp.str() + " ";
        if ((i + 1) == limit) {
            result += "...";
            break;
        }
    }

    result += "\n";
    return result;
}

// TODO - Fill in the missing implementations. Experiment with the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code.

#endif /* Queue_h */
