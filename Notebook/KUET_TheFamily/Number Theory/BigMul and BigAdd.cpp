ll bigMul(ll a, ll b, ll M)
{
    ll res = 0;
    a = a % M;
    while(b)
    {
        if(b&1)
        {
            res = (res + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return res;
}
ll bigMod(ll a,ll b, ll M)
{
    ll res = 1;
    a = a % M;
    while(b)
    {
        if(b&1)
        {
            res = bigMul(res,a,M);
        }
        a = bigMul(a,a,M);
        b >>= 1;
    }
    return res;
}
ll inverse(ll a, ll b,ll M)
{
    return bigMul(a, bigMod(b,M-2,M), M);
}