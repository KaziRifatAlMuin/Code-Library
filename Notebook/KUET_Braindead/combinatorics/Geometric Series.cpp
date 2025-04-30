// a + ar + ar^2 + ar^3 + ... + ar^n-1 = a(r^(n) - 1) / (r - 1)
// 1 + a + a^2 + a^3 + a^4 + .... + a^(n-1) = (a^n - 1) / (a - 1)
ll bigsum(ll a, ll n) {
    if(n == 0 || n == 1) return n % mod;
    if(n & 1) return ((a % mod) * bigsum(a % mod, n - 1) + 1) % mod;
    ll x = bigsum((a * a) % mod, n / 2);
}
inline ll modInverse(ll a) { return power(a, mod - 2); }
ll formula(ll a, ll n){
    if(a == 1) return n;
    return ((power(a, n) - 1) * (modInverse(a - 1))) % mod; // if mod is prime
}