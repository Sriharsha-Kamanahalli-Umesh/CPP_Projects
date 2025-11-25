#include <iostream>



void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j], &A[j+1]);
            }
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
    BubbleSort(A, 8);

    std::cout << "After Sorting" <<"\n";

    for(int i=0; i<8; i++)
    {
        std::cout<< A[i] << " "; 
    }



}