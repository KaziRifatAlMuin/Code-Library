#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;

const int N = 1e6 + 9;
const int mod1 = 127657753, mod2 = 987654319;
const int p1 = 137, p2 = 277;

pair<int,int> pw[N], invpw[N];
int bigMod(int a,int b,int mod) {
    int ans = 1;
    while(b) {
        if(b & 1) {
            ans = 1LL * ans * a % mod;
        }
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}
void preCalc() {
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
    }
    int inv1 = bigMod(p1, mod1 - 2, mod1);
    int inv2 = bigMod(p2, mod2 - 2, mod2);
    invpw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        invpw[i].first = 1LL * invpw[i - 1].first * inv1 % mod1;
        invpw[i].second = 1LL * invpw[i - 1].second * inv2 % mod2;
    }
}

class hashNode
{
public:
    int n;
    string str;
    vector<pair<int,int>> hs, prehs;
    hashNode(){}
    hashNode(string s) {
        str = s;
        n = s.size();
        hs.resize(n);
        for(int i = 0; i < n; i++) {
            hs[i].first = 1LL * s[i] * pw[i].first % mod1;
            hs[i].second = 1LL * s[i] * pw[i].second % mod2;
        }
        prehs.resize(n);
        prehs[0].first = hs[0].first;
        prehs[0].second = hs[0].second;
        for(int i = 1; i < n; i++) {
            prehs[i].first = prehs[i - 1].first + hs[i].first;
            prehs[i].first %= mod1;
            prehs[i].second = prehs[i - 1].second + hs[i].second;
            prehs[i].second %= mod2;
        }
    }
    pair<int,int> getHash(int i,int j) {
        assert(i <= j);
        pair<int,int> ans{0, 0};
        if(i == 0) {
            ans.first = 1LL * prehs[j].first * invpw[i].first % mod1;
            ans.second = 1LL * prehs[j].second * invpw[i].second % mod2;
        }
        else {
            ans.first = (prehs[j].first - prehs[i-1].first + mod1) % mod1;
            ans.first = 1LL * ans.first * invpw[i].first % mod1;
            ans.second = (prehs[j].second - prehs[i-1].second + mod2) % mod2;
            ans.second = 1LL * ans.second * invpw[i].second % mod2;
        }
        return ans;
    }
};
// return LCP(lowest common prefix) of str[i.........j] and str[x.........y]
int findLCP(hashNode &node, int i, int j, int x, int y) {
    int len = min(j - i + 1, y - x + 1);
    int l = 1, r = len, mid, ans;
    while(l <= r) {
        mid = l + r >> 1;
        if(node.getHash(i, i + mid - 1) == node.getHash(x, x + mid - 1)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    string str;
    cin >> str;
    hashNode node(str);
    cout << findLCP(node, 0, 1, 2, 6);
}    
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    preCalc();
    int t = 1, cs = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}