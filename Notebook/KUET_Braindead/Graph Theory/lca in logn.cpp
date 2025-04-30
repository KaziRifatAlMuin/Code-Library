class LCA {
public:
    int n;
    vector<vector<int>> g, par;
    vector<int> dep, sz;
    int lg;
    LCA(){}
    LCA(int n) {
        this -> n = n;
        g.assign(n + 1, vector<int>());
        lg = log2(n) + 1;
        par.assign(n + 1, vector<int>(lg + 1, 0));
        dep.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        take_input();
    }
    void take_input() {
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    void dfs(int u = 1, int p = 0) {
        par[u][0] = p;
        dep[u] = dep[p] + 1;
        sz[u] = 1;
        for(int i = 1; i <= lg; i++) {
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
        for(auto v : g[u]) {
            if(v != p) {
                dfs(v, u);
                sz[u] += sz[v];
            } 
        }
    }
    int lca(int u, int v) {
        if(dep[u] < dep[v]) swap(u, v); // make sure that dep[u] > dep[v]
        for(int k = lg; k >= 0; k--) {
            if(dep[par[u][k]] >= dep[v]) u = par[u][k];
        }
        if(u == v) return v;
        for(int k = lg; k >= 0; k--) {
            if(par[u][k] != par[v][k]) {
                u = par[u][k];
                v = par[v][k];
            }
        } 
        return par[u][0];
    }
    int kth(int u, int k) {
        for(int i = 0; i <= lg; i++) {
            if(k & (1 << i)) {
                u = par[u][i];
            }
        }
        return u;
    }
    int dist(int u, int v) {
        int l = lca(u, v);
        return dep[u] + dep[v] - (2 * dep[l]);
    }
    // kth node from u to v, 0th node is u
    // k < dist(u, v)
    int go(int u, int v, int k) { 
        int l = lca(u, v);
        if(dep[l] + k <= dep[u]) return kth(u, k);
        k -= dep[u] - dep[l];
        return kth(v, dep[v] - dep[l] - k);
    }
} lca_ob;