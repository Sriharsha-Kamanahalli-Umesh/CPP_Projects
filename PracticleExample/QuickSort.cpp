#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i=low+1;
    int j=high;

    while(true)
    {
        while(i<=j && A[i] <= pivot)
        {
            i++;
        }

        while(j>=i && A[j] >= pivot)
        {
            j--;
        }

        if( j < i)
        {
            break;
        }
        else{
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}
void QuickSort(int A[], int low, int high)
{
    if(low < high)
    {
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
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
    QuickSort(A, 0, 7);

    std::cout << "After Sorting" <<"\n";

    for(int i=0; i<8; i++)
    {
        std::cout<< A[i] << " "; 
    }



}

