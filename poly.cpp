#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
typedef long double ld;
long long int const MOD = 1e9 + 7;
const int N = 1e5 + 9;

ld dis(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1 - y2));
}

void solve()
{
    int n;
    cin >> n;
    vector <ld> x(n), y(n), mx(n), my(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int n1 = n, n2 = n/2, n3 = n/2;
    ld sum = 0;
    for(int i = 1; i < n; i++){
        ld d = dis(x[i], y[i], x[i-1], y[i-1]);
        sum += d;
        mx[i-1] = (x[i-1] + x[i]) / 2.0;
        my[i-1] = (y[i-1] + y[i]) / 2.0;
    }
    sum += dis(x[0], y[0], x[n-1], y[n-1]);
    mx[n-1] = (x[0] + x[n-1]) / 2.0;
    my[n-1] = (y[0] + y[n-1]) / 2.0;
    ld ext = 1e9, tmp;
    if(n & 1){
        int step = n / 2;
        int pi = 0, mi = 0;
        while(n1--){
            mi = pi + step;
            if(mi >= n) mi -= n;
            tmp = dis(x[pi], y[pi], mx[mi], my[mi]);
            ext = min(ext, tmp);
            // cout << x[pi] << " " << y[pi] << " " << mx[mi] << " " << my[mi] << " ";
            // cout << ext << "\n";
            pi++;
        }
    }
    else{
        int step = n / 2;
        int pi = 0, qi;
        while(n2--){
            qi = pi + step;
            if(qi >= n) qi -= n;
            tmp = dis(x[pi], y[pi], x[qi], y[qi]);
            ext = min(ext, tmp);
            // cout << x[pi] << " " << y[pi] << " " << mx[mi] << " " << my[mi] << " ";
            // cout << ext << "\n";
            pi++;
        }
        pi = 0, qi;
        while(n3--){
            qi = pi + step;
            if(qi >= n) qi -= n;
            tmp = dis(mx[pi], my[pi], mx[qi], my[qi]);
            ext = min(ext, tmp);
            // cout << x[pi] << " " << y[pi] << " " << mx[mi] << " " << my[mi] << " ";
            // cout << ext << "\n";
            pi++;
        }
    }

    cout << setprecision(10) << fixed << sum + 2 * ext << '\n';
}

int main()
{
    FAST_IO

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
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
    