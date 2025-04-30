// here the segTree template
class HLD : public SegTlazy {
public:
    vector<vector<pair<int, int>>> g;
    vector<vector<int>> dp;
    vector<int> heavy, head, pos, par, depth, val;
    int cur, n, Lg;
 
    HLD(int sz) : SegTlazy(sz) {
        n = sz;
        cur = 0;
        Lg = 6;
        heavy.assign(n + 1, 0);
        head.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        par.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        val.assign(n + 1, 0);
        g.resize(n + 1);
        dp.resize(Lg + 1);
        for (int i = 0;i < Lg;i++) dp[i].resize(n + 1, 0);
    } 
 
    void add_edge(int u, int v, int w) {
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
 
    int dfs(int u) {
        int sub = 1, big = 0;
        for(int i = 1; i < Lg; i++) {
            dp[i][u] = dp[i - 1][dp[i - 1][u]];
        }
        for (auto [v, w] : g[u]) {
            if (v == par[u]) continue;
            par[v] = u;
            dp[0][v] = u;
            depth[v] = depth[u] + 1;
            val[v] = w;
            int subsize = dfs(v);
            if (subsize > big) big = subsize, heavy[u] = v;
            sub += subsize;
        }
        return sub;
    }
    int lca(int u, int v) {
        if (depth[v] < depth[u])swap(u, v);
        int diff = depth[v] - depth[u];
        for (int i = 0;i < Lg;i++)
            if (diff & (1 << i)) v = dp[i][v];
        for (int i = Lg - 1;i >= 0;i--)
            if (dp[i][u] != dp[i][v]) u = dp[i][u], v = dp[i][v];
        return u == v ? u : dp[0][u];
    }
    void decompose(int u, int h) {
        head[u] = h, 
        pos[u] = ++cur;
        if (heavy[u]) decompose(heavy[u], h);
        for (auto [v, w] : g[u]) {
            if (v != par[u] && v != heavy[u]) decompose(v, v);
        }
    }
    void makeHLD(int root = 1) {
        dfs(root);
        decompose(root, root);
        for(int i = 1; i <= n; i++) {
            SegTlazy::a[pos[i]] = val[i];
        }
        SegTlazy::build(1, 1, n);
    }
    int pathQuery(int u, int v) {
        node ret;
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            node tmp = SegTlazy::query(1, 1, n, pos[head[v]], pos[v]);
            SegTlazy::merge(ret, ret, tmp);
        }
        if (depth[u] > depth[v]) swap(u, v);
        node tmp = SegTlazy::query(1, 1, n, pos[u] + 1, pos[v]);
        SegTlazy::merge(ret, ret, tmp);
        return ret.val;
    }
    void pathUpdate(int u, int v, int val) {
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
          //  cout<<"Updating:"<<v<<' '<<head[v]<<' '<<val<<endl;
            SegTlazy::upd(1, 1, n, pos[head[v]], pos[v], val);
        }
        if (depth[u] > depth[v]) swap(u, v);
        //cout<<"Updating:"<<v<<' '<<u<<' '<<val<<endl;
        SegTlazy::upd(1, 1, n, pos[u] + 1, pos[v], val);
    }
};
 
void solve() { 
    int n;
    cin>> n;
    HLD hld(n);
    vector<pair<int, int>> edge;
    for(int i=1;i<n;i++){
        int u, v, w;
        cin >> u >> v >> w;
        hld.add_edge(u, v, w);
        edge.push_back({u, v});
    }
    hld.makeHLD();
    while(q--){
        int ty; cin >> ty;
        if(ty == 1) {
            int id, val;
            cin >> id >> val;
            auto [u, v] = edge[id - 1];
            hld.pathUpdate(u, v, val);
        }
        else {
            int u, v;
            cin >> u >> v;
            cout << hld.pathQuery(u, v) << "\n";
        }
    }
}          