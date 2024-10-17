#include <iostream>
#include <vector>
#include <algorithm>
class OddCounter 
{
    // Tracks the count of odd numbers encountered
    int mOddCounter = 0;
    public:
    int getCount() const 
    {
        return mOddCounter;
    }
    void update(std::vector<int>& vec) 
    {
        // Capturing this pointer to access member variable mCounter
        std::for_each(vec.begin(),
                    vec.end(),
                    [this](int element){
                                if(element % 2)
                                {
                                    // Accessing member variable through this pointer
                                    this->mOddCounter++; 
                                }
                    });
    }
};

int main() {
    std::vector<int> vec = {12, 3, 2, 1, 8, 9, 0, 2, 3, 9, 7};
    OddCounter counterObj;
    // Passing the vector to OddCounter object
    counterObj.update(vec);
    int count = counterObj.getCount();
    std::cout << "Counter = " << count << std::endl;
    return 0;
}