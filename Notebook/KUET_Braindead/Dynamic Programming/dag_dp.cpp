int f(int u, int p, int dest) {
    if(u == dest) {
        return dp[u] = 1;
    }
    int mx = 0;
    if(dp[u] != -1) return dp[u];
    for(auto v : g[u]) {
        if(v != p) {
            f(v, u, dest);
            int cur = dp[v] != 0 ? 1 + dp[v] : 0;
            if(cur > dp[u]) {
                dp[u] = cur;
                mx = cur;
                child[u] = v;
            }
        }
    }
    return dp[u] = mx;
}
