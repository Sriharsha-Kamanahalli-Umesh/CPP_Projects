#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heap;
    bool isMaxHeap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if(isMaxHeap)
        {
            //MaxHeap
            if (index > 0 && ((heap[index] > heap[parent]))) {
                std::swap(heap[index], heap[parent]);
                heapifyUp(parent);
            }
        }
        else
        {
            //MinHeap
            if (index > 0 && ((heap[index] < heap[parent]))) {
                std::swap(heap[index], heap[parent]);
                heapifyUp(parent);
            }
        }
    }

    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int extreme = index;

        if(isMaxHeap)
        {
            if(leftChild < heap.size() && heap[leftChild] > heap[extreme])
            {
                extreme = leftChild;
            }
            if(rightChild < heap.size() && heap[rightChild] > heap[extreme])
            {
                extreme = rightChild;
            }
        } 
        else
        {
            if(leftChild < heap.size() && heap[leftChild] < heap[extreme])
            {
                extreme = leftChild;
            }
            if(rightChild < heap.size() && heap[rightChild] < heap[extreme])
            {
                extreme = rightChild;
            }

        }

        if(extreme != index)
        {
            std::swap(heap[index], heap[extreme]);
            heapifyDown(extreme);
        }
    }

public:
    Heap(bool isMaxHeap) : isMaxHeap(isMaxHeap) {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);

    }

    int extract()
    
    {
        if(heap.empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    void printHeap() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Max-Heap Example
    Heap maxHeap(true);
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(50);
    maxHeap.insert(60);

    std::cout << "Max-Heap: ";
    maxHeap.printHeap();

    std::vector<int> MaxHeapSort;
    for(int i=0; i<6; i++)
    {
        try
        {
            int ele = maxHeap.extract();
            std::cout << "Extracted from Min-Heap: " << ele << std::endl;
            std::cout << "Min-Heap after extraction: ";
            maxHeap.printHeap();
            MaxHeapSort.emplace_back(ele);
        }
        catch(const std::runtime_error& e)
        {
            std::cout << e.what() << '\n';
        }

    }
    std::cout<<"\n";
    std::cout<< "Sorted Array Descending order: ";
    for(auto val : MaxHeapSort)
    {
        std::cout << val << " ";
    }
    std::cout<<"\n";
    // Min-Heap Example
    Heap minHeap(false);
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(65);
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(25);

    std::cout << "Min-Heap: ";
    minHeap.printHeap();

    std::vector<int> MinHeapSort;
    for(int i=0; i<6; i++)
    {
        try
        {
            int ele = minHeap.extract();
            std::cout << "Extracted from Min-Heap: " << ele << std::endl;
            std::cout << "Min-Heap after extraction: ";
            minHeap.printHeap();
            MinHeapSort.emplace_back(ele);
        }
        catch(const std::runtime_error& e)
        {
            std::cout << e.what() << '\n';
        }

    }
    std::cout<<"\n";
    std::cout<< "Sorted Array Ascending order: ";
    for(auto val : MinHeapSort)
    {
        std::cout << val << " ";
    }
    std::cout<<"\n";
    return 0;
}