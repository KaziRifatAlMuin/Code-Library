class SegTlazy {
public:
    #define lc (nd << 1)
    #define rc (lc | 1)
    struct node {
        int max_sub, pre_sum, suf_sum, tot_sum;
        ll val, lazy;
        node() {};
        node(int _ms, int _ps, int _ss, int _ts) {
            max_sub = _ms;
            pre_sum = _ps;
            suf_sum = _ss;
            tot_sum = _ts;
        }
    };
    vector<int> a;
    vector<node> t;
    int n;
    SegTlazy() {
        a.clear();
        t.clear();
        n = 0;
    }   
    SegTlazy(int n) {
        this -> n = n;
        a.resize(n + 1, 0);
        t.resize(4*n + 1, node());
    }
    void takeInput() {
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
    }
    // merge sort tree
    void merge(node &ND, node L, node R) {
        int l = 0, r = 0;
        while(l < L.vec.size() && r < R.vec.size()) {
            if(L.vec[l] <= R.vec[r]) {
                ND.vec.push_back(L.vec[l++]);
            }
            else {
                ND.vec.push_back(R.vec[r++]);
            }
        }
        while(l < L.vec.size()) {
            ND.vec.push_back(L.vec[l++]);
        }
        while(r < R.vec.size()) {
            ND.vec.push_back(R.vec[r++]);
        }
    }
    // sub array sum
    void merge(node &nd, node l, node r) {
        if(l.tot_sum == inf) {
            nd = r;
            return;
        }
        if(r.tot_sum == inf) {
            nd = l;
            return;
        }
        nd.max_sub = max({l.max_sub, r.max_sub, 
            l.suf_sum + r.pre_sum});
        nd.pre_sum = max(l.pre_sum, l.tot_sum + 
            r.pre_sum);
        nd.suf_sum = max(r.suf_sum, r.tot_sum + 
            l.suf_sum);
        nd.tot_sum = l.tot_sum + r.tot_sum;
    }
    void push(int nd, int b, int e) {
        if(lazy[nd] == 0) return;
        // addition and min/max 
        // also used for arithmatic progression
        t[nd] += lazy[nd];
        lazy[l] += lazy[nd];
        // multiplication and sum
        t[nd] = (t[nd] * lazy[nd]) % MOD;
        lazy[l] = (lazy[l] * lazy[nd]) % MOD;
        // addition and sum
        t[nd].val = t[nd].val + (1LL * (e - b + 1) * lazy[nd]);
        lazy[l] += lazy[nd];
        // assignment and min/max
        t[nd] = lazy[nd];
        lazy[l] = lazy[nd];
        // assignment and sum
        t[nd] = (1LL*(e-b+1) * lazy[nd]);
        lazy[l] = lazy[nd];
        if(b != e) {
            lazy[lc] += lazy[nd];
            lazy[rc] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void build(int nd, int b, int e) {
        lazy[nd] = 0;
        if(b == e) {
            t[nd].val = a[b];
            return;
        }
        int mid = b + e >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        merge(t[nd], t[lc], t[rc]);
    }
    void upd(int nd, int b, int e, int i, int j, ll v) {
        push(nd, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[nd] = v;
            push(nd, b, e);
            return;
        }
        int mid = b + e >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        merge(t[nd], t[lc], t[rc]);
    }
    node query(int nd, int b, int e, int i, int j) {
        push(nd, b, e);
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
    // merge sort tree
    int query(int nd,int b,int e,int i,int j, int k) {
        if(j < b || e < i) {
            return 0;
        }
        if(i <= b && e <= j) {
            return lower_bound(t[nd].vec.begin(), 
                t[nd].vec.end(), k) - t[nd].vec.begin();
        }
        int mid = (b+e) >> 1;
        return query(lc, b, mid, i, j, k) + 
        query(rc, mid+1, e, i, j, k);
    }
};
// arithmatic progression

ll sumIndices(ll L, ll R) {
    return (L + R) * (R - L + 1) / 2;
}

void push(ll nd, ll b, ll e) {
    if(lazyA[nd] == 0 && lazyB[nd] == 0) return;
    ll mid = (b + e) / 2;
    t[lc].val += lazyA[nd] * (mid - b + 1) + lazyB[nd] * sumIndices(b, mid);
    t[rc].val += lazyA[nd] * (e - mid) + lazyB[nd] * sumIndices(mid + 1, e);
    lazyA[lc] += lazyA[nd];
    lazyB[lc] += lazyB[nd];
    lazyA[rc] += lazyA[nd];
    lazyB[rc] += lazyB[nd];

    lazyA[nd] = 0;
    lazyB[nd] = 0;
}
void upd(ll nd, ll b, ll e, ll i, ll j, ll A, ll B) { // ll A = a - b * l;
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            t[nd].val += A * (e - b + 1) + B * sumIndices(b, e);
            lazyA[nd] += A;
            lazyB[nd] += B;
            return;
        }
        push(nd, b, e);
    }
// ** MUST PUSH after all return in upd and query otherwise get WA 

