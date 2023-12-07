#include <bits/stdc++.h>
using namespace std;
 
#define pb          push_back
#define eb          emplace_back
#define mem(x,i)    memset(x,i,sizeof(x))
#define ff          first
#define ss          second
#define all(x)      x.begin(),x.end()
#define Q           int t; scanf("%d", &t); for(int q=1; q<=t; q++)
 
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll, ll> pi;
typedef vector <int> vi;
typedef vector <long long int> vll;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;
typedef map <int,int> mii;
typedef map <long long int, long long int> mll;
 
 
const int MOD = 1e9+7 ; //For big mod
template<typename T>inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;} // better than __gcd
ll powmod(ll a,ll b){ll res=1;a%=MOD;if(b<0) return 0;for(; b; b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
 
const int xx[]   = {+1, -1, +0, +0};//, +1, +1, -1, -1}; // exclude last four when side adjacent
const int yy[]   = {+0, +0, +1, -1};//, +1, -1, +1, -1};
const int INF    = 0x3f3f3f3f;// useful for memset
const ll LL_INF  = 0x3f3f3f3f3f3f3f3f;
const double PI  = acos(-1.0);
const double eps = 1e-9;
const int mxn    = 1e5+5; //CHECK here for every problem
const int mod    = 1e9+7;

void solve()
{
    ll n, m, a, ans = 0;
    cin >> n >> m;
    mii mp;
    for(int i = 0; i < n+m; i++){
        cin >> a;
        if(mp.find(a) != mp.end()){
            ans++;
        }
        mp[a] = 0;
    }
    cin >> a >> a;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
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