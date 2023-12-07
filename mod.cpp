/*
    Author : RifatALmuiN
*/
 
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
int const MOD = 998244353;

ll power(ll a, ll b)
{
    ll ans=1;
    for(ll i=0; i<b; i++){
        ans *= a;
        ans = ans%MOD;
    }
    return ans;
}

void solve()
{
    ll a, b, n, ans = 1, i, j;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}
 
int main()
{
    FAST_IO;
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}