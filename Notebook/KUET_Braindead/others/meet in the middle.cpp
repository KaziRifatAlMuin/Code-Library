const int N = 1e7 + 2;
void subsetsum(int pos, vector<int> &v, ll s, vector<ll> &sum) {
    sum.push_back(s);
    if(pos < v.size()) {
        subsetsum(pos + 1, v, s, sum);
        subsetsum(pos + 1, v, s + v[pos], sum);
        subsetsum(pos + 1, v, s + 2*v[pos], sum);
    }
}
void solve() {  
    int n, k;
    cin >> n >> k;
    vector<int> v1, v2;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(i & 1) v1.push_back(x);
        else v2.push_back(x);
    }
    vector<ll> sum1, sum2;
    subsetsum(0, v1, 0, sum1);
    subsetsum(0, v2, 0, sum2);
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    for(auto x : sum1) {
        int val = k - x;
        if(binary_search(sum2.begin(), sum2.end(), val)) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}  