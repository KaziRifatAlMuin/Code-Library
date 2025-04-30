
struct DSU
{
    vector<ll> par, rank, sz;
    int nn;
    DSU(int n) : par(n + 1), rank(n + 1, 0), sz(n + 1, 1), nn(n)
    {
        for (int i = 1; i <= n; ++i)
        {
            par[i] = i;
        }
    }
    void make(int v)
    {
        par[v] = v;
        sz[v] = 1;
    }
    ll find(int v)
    {
        // path compression
        if (par[v] == v)
        {
            return v;
        }
        return par[v] = find(par[v]);
    }
    ll findp(int v)
    {
        // no path compression
        if (par[v] == v)
        {
            return v;
        }
        return find(par[v]);
    }
    bool same(int u, int v)
    {
        return findp(u) == findp(v);
    }
    int get_size(int v)
    {
        return sz[findp(v)];
    }
    int count()
    {
        return nn; // connected components
    }
    void merge(int u, int v)
    {
        u = findp(u);
        v = findp(v);
        if (u == v)
        {
            return;
        }
        nn--;
        if (rank[u] > rank[v])
        {
            swap(u, v);
        }
        par[u] = v;
        sz[v] += sz[u];
        if (rank[u] == rank[v])
        {
            rank[v]++;
        }
        // v is the parent;
    }
};