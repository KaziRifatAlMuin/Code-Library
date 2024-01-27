#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    // Graph representation using adjacency list
    vector<pair<int, int>> list[n + 1]; // 1 based indexing
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; // edge from u to v with weight w
        list[u].push_back({v, w});
        list[v].push_back({u, w}); // for undirected graph
    }

    // Printing the adjacency list
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : list[i])
        {
            cout << "(" << j.first << " " << j.second << ") ";
        }
        cout << "\n";
    }
    // Time complexity: O(n + m) to print the list and
    //                  O(n) to access any element
    //                  O(n + m) to store the graph

    // Space complexity: O(n + m)

    return 0;
}