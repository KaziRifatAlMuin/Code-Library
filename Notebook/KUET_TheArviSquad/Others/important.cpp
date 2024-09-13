
> if ans % mod is used never divide ans 
with only val must use inverse modulo 
for example the final ans is 'ans / 2'
so this is must be ans * inverse_modulo(2); 
> if there is any subtract operation, 
mod must be add with the value 
ans = ans + div_group_sum(pos-1, 
(sum + (a[pos] % d + d) % d) % d, cnt - 1);
not ans = ans + div_group_sum(pos-1, 
(sum + (a[pos]  % d), cnt - 1);
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
> #pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,
lzcnt,abm,bmi,bmi2,fma,tune=native")
> # x & -x is the least bit in x.
# iterate over all the subsets of the mask
for (int s=m; ; s=(s-1)&m) {
 ... you can use s ...
 if (s==0)  break;
}
# c = x&-x, r = x+c; (((rˆx) >> 2)/c) 
| r is the
next number after x with the same 
number of bits set.
# __builtin_popcount(x) //number 
of ones in binary
  __builtin_popcountll(x) // for 
  long long
# __builtin_clz(x) // number of 
  leading zeros
  __builtin_ctz(x) // number of 
  trailing zeros, they also have 
  long long version
7. bitset<17>BS;
BS[1] = BS[7] = 1;
cout<<BS._Find_first()<<endl; // prints 1
bs._Find_next(idx). This function 
returns first set bit after index idx.for example:
bitset<17>BS;
BS[1] = BS[7] = 1;
cout<<BS._Find_next(1)<<','<<
BS._Find_next(3)<<endl; // prints 7,7
So this code will print all 
of the set bits of BS:
for(int i=BS._Find_first();
  i< BS.size();i = BS._Find_next(i))
    cout<<i<<endl;
//Note that there isn't any set 
    bit after idx, BS._Find_next(idx) 
    will return BS.size(); same as 
    calling BS._Find_first() when 
    bitset is clear;
*/
/* Game Theory */
>[First Write a Brute Force solution]
>Nim = all xor
>Misere Nim = Nim + corner case: if all piles are 1, reverse(nim)
>Bogus Nim = Nim
>Staircase Nim = Odd indexed pile Nim 
(Even indexed pile doesnt matter, as one player 
can give bogus moves to drop all even piles to ground)
>Sprague Grundy: [Every impartial game under 
the normal play convention is equivalent 
to a one-heap game of nim] 
Every tree = one nim pile = tree root value; 
tree leaf value = 0; tree node value = mex of 
all child nodes.
[Careful: one tree node can become multiple 
new tree roots(multiple elements in one node), 
then the value of that node = xor of all those root values] 
>Hackenbush on graph (instead of tree given 
an rooted graph): 
fusion: All edges in a cycle can be fused to 
get a tree structure; build a super node, 
connect some single nodes with that super node,
number of single nodes is the number of edges in the cycle.
Sol: [Bridge component tree] mark all bridges, 
a group of edges that are not bridges, becomes 
one component and contributes number of edges 
to the hackenbush. (even number of edges contributes 0, 
odd number of edges contributes 1)

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
