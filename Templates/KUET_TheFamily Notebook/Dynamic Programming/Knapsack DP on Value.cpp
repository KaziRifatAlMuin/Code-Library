int w[N+5], v[N+5];
ll dp[N+5][(N+5)*1000];
// dp[pos][val] returns If I take items from 0 to pos then what is the minimum 
// weight I need. means dp[pos][val] returns the minimum weight if I take 
// 0 to pos items 
ll knapsack(int pos,int val) {
    if(pos < 1) {
        if(val == 0) return 0;
        return inf;
    }
    if(dp[pos][val] != -1) return dp[pos][val];
    ll ans = w[pos] + knapsack(pos-1, val - v[pos]);
    ans = min(ans, knapsack(pos-1, val));
    return dp[pos][val] = ans;
}
void solve() {
    int n, cap;
    cin >> n >> cap;
    int tot = 0;
    for(int i=1;i<=n;i++) {
        cin >> w[i] >> v[i];
        tot += v[i];
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int val=tot;val>=1;val--) {
        if(knapsack(n, val) <= cap) {
            ans = val;
            break;
        }
    }
    cout << ans << "\n";
}