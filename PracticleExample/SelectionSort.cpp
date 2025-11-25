#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j]<A[min])
                min = j;
        }

        swap(&A[i], &A[min]);
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
    SelectionSort(A, 8);

    std::cout << "After Sorting" <<"\n";

    for(int i=0; i<8; i++)
    {
        std::cout<< A[i] << " "; 
    }



}