#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
typedef long long int ll;
typedef vector <int> vi;
typedef vector <long long int> vll;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;
typedef map <int,int> mii;
typedef map <long long int, long long int> mll;
long long int const MOD = 1000000007;

void solve()
{
    ll n, sum = 0;
    cin >> n;
    while(n){
        sum += n;
        n = n >> 1;
    }
    cout << sum << endl;
}

int main()
{
    FAST_IO
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

/*

Coded by RifatALmuiN

Input
_______________________________

_______________________________


Output
_______________________________

_______________________________




*/
