bitset<17>BS;
BS[1] = BS[7] = 1;
cout<<BS._Find_first()<<endl; // prints 1
bs._Find_next(idx). This function returns first set bit after index idx.for example:
bitset<17>BS;
BS[1] = BS[7] = 1;
cout<<BS._Find_next(1)<<','<<BS._Find_next(3)<<endl; // prints 7,7
So this code will print all of the set bits of BS:
for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
    cout<<i<<endl;
//Note that there isn't any set bit after idx, BS._Find_next(idx) will return BS.size(); same as calling BS._Find_first() when bitset is clear;
int totalStates = 1 << N;
vector<int> dp(totalStates, 0);
// dp[mask] stores the maximum total priority when women corresponding to the set bits in mask are paired.
// The number of set bits in mask gives the index of the man to be paired next.
for (int mask = 0; mask < totalStates; mask++) {
    int i = __builtin_popcount(mask); // current man index
    // Create a bitset for women not yet paired.
    // (~mask) gives the complement bits, then we mask to only N bits.
    bitset<16> unpaired((~mask) & ((1 << N) - 1));
    // Iterate over all unpaired women using _Find_first() and _Find_next()
    for (int j = unpaired._Find_first(); j < unpaired.size(); j = unpaired._Find_next(j)) {
        int newMask = mask | (1 << j);
        dp[newMask] = max(dp[newMask], dp[mask] + priority[i][j]);
    }
}
