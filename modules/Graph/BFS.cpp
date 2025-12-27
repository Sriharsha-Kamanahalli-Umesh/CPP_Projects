#include <iostream>
#include <queue>
void BFS(int A[][6], int start, int n)
{
    int visited[6] = {0};
    std::queue<int> q;

    std::cout<< start << " ";
    visited[start] = 1;
    q.emplace(start);

    while(!q.empty())
    {
        int qEle = q.front();
        q.pop();
        for(int j=0; j<n; j++)
        {
            if((A[qEle][j]==1) && (visited[j]==0))
            {
                std::cout<< j << " ";
                visited[j] = 1;
                q.emplace(j);
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

    BFS(A, 0, 6);
    std::cout <<"\n";
}