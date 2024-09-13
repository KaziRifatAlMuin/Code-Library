string a, b;
ll dp[11][12][2][2][2];
ll f(int pos, int sum, bool lf, bool uf, bool lz) {
    if(pos == a.size()) return sum | lz;
    ll &ans = dp[pos][sum][lf][uf][lz];
    if(ans != -1) return ans;
    ans = 0;
    int da = a[pos] - '0', db = b[pos] - '0';
    //cout << pos << " " << da << " " << db << "\n";
    for(int i = 0; i <= 9; i++) {
        if(i < da && !lf) continue;
        if(i > db && !uf) continue;

        bool lff = lf, uff = uf, lzz = lz;
        if(i > da) lff = 1;
        if(i < db) uff = 1;
        if(i != 0) lzz = 0;
        int tmp = 0;
        if(i == 0 && !lzz) tmp++;
        ans += f(pos + 1, sum + tmp, lff, uff, lzz);
    }
    return ans;
}