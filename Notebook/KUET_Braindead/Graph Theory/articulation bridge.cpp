int timer;
vector<bool> vis;
vector<int> disc, low;
set<pair<int, int>> bridge;
void dfs(int u, int p = -1) {
    vis[u] = 1;
    disc[u] = low[u] = timer++;
    //int children=0; 
    for(auto v : g[u]) {
        if(v == p) continue;
        if(vis[v]) {
            low[u] = min(low[u], low[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) {
                bridge.insert({min(u, v), max(u, v)});
                //IS_CUTPOINT(v);
            }
            //++children;
        }
    }
    //if(p == -1 && children > 1) IS_CUTPOINT(v);
}
void find_bridges(int n) {
    timer = 0;
    vis.assign(n + 1, false);
    disc.assign(n + 1, -1);
    low.assign(n + 1, -1);
    bridge.clear();
    for(int i = 0; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
} 
void solve() {
    find_bridges(n);
    cout << bridge.size() << " critical links\n";
    for(auto [x, y] : bridge) {
        cout << x << " - " << y << "\n";
    }
}  