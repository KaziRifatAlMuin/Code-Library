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
    mll def, atk, hel;
    ll n, k, d, a, h, leave;
    set <ll> poke;
    cin >> n >> k;
    leave = n - k;
    for(int i = 1; i <= n; i++){
        cin >> d >> a >> h;
        def[d] = i;
        atk[a] = i;
        hel[h] = i;
    }
    int j = 0;
    for(auto x : def){
        if(j < leave){
            j++;
            continue;
        }
        poke.insert(x.second);
    }
    j = 0;
    for(auto x : atk){
        if(j < leave){
            j++;
            continue;
        }
        poke.insert(x.second);
    }
    j = 0;
    for(auto x : hel){
        if(j < leave){
            j++;
            continue;
        }
        poke.insert(x.second);
    }
    cout << poke.size() << endl;
}

int main()
{
    FAST_IO
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

/*

Coded by RifatALmuiN

Input
_______________________________

_______________________________


Output
_______________________________

_______________________________




*/
