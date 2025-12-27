
#include <atomic>
#include <cstddef>
#include <stdexcept>
#include <memory>

namespace lockfree {

namespace spsc {

template<typename T, size_t size>
class Queue {
    static_assert(std::is_trivial<T>::value, "The type T must be trivial");
    static_assert(size > 2, "Buffer size must be bigger than 2");

    public:
    
    /**
     * @brief Adds an element into the queue.
     * Should only be called from the producer thread.
     * @param[in] element
     * @retval Operation success
     */
    bool Push(const T& element);

    /**
     * @brief Removes an element from the queue.
     * Should only be called from the consumer thread.
     * @param[out] element
     * @retval Operation success
     */
    bool Pop(T& element);

    private:
    T _data[size]; /**< Data array */

    std::atomic_size_t _r; /**< Read index */
    std::atomic_size_t _w; /**< Write index */

};

} /* namespace spsc */

} /* namespace lockfree */