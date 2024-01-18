#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

vector<int> BFSofGraph(vector<int> adj[], int v, int s)
{
    vector<int> bfs;           // to store the bfs traversal
    vector<int> vis(v + 1, 0); // to keep track of visited nodes
    queue<int> q;              // to store the nodes for bfs
    q.push(s);                 // pushing the source node
    vis[s] = 1;                // marking the source node as visited
    while (!q.empty())
    {                         // while the queue is not empty
        int node = q.front(); // storing the front element
        q.pop();              // popping the front element
        bfs.push_back(node);
        for (auto it : adj[node])
        { // traversing the adjacency list of the node
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1; // marking the node as visited
            }
        }
        // Space complexity: O(n + m)
        // Time complexity: O(n + m)
        // runs on all its degree, ie O(2 * m) and O(n) for the queue
        // it works on the principle of level order traversal
        // it is used to find the shortest path between two nodes
        // it is used to find the connected components in a graph
        // it is used to find the diameter of a tree
        // it is used to find the level of each node in a tree
        // it is used to find the minimum spanning tree
        // it is used to find the shortest path in a weighted graph
        // it is used to find the shortest path in a unweighted graph
        // it is used to find the shortest path in a directed graph
        // it is used to find the shortest path in a undirected graph
        // it is used to find the shortest path in a cyclic graph
        // it is used to find the shortest path in a acyclic graph
        // it is used to find the shortest path in a bipartite graph
        // it is used to find the shortest path in a connected graph
        // it is used to find the shortest path in a disconnected graph
        // it is used to find the shortest path in a tree
    }
    return bfs; // returning the bfs traversal
}

int main()
{
    // Breadth First Search
    // Time complexity: O(n + m)
    // Space complexity: O(n + m)
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
    // BFS Function that will take the graph
    // the number of vertices and the source node
    vector<int> bfs = BFSofGraph(list, n, 1);
    // Printing the bfs traversal
    for (auto it : bfs)
    {
        cout << it << " ";
    }
    cout << "\n";

    // Space complexity: O(n + m)
    // Time complexity: O(n + m)
    // runs on all its degree, ie O(2 * m) and O(n) for the queue

    // Example:
    // 5 5
    // 1 2
    // 2 3
    // 3 4
    // 4 5
    // 1 5
    // 1 -> 2
    // 2 -> 1 3
    // 3 -> 2 4
    // 4 -> 3 5
    // 5 -> 4 1
    // 1 2 5 3 4

    return 0;
}