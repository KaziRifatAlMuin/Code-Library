/*
    Author : RifatALmuiN
    Problem : AG - Large Division
    Source : https://vjudge.net/contest/548702
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    ll b, i, div=0;
    string a;
    cin>>a>>b;
    a[0] == '-' ? i=1 : i=0;
    for(i; i<a.length(); i++){
        div = div * 10 + (a[i]-'0');
        div = div % b;
    }
    if(div) cout<<"not divisible\n";
    else cout<<"divisible\n";
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
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

