ll minimum_cost(int l,int r) {
    if(l == r) return 0;
    ll &ans = dp[l][r];
    if(ans != -1) return ans;
    ans = inf;
    ll current_cost = 0;
    for(int i=l;i<=r;i++) {
        current_cost += a[i];
    }
    for(int i=l;i<r;i++) {
        ans = min(ans, current_cost + minimum_cost(l, i)
         + minimum_cost(i+1, r));
    }
    return ans;
}