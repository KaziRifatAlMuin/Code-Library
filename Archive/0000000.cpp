#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, odd, even, ans;
    cin >> s;
    if(k & 1){
        for(int i = 0; i < n; i++){
            if(i & 1){
                even.push_back(s[i]);
            }
            else{
                odd.push_back(s[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        for(int i = 0, a = 0, b = 0; i < n; i++){
            if(i & 1){
                ans.push_back(even[a++]);
            }
            else{
                ans.push_back(odd[b++]);
            }
        }
        cout << ans << endl;
    }
    else{
        sort(s.begin(),s.end());
        cout << s << endl;
    }
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
    