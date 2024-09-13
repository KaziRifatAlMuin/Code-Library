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

class hashNode
{
public:
    int n;
    string str;
    vector<pair<int,int>> prehs;
    hashNode(){}
    hashNode(string s) {
        str = s;
        n = s.size();
        prehs.resize(n);
        prehs[0].first = 1LL * s[0] * pw[0].first % mod1;
        prehs[0].second = 1LL * s[0] * pw[0].second % mod2;
        for(int i = 1; i < n; i++) {
            prehs[i].first = prehs[i - 1].first + (1LL * s[i] * pw[i].first % mod1);
            prehs[i].first %= mod1;
            prehs[i].second = prehs[i - 1].second + (1LL * s[i] * pw[i].second % mod2);
            prehs[i].second %= mod2;
        }
    }
    pair<int,int> getHash(int i,int j) {
        //assert(i <= j);
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