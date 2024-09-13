vector<int> g[N+5];
int vis[N+5], par_arr[N+5];
void dfs(int u,int par,bool &status,int &node) {
    if(status) return;
    vis[u] = 1;
    par_arr[u] = par;
    for(auto v : g[u]) {
        if(vis[v]==0) {
            dfs(v,u,status,node);
            if(status) return;
        }
        if(vis[v] == 1 && v != par) {
            par_arr[v] = u;
            status = true; // cycle detected
            node = v;
            return;
        }
    }
    vis[u] = 2;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool ok = false;
    int node;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i, i, ok, node);
        }
        if(ok) break;
    }
    if(!ok) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> ans;
        ans.push_back(node);
        int child = par_arr[node];
        while(child != node) {
            ans.push_back(child);
            child = par_arr[child];
        }
        ans.push_back(node);
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x << " ";
        }
    }
} 