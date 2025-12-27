#include <iostream> 

// What allocate() Does

// Purpose: Allocate raw memory for n objects of type T.
// n * sizeof(T) → calculates total bytes needed.
// ::operator new(size) → global operator new, allocates raw memory (uninitialized).
// static_cast<T*> → converts the raw void* pointer returned by operator new into a T*.
template<typename T>
T* allocat(std::size_t size)
{
    T *p = static_cast<T*>(::operator new(size * sizeof(T))); // placement new
    return p;
}

// Example usage of placement new and custom allocator



template<typename T>
class CustomeAllocator {
public:
    CustomeAllocator() = default;

    using value_type = T;

    T* allocate(std::size_t size) {
        T* ptr = static_cast<T*>(::operator new(size * sizeof(T))); // placement new
        std::cout <<  "address allocated at: " << ptr << std::endl;
        return ptr;
    }

    void dealocate(T* p, std::size_t size) {
        std::cout << "deallocating memory at address: " << p << std::endl;
        ::operator delete(p); // deallocate memory
    }
    
    // void construct(T* p, T val) {
    //     new(p) T(val);
    // }


    // void destroy(T* p) {
    //     p->~T(); // explicitly call destructor
    // }


};

int main() {
    // int *p = new int(42); // creating memory on heap with initial value 42
    // std::cout << "Value: " << *p << std::endl;

    // int *q = new(p) int(84); // placement new, constructs int at the location pointed by p
    // std::cout << "New Value using placement new: " << *q << std::endl;
    // delete p;
    // No need to delete q since it points to the same memory as p


    // auto ptr = allocat<int>(10); // allocate memory for 10 integers
    // std::cout << "Allocated memory for 10 integers at address: " << ptr << std::endl;

    // //placement new to construct integers in allocated memory
    // void* raw =  ::operator new(sizeof(int)); // allocate raw memory
    // int* intPtr = new(raw) int(100); // construct integer with value 100
    // std::cout << "Constructed integer using placement new: " << *intPtr << std::endl;


    // Using CustomeAllocator
    CustomeAllocator<double> allocator;
    double *arr = allocator.allocate(5); // allocate memory for 5 doubles
    std::cout << "address allocated at: " << arr << std::endl;
    // for(int i = 0; i < 5; ++i) {
    //     new(&arr[i]) double(i * 1.1); // placement new to construct doubles
    // }

    // for(int i=0; i<5; ++i) {
    //     allocator.construct(&arr[i], i * 1.1);
    // }
    // std::cout << "Allocated and constructed doubles: ";
    // for(int i = 0; i < 5; ++i) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;

    // allocator.dealocate(arr, 5); // deallocate memory

    // for(int i=0; i<5; ++i) {
    //     allocator.destroy(&arr[i]);
    // }

    std::allocator_traits<CustomeAllocator<double>>::construct(allocator, arr, 3.14);
    std::allocator_traits<CustomeAllocator<double>>::destroy(allocator, arr);
    std::allocator_traits<CustomeAllocator<double>>::deallocate(arr, 1);
    

    std::cout << arr[0] << "\n";
    return 0;
}

/**
 what is the diffrence between ?
 a. int *ptr = new int();
 b. void* raw = ::operator new(sizeof(int))

✅ 1. int *ptr = new int();

What happens:

Allocates memory for one int on the heap.
Constructs the int object (initializes it to 0 because of ()).


Equivalent to:
int *ptr = new int; // uninitializedint 
*ptr = new int(); // value-initialized to 0

Key point: new does allocation + construction in one step.


✅ 2. void* raw = ::operator new(sizeof(int));

What happens:

Allocates raw memory of size sizeof(int) on the heap.
Does NOT call the constructor or initialize the object.


You only get a void* pointing to raw memory.
To use it, you must manually construct the object using placement new:
int* p = new(raw) int(42); // placement new constructs int at raw memory

Later, you must manually destroy and deallocate:
p->~int();                // call destructor
::operator delete(raw);   // free memory

*/