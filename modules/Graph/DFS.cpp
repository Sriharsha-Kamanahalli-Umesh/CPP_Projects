#include <iostream>
#include <stack>
// using recusrion
void DFSRecusrion(int A[][6], int start, int n)
{
    static int visited[6] = {0};
    std::stack<int> s;

    if(visited[start]==0)
    {
        std::cout << start << " ";
        visited[start] = 1;
        for(int j=0; j<n; j++)
        {
            if((A[start][j]==1) && (visited[j]==0))
            {
                DFSRecusrion(A, j, n);
            }
        }
    }
}

//Using Stack
void DFSStack(int A[][6], int start, int n)
{
    static int visited[6] = {0};
    std::stack<int> s;
    s.emplace(start);
    
    while(!s.empty())
    {
        int stackEle = s.top();
        s.pop();
        if(visited[stackEle]==0)
        {
            std::cout << stackEle << " ";
            visited[stackEle] = 1;

            for(int j=0; j<n; j++)
            {
                if((A[stackEle][j]==1) && (visited[j]==0))
                {
                    s.emplace(j);
                }
            }
        }
    }
}
int main()
{
    int A[6][6] = { {0, 1, 1, 0, 0, 0},
                    {1, 0, 0, 1, 0, 0},
                    {1, 0, 0, 1, 0, 1},
                    {0, 1, 1, 0, 1, 0},
                    {0, 0, 0, 1, 0, 0},
                    {0, 0, 1, 0, 0, 0}};

    DFSRecusrion(A, 0, 6);
    std::cout <<"\n";

    DFSStack(A, 0, 6);
    std::cout <<"\n";
    return 0;
}