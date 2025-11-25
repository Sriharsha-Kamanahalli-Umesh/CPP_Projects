#include <iostream>
#include <vector>
using namespace std;

// adjacency list representation.
int main() {
    int N = 5; // number of nodes
    vector<vector<int>> graph(N);

    // Add edge from node 0 to node 1
    graph[0].push_back(1);

    // Add edge from node 0 to node 2
    graph[0].push_back(2);
    
    // Add edge from node 0 to node 2
    graph[1].push_back(2);

    // Add edge from node 0 to node 3
    graph[1].push_back(3);

    // Print neighbors of node 0
    int i=0;
    while(i<graph.size())
    {
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        std::cout <<"\n";
        i++;
    }
}



// adjacency matrix
#include <iostream>

int main()
{
    int N = 5;
    int graph[N][N] = {0}; // Initialize all values to 0

    // Print the adjacency matrix
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

