#include <iostream>

void DiagonaMatrix(int &n)
{
    int A[n][n];

    std::cout<< "DIAGONAL MATRIX" <<"\n";
    //Creating Diagnol matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                A[i][j] = i+1;
            }
            else{
                A[i][j] = 0;
            }
        }
            
    }
    //Printing Diagnol matrix
    std::cout <<"\n";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++){
            std::cout << A[i][j] << " ";
        }
        std::cout <<"\n";
    }
    //Printing only Diagnol elements
    std::cout <<"\n";
    int i=0; int j=0;
    for(int k=0; k<n; k++)
    {
        if(i==j)
        {
            std::cout<< A[i][j] <<" ";
            i++; j++;
        }
    }
    std::cout <<"\n";
}

void LowerTriangleMatrix(int n)
{
    int A[n][n];
    std::cout <<"\n";
    std::cout<< "LOWERTRIANGLE MATRIX" <<"\n";
    //Creating Lower Triangle Metrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>=j)
            {
                A[i][j] = i+1;
            }
            else{
                A[i][j] = 0;
            }
        }
    }

    //Printing LowerTriangle matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout <<"\n";
    }
}

void UpperTriangleMatrix(int n)
{
    int A[n][n];
    std::cout <<"\n";
    std::cout<< "UPPERTRIANGLE MATRIX" <<"\n";
    //Creating Upper Triangle Metrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i<=j)
            {
                int index = i*(i+1)/2;
                A[i][j] = i+1;
            }
            else{
                A[i][j] = 0;
            }
        }
    }

    //Printing UpperTriangle matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout <<"\n";
    }
}

void TransPoseMatrix(int n)
{
    int A[n][n];

    std::cout <<"\n";
    std::cout<< "BEFORE TRANSPOSE OF MATRIX" <<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            A[i][j] = i+1;
        }
    }

    //Printing matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            std::cout << A[i][j] << " ";
        }
        std::cout <<"\n";
    }

    std::cout<< "AFTER TRANSPOSE OF MATRIX" <<"\n";
    for(int i=0; i<n; i++)
    {
        std::cout <<"\n";
        for(int j=0; j<n; j++)
        {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    //Printing Transpose matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout <<"\n";
    }

}

int main()
{
    int n=5;
    int A[5][5]={0};
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++){
            std::cout << A[i][j] << " ";
        }
        std::cout <<"\n";
    }
    DiagonaMatrix(n);
    LowerTriangleMatrix(n);
    UpperTriangleMatrix(n);
    TransPoseMatrix(n);
}