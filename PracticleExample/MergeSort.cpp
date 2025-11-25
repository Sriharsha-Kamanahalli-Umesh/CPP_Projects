#include <iostream>

void Merging(int A[], int B[], int n, int m, int C[])
{
    int i = 0;
    int j = 0;
    int k=0;
    while(i<n && j<m)
    {
        if(A[i]>B[j])
        {
            C[k++] = B[j];
            j++;
        }
        else
        {
            C[k++] = A[i];
            i++;
        }
    }

    for(;i<n; i++)
    {
        C[k++] = A[i]; 
    }

    for(;j<m; j++)
    {
        C[k++] = B[j];
    }
}

void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k=low;
    int C[high+1];
    while(i<=mid && j<=high)
    {
        if(A[i]>A[j])
        {
            C[k++] = A[j];
            j++;
        }
        else
        {
            C[k++] = A[i];
            i++;
        }
    }

    for(;i<=mid; i++)
    {
        C[k++] = A[i]; 
    }

    for(;j<=high; j++)
    {
        C[k++] = A[j];
    }


    for(int i=0; i<high; i++)
    {
        A[i] = C[i];
    }
}

void MergeSort(int A[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);

    }
}

int main()
{
    int A[8] = {10, 20, 30, 40, 50, 60, 90, 100};

    int B[8] = {70, 80, 110, 120, 130, 140, 150, 160};

    int C[16]={0};

    Merging(A, B, 8, 8, C);

    std::cout<< "After Merging" <<"\n";

    for(int i=0; i<16; i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout<<"\n";

    int D[10] = {20, 40, 60, 30, 50, 10, 80, 70, 90, 100};
    MergeSort(D, 0, 10);

    std::cout<< "After MergeSort" <<"\n";

    for(int i=0; i<10; i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout<<"\n";
}