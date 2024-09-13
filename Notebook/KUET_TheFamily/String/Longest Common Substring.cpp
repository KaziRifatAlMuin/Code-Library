#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;

const int N = 2e5 + 9;
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
    return (ans % mod);
}
void preCalc() {
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
    } 
    for(int i = 1; i < N; i++) {
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
    } 
    int invpw1 = bigMod(p1, mod1 - 2, mod1);
    int invpw2 = bigMod(p2, mod2 - 2, mod2);
    invpw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        invpw[i].first = 1LL * invpw[i-1].first * invpw1 % mod1;
        invpw[i].second = 1LL * invpw[i-1].second * invpw2 % mod2;
    }
}

class  Hash_node {
public:
    int n;
    string s;
    vector<pair<int,int>> hs, prehs;
    Hash_node(){}
    Hash_node(string _s) {
        s = _s;
        n = _s.size();
        hs.resize(n);
        for(int i = 0; i < n; i++) {
            hs[i].first += 1LL * s[i] * pw[i].first % mod1;
            hs[i].first %= mod1;
        }
        for(int i = 0; i < n; i++) {
            hs[i].second += 1LL * s[i] * pw[i].second % mod2;
            hs[i].second %= mod2;
        }
        prehs.resize(n);
        prehs[0].first = hs[0].first;
        for(int i = 1; i < n; i++) {
            prehs[i].first = prehs[i-1].first + hs[i].first;
            prehs[i].first %= mod1;
        }
        prehs[0].second = hs[0].second;
        for(int i = 1; i < n; i++) {
            prehs[i].second = prehs[i-1].second + hs[i].second;
            prehs[i].second %= mod2;
        }
    }
    pair<int,int> getHash(int i,int j) {
        assert(i <= j);
        pair<int,int> ans({0, 0});
        if(i == 0) {
            ans.first = prehs[j].first;
            ans.second = prehs[j].second;
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

pair<bool, string> check(int len, Hash_node &nodeA, Hash_node &nodeB) {
    set<pair<int,int>> st;
    pair<bool, string> ans{false, ""};
    for(int i = 0; i + len - 1 < nodeA.s.size(); i++) {
        st.insert(nodeA.getHash(i, i + len - 1));
    }
    for(int i = 0; i + len - 1 < nodeB.s.size(); i++) {
        auto val = nodeB.getHash(i, i + len - 1);
        if(st.find(val) != st.end()) {
            ans.first = true;
            ans.second = nodeB.s.substr(i, len);
            break;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    Hash_node node_a(a), node_b(b);
    int l = 1, r = n, mid;
    string ans_str = "";
    while(l <= r) {
        mid = (l + r) >> 1;
        auto [x, y] = check(mid, node_a, node_b);
        if(x) {
            ans_str = y;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans_str << "\n";
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