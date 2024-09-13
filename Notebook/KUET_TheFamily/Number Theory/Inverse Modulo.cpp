int power(int a,int b) {
    int ans = 1;
    while(b) {
        if(b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int inverese(int x) {
    return power(x, MOD - 2);
}