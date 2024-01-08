#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int >> vec(n + 1);
    for(int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        vec[i] = {v, w};
    }
    sort(vec.begin(), vec.end());
    multiset<int> mst;
    for(int i = 1; i <= n / 2; i++) {
        mst.insert(vec[i].second);
    }
    int limit = n / 2;
    if(n & 1) limit++;
    vector<int> ans;
    for(int i = n; i > limit; i-- ) {
        auto halka = mst.upper_bound(vec[i].second);
        if(halka != mst.begin()) {
            halka--;
            if(halka != mst.begin()) {
                ans.push_back(vec[i].first);
                mst.erase(halka);
            }
        }
        auto vari = mst.lower_bound(vec[i].second);
        if(vari != mst.begin() && vari != mst.end()) {
            int val = *vari;
            int v = vec[i].first - (val - vec[i].second);
            int check = *(mst.begin());
            if(v > check) {
                ans.push_back(v);
                mst.erase(vari);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ((ans.size() == 0) ? vec[1].first : ans[0]) << "\n";
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
    cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}
