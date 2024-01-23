const int N = 1005; // Assuming N is the maximum number of nodes

int dp[N];
vector<int> g[N + 5];

// Function to perform depth-first search (DFS) and calculate the maximum depth for each node
int dfs(int u) {
    if (dp[u] != -1)
        return dp[u];

    int ans = 0;
    for (auto v : g[u]) {
        ans = max(ans, 1 + dfs(v));
    }
    return dp[u] = ans;
}

// Function to solve the problem
void solve() {
    int n, m;
    cin >> n >> m;

    // Input edges
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    // Initialize the dp array with -1 to indicate that the depth is not calculated yet
    memset(dp, -1, sizeof dp);

    int ans = 0;

    // Calculate the maximum depth for each node
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << "\n";
}