int block_size;
class Query {
public:
    int l, r, idx;
    Query(int _l, int _r, int _i) {
        l = _l;
        r = _r;
        idx = _i;
    }
    bool operator < (const Query &other) const {
        if (l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return r < other.r;
    }
};
int cnt = 0;
void add(int x, vector<int> &v, vector<int> &freq) {
    if (freq[v[x]] == 0) cnt++;
    freq[v[x]]++;
}

void remove(int x, vector<int> &v, vector<int> &freq) {
    freq[v[x]]--;
    if (freq[v[x]] == 0) cnt--;
}
void solve() { 
    int n, q;
    cin >> n >> q;
    vector<int> v(n), freq(n);
    block_size = sqrt(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // coordinate compress
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i = 0; i < n; i++) {
        v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
    }
    vector<Query> queries;
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({--l, --r, i});
    }
    sort(queries.begin(), queries.end()); 
    vector<int> ans(q + 1);
    int cur_l = 0, cur_r = -1;
    for(auto qi : queries) {
        while(cur_l > qi.l) add(--cur_l, v, freq);
        while(cur_r < qi.r) add(++cur_r, v, freq);
        while(cur_l < qi.l) remove(cur_l++, v, freq);
        while(cur_r > qi.r) remove(cur_r--, v, freq);
        ans[qi.idx] = cnt;
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
}  