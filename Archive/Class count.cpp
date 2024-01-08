#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
const long long int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define rng(i,c,n) for(int i=c;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)a.size()
void solve()
{
    ll n,m,k,x,y;
    cin >> n >> m >> k >> x >> y;
    if(n == 1) {
        cout << k/m + (k%m != 0) << " ";
        cout << k/m << " ";
        cout << k/m + (y <= (k%m)) << "\n";
        return;
    }
    if(n == 2) {
        cout << k/(2*m) + (k%(2*m) != 0) << " ";
        cout << k/(2*m) << " ";
        cout << k/(2*m) + (((x-1)*m + y) <= (k%(2*m))) << "\n";
        return;
    }
    ll maxi = 0, mini = 0;
    if(k >= n*m) {
        maxi = 1;
    }
    ll tmp1 = k - m*n;
    maxi += (tmp1/((n-1)*m));
    if(tmp1 % ((n-1)*m) != 0) maxi++;
    cout << maxi << " ";

    if(k > (n-1)*m) {
        mini = 1;
    }
    ll tmp2 = k - m*n;
    mini += tmp2/((2*n-2)*m);
    cout << mini << " ";

    if(x != 1 && x != n) {
        ll cycle = 0;
        if(k - m*n >= 0) cycle++;
        cycle += (k - n*m)/((n-1)*m);
        ll rem = (k - n*m) % ((n-1)*m);
        if(cycle & 1) {
            ll tot = (n - x)*m + y + m;
            if(rem >= tot) {
                cout << cycle + 1 << " ";
            }
            else {
                cout << cycle << " ";
            }
        }
        else {
            ll tot = (x-1)*m + y + m;
            if(rem >= tot) {
                cout << cycle + 1 << " ";
            }
            else {
                cout << cycle << " ";
            }
        }
    }
    else {
        ll cycle = 0;
        if(k - m*n >= 0) cycle++;
        cycle += (k - n*m)/((n-1)*m);
        ll rem = (k - n*m) % ((n-1)*m);
        if(cycle & 1) {
            ll tot = (n-x)*m + y + m;
            if(rem >= tot) {
                cout << mini + 1 << " ";
            }
            else {
                cout << mini << " ";
            }
        }
        else {
            ll tot = (x-1)*m + y + m;
            if(rem >= tot) {
                cout << mini + 1 << " ";
            }
            else {
                cout << mini << " ";
            }
        }
    }

    cout << "\n";
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