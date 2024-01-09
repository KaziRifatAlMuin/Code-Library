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
    vector<int> list[n + 1]; // 1 based indexing
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u); // for undirected graph
    }

    // Printing the adjacency list
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : list[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    // Time complexity: O(n + m) to print the list and
    //                  O(n) to access any element
    //                  O(n + m) to store the graph

    // Space complexity: O(n + m)

    return 0;
}