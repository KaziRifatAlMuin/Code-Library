// generates primes using sieve
void solve() {
    int n, d;
    cin >> n >> d;
    if(n == 0) n = 1;
    map<int, int> nfactmp;
    for(auto p : primes) {
        if(p > n) break;
        for(int j = p; ;j *= p) {
            if(j > n) break;
            nfactmp[p] += (n / j);
        }
    }
    bool flag = true;
    for(auto p : primes) {
        if(d % p == 0) {
            while(d % p == 0) {
                if(nfactmp.find(p) == nfactmp.end()) {
                    flag = false;
                    break;
                }
                nfactmp[p]--;
                d /= p;
            }
        }
        if(!flag) break;
    }
    if(d > 1) {
        if(nfactmp.find(d) == nfactmp.end()) {
            flag = false;
        }
        else nfactmp[d]--;
    }
    if(!flag) {
        cout << 0 << "\n";
        continue;
    }
    ll ans = 1;
    for(auto x : nfactmp) {
        ans *= (x.second + 1);
    }
    if(ans < 0) ans = 0;
    cout << ans << "\n";
}