// return kth number in [i.......j]
class mergeSortTree  {
public:
    #define lc (nd << 1)
    #define rc (lc | 1)
    struct node {
        vector<ll> vec;
        node() {
            vec.clear();
        }
        node(vector<ll> v) {
            vec = v;
        }
    };
    vector<int> a;
    vector<node> t;
    int n;
    mergeSortTree() {
        a.clear();
        t.clear();
        n = 0;
    }   
    mergeSortTree(int n) {
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
    void build(int nd,int b,int e) {
        if(b == e) {
            t[nd].vec.push_back(a[b]);
            return;
        }
        int mid = b + e >> 1;
        build(lc, b, mid);
        build(rc, mid+1, e);
        merge(t[nd], t[lc], t[rc]);
    } 
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