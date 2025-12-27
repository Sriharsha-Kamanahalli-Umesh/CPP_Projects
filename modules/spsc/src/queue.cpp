#include "queue.h"

namespace lockfree {

namespace spsc {

template<typename T, size_t size>
Queue<T, size>::Queue() : _r(0), _t(0) {}

template<typename T, size_t size>
bool Queue<T, size>::Push(const T& element)
{
    const size_t w = _w.load(std::memory_order_relaxed);
    size_t w_next = w + 1;
    if (w_next == size) {
        w_next = 0U;
    }

    const size_t r = _r.load(std::memory_order_acquire);
    if (w_next == r) {
        return false;
    }
}
}
}