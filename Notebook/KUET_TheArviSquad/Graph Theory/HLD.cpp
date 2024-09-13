#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const int N = 1e5 + 9;
 
vector<vector<int>> g;
vector<int> heavy, head, pos, par, depth, cost;
 
class SegTlazy {
public:
    #define lc (nd << 1)
    #define rc (lc | 1)
    struct node {
        int val;
        node() {
            val = 0;
        };
        node (int v) {
            val = v;
        }
    };
    vector<int> a;
    vector<node> t;
    int n;   
    SegTlazy(int n) {
        this -> n = n;
        a.resize(n + 1, 0);
        t.resize(4*n + 1, node());
    }
    inline void merge(node &ND, node L, node R) {
        ND.val = max(L.val, R.val);
    } 
    void upd(int nd, int b, int e, int i, int j, int v) {
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            t[nd].val = v;
            return;
        }
        int mid = b + e >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        merge(t[nd], t[lc], t[rc]);
    }
    node query(int nd, int b, int e, int i, int j) {
        if(j < b || e < i) return 0;
        if(i <= b && e <= j) {
            return t[nd];
        }
        int mid = b + e >> 1;
        auto left = query(lc, b, mid, i, j);
        auto right = query(rc, mid + 1, e, i, j);
        node res;
        merge(res, left, right);
        return res;
    }
};
 
class HLD : public SegTlazy {
public:
    int cur_pos;
    int n;
    HLD(int sz) : SegTlazy(sz) {
        n = sz;
        heavy.assign(n + 1, -1);
        head.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        par.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        g.assign(n + 1, vector<int>());
        cur_pos = 0;
    } 
 
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    int dfs(int u = 1) {
        int size = 1, mx_child_size = 0;
        for(auto v : g[u]) {
            if(v != par[u]) {
                par[v] = u;
                depth[v] = depth[u] + 1; 
                int cur_child_size = dfs(v);
                size += cur_child_size;
                if(cur_child_size > mx_child_size) {
                    mx_child_size = cur_child_size;
                    heavy[u] = v; 
                }
            }
        }
        return size;
    }
 
    void decompose(int u = 1, int h = 1) {
        head[u] = h;
        pos[u] = ++cur_pos;
        if(heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for(auto v : g[u]) {
            if(v != par[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }
 
    int query(int a, int b) {
        int res = 0;
        for(; head[a] != head[b]; b = par[head[b]]) {
            if(depth[head[a]] > depth[head[b]]) {
                swap(a, b);
            }
            int cur_heavy_path = SegTlazy::query(1, 1, n, pos[head[b]], pos[b]).val;
            res = max(res, cur_heavy_path);
        }
        if(depth[a] > depth[b]) {
            swap(a, b);
        }
        int last_heavy_path = SegTlazy::query(1, 1, n, pos[a], pos[b]).val;
        return max(res, last_heavy_path);
    }
 
    void update(int u, int val) {
        SegTlazy::upd(1, 1, n, pos[u], pos[u], val);
    }
};

class LCA {
public:
    int n, l;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    LCA(int n) : adj(n), tin(n, 0), tout(n, 0), up(n, {0}), n(n) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int query(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    void build(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }
};
 
void solve() {  
    int n, q;
    cin >> n >> q;
    cost.assign(n + 1, 0);
    HLD hld(n + 1);
    LCA lca(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        hld.add_edge(u, v);
        lca.add_edge(u, v);
    }
    lca.build(1);
    hld.dfs();
    hld.decompose();
    for(int i = 1; i <= n; i++) {
        hld.update(i, cost[i]);
    }
    while(q--) {
        int ty; cin >> ty;
        if(ty == 1) {
            int i, v;
            cin >> i >> v;
            hld.update(i, v);
            cost[i] = v;
        }
        else {
            int i, j;
            cin >> i >> j;
            int nd = lca.query(i, j);
            int ans = max(hld.query(nd, i), hld.query(nd, j));
            cout << max(ans, cost[nd]) << " ";
        }
    }   
}     