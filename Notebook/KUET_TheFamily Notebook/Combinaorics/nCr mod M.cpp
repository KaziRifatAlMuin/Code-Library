const int N = 1e6 + 9, MOD = 1e9 + 7;
int f[N];

void preFact() {
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = (1LL * f[i - 1] * i) % MOD;
    }
}

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int inverse(int x) {
    return power(x, MOD - 2);
}

int nCr(int n, int r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * inverse(f[r]) % MOD * inverse(f[n - r]) % MOD;
}

void solve() {
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) % MOD << "\n";
}

int main() {
    preFact();
    solve();
    return 0;
}
