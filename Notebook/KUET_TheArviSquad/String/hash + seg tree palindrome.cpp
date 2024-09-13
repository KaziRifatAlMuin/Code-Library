const int N = 5e6 + 9;
const int mod1 = 127657753, mod2 = 987654319;
const int p1 = 137, p2 = 277;
using pii = pair<int,int>;
pii pw[N], invpw[N];
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
class hashNode {
private:
int n;
string str;
vector<pii> t;
auto merge(pii p1, pii p2) {
//pii ans;
p1.first = (p1.first + p2.first) % mod1;
p2.second = (p1.second + p2.second) % mod2;
return p1;
}
auto mul(pii p1, pii p2) {
//pii ans;
p1.first = 1LL * p1.first * p2.first % mod1;
p1.second = 1LL * p1.second * p2.second % mod2;
return p1;
}
void build(int nd, int b, int e) {
if(b == e) {
t[nd].first = 1LL * str[b] * pw[b].first % mod1;  
t[nd].second = 1LL * str[b] * pw[b].second % mod2;  
return;
}
int mid = b + e >> 1, l = (nd << 1), r = l | 1;
build(l, b, mid);
build(r, mid + 1, e);
t[nd] = merge(t[l], t[r]);
}
void upd(int nd,int b,int e,int pos,char ch) {
if(pos < b || e < pos) return;
if(b == e && pos == b) {
t[nd].first = 1LL * ch * pw[b].first % mod1;  
t[nd].second = 1LL * ch * pw[b].second % mod2;  
return;
}
int mid = b + e >> 1, l = (nd << 1), r = l | 1;
upd(l, b, mid, pos, ch);
upd(r, mid + 1, e, pos, ch);
t[nd] = merge(t[l], t[r]);
}
pii query(int nd,int b,int e,int i,int j) {
if(j < b || e < i) return {0, 0};
if(i <= b && e <= j) return t[nd];
int mid = b + e >> 1, l = (nd << 1), r = l | 1;
auto left = query(l, b, mid, i, j);
auto right = query(r, mid + 1, e, i, j);
pii ans;
ans = merge(left, right);
return ans;
}
public:
hashNode(){}
hashNode(string s) {
str = s;
n = s.size();
t.resize(4*n + 10, {0, 0});
build(1, 0, n - 1);
}
void updateChar(int pos, char x) {
upd(1, 0, n - 1, pos, x);
}
auto getHash(int i,int j) {
return mul(query(1, 0, n - 1, i, j), invpw[i]);
}
};

void solve() {
int n, m;
cin >> n >> m;
string str;
cin >> str;
hashNode node(str);
string rev = str;
reverse(rev.begin(), rev.end());
hashNode revnode(rev);
while(m--) {
int ty; cin >> ty;
if(ty == 1) {
int k; cin >> k;
k--; // make 0-index
char x; cin >> x;
node.updateChar(k, x);
revnode.updateChar(n - k - 1, x);
}
else {
int a, b;
cin >> a >> b;
a--;
b--;
if(node.getHash(a, b) == 
    revnode.getHash(n - b - 1, n - a - 1)) {
    cout << "YES\n";
}
else {
    cout << "NO\n";
}
}
}
}   