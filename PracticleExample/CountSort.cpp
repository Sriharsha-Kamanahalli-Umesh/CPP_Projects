#include <iostream>
#include <map>

void CountSort(int A[], int n)
{
    std::map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[A[i]] += 1; 
    }

    int i=0;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        while(it->second--)
        {
            A[i++] = it->first;
        }
    }
}


int main()
{
    int A[8] = {60, 40, 80, 70, 50, 10, 20, 30};
    std::cout << "Before Sorting" <<"\n";

    for(int i=0; i<8; i++)
    {
        std::cout<< A[i] << " "; 
    }
    
    std::cout<<"\n";
    CountSort(A, 8);

    std::cout << "After Sorting" <<"\n";

    for(int i=0; i<8; i++)
    {
        std::cout<< A[i] << " "; 
    }



}