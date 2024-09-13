#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 2e5 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector <ll> v(n), v1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ans = 0;
    while(1){
        v1.push_back(v[v.size()-1]);
        for(int i = v.size() - 1; i > 0; i--){
            if(v[i-1] > v[i]){
                ans++;
                v1.pop_back();
                v1.push_back(v[i-1] + v[i]); 
                v[i-1] = v[i-1] + v[i];
            }
            else{
                v1.push_back(v[i-1]);
            }
        }
        v.clear();
        v = v1;
        v1.clear();
        reverse(v.begin(), v.end());
        for(auto x : v){
            cout << x << " ";
        }
        cout << "\n";

        bool ok = true;
        for(int j = 1; j < v.size(); j++){
            if(v[j-1] > v[j]){
                ok = false;
                break;
            }
        }
        if(ok) break;
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
