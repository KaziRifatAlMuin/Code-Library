int const N = 1e6 + 2, mod = 1000003;
int f[N], invf[N];
void pre() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}
int nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    if(n == 0 && r == 0) return 1;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
// ll Catalan_Number = (nCr(2*n, n) % mod - nCr(2*n, n+1) % mod + mod) % mod;
// Formula: Cn = (1 / (n + 1)) * (2n choose n)
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862
// Examples: Valid parentheses, binary search trees, Dyck paths, polygon triangulations
// Non-crossing handshakes, stack-sortable permutations, rooted planar trees, non-crossing partitions
