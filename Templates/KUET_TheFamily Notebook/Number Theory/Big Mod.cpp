ll bigMod(ll a,ll b,ll MOD) 
{
    ll res = 1;
    bool flag = (a >= MOD);
    while(b)
    {
        if (b & 1)
        {
            res *= a;
            if (res >= MOD)
            {
                flag = true;
                res %= MOD;
            }
        }
        a *= a;
        if (a >= MOD)
        {
            flag = 1;
            a %= MOD;
        }
        b >>= 1;
    }
    return (res + (flag * MOD)) % MOD;
}