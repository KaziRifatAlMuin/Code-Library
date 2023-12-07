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
        ans *= (a%MOD);
        ans = ans%MOD;
        //cout<<ans<<" ";
    }
    return ans;
}

void solve()
{
    ll n, l, ans=0;
    cin>>n>>l;
    int fq[26] = {0};
    vector <string> s;
    string str;
    for(int j=0; j<n; j++){
        cin>>str;
        ll len = str.length();
        ll ch = 0;
        for(int i=0; i<len; i++){
            if(fq[str[i]-'a']!=0){
                ch++;
                //cout<<ch<<endl;
            }
            fq[str[i]-'a']++;
        }
        ans += ((power(len,l)%MOD - power(ch,l)%MOD)%MOD);
        //cout<<power(len,l)<<" "<<power(ch,l)<<endl;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;

}
 
int main()
{
    FAST_IO;
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
    int t = 1, case_number = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}