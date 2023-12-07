/*
    Author : RifatALmuiN
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef vector <int> vi;
typedef vector <long long int> vll;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;
#define pb push_back
#define all(v) v.begin(), v.end()
void solve()
{
    int n,m,i,j;
    set<string> s;
    string str;
    cin>>n>>str;
    for (i=1; i<n; i++)
        s.insert(str.substr(i-1,2));
    cout<<s.size()<<'\n';
}

int main()
{
    FAST_IO;
    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

