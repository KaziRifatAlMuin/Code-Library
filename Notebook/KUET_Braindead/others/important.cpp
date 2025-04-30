ans * invmod(2);
(((sum + a[pos]) % mod) + mod) % mod
> Number of trailing zeroes in 
base B representation of N!
as same as finding the highest 
power of B in N!. (Largest power of k in n!)
so the ans is just largestPowerOfB(N, B)
> let a number is N. find x 
such that x^3 <= N and N = x * y
now x contain all prime factor 
less than N^(1/3) 
and y is prime or y = p1 or y = p1 * p2 
> if m and n relatively prime then largest 
number than cant be expressed using n, m is
nm - n - m
> #pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); 
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}
> string str;
getline(cin, str);
stringstream mystream(str);
int l, r, v;
mystream >> l >> r;
string tmp;
mystream << tmp;
> ll find_sq_root(ll n) {
    ll k = sqrtl(n);
    while(k*k < n) ++k;
    while(k*k > n) --k;
    return k;
}
{    
"cmd": ["g++", "$file", "-o", "$file_base_name", "&&", "./$file_base_name", "<", "input.txt"],
"shell": true,    
"selector": "source.c, source.c++",
"path": "/usr/bin"
}