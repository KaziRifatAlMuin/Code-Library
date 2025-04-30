# x & -x is the least bit in x.
# for any two value a and b 
a + b = (a ^ b) + 2(a & b)
# iterate over all the subsets of the mask
for (int s=m; ; s=(s-1)&m) {
 ... you can use s ...
 if (s==0)  break;
}
# c = x&-x, r = x+c; (((rˆx) >> 2)/c) | r is the
next number after x with the same number of bits set.
// Turn off the b-th bit (zero-based)
long long turnoff(long long x, long long b) return x & ~(1LL << b);
// Get the lowest active bit
long long lowActive(long long x) return x & (-x);
// Print all subsets of the bitmask x
void subset(long long x)
for (long long i = x; i > 0; i = x & (i - 1))
cout << i << endl;
// Count the number of set bits
int cntset(long long x) return __builtin_popcountll(x);
// Count the number of trailing zeros
int tailzero(long long x) return __builtin_ctzll(x);
// Count the number of leading zeros
int leadzero(long long x) return __builtin_clzll(x);
// Get a bitmask with the rightmost n bits set
long long rightmost_bits(int n) return (1LL << n) - 1;
// Get the position of the highest set bit (zero-based)
int highest_set_bit(long long x) return 63 - __builtin_clzll(x);
// Get the position of the lowest set bit (zero-based)
int lowest_set_bit(long long x) return __builtin_ctzll(x);
// Get the number of bits required to represent x
int bit_length(long long x) return 64 - __builtin_clzll(x);

Some properties of bitwise operations:
a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b
Addition:
a+b = a|b + a&b
a+b = a⊕b + 2(a&b)
Subtraction:
a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))
