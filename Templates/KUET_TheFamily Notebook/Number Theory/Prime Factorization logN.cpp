const int N = 1e6+9;
int lpf[N+5];
void pre_calculate()
{
    for(int i=2;i<=N;i++)
    {
        lpf[i] = i;
    }
    for(int i=2;i*i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            lpf[j] = min(lpf[j], i);
        }
    }
}
void find_prime_factorizations(int n, unordered_map<int,int> &mp)
{
    while(n > 1)
    {
        mp[lpf[n]]++;
        n /= lpf[n];
    }
}
void solve()
{
    unordered_map<int,int> mp;
    find_prime_factorizations(900900, mp);
    for(auto x : mp)
    {
        cout << x.first << " " << x.second << "\n";
    }
}
