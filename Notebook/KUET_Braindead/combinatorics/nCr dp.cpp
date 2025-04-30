int const N = 10000, mod = 12345;
int C[N][N];
void pre() {
    C[0][0] = 1;
    for(int n = 1; n < N; n++){
        C[n][0] = 1;
        for (int k = 1; k <= n; k++){
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
        }
    }
}