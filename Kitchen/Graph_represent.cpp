#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    // Graph representation using adjacency matrix
    int adj[n + 1][n + 1];       // 1 based indexing
    memset(adj, 0, sizeof(adj)); // initialize with 0
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }
    // Printing the adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    // Time complexity: O(n^2) to print the matrix and
    //                  O(1) to access any element
    //                  O(n) to store the graph

    // Space complexity: O(n^2)

    return 0;
}