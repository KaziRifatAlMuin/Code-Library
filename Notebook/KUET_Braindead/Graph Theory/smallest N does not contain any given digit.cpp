//Given a positive integer and some 
//digits, find the smallest 
//positive multiple of N whose decimal 
//notation does not contain any of the given digits.

const int N = 1e5 + 9;
const int inf = (1 << 30);
void solve() {
int n, m, cs = 1;
while(cin >> n >> m) {
vector<bool> bad_digits(10, false);
while(m--) {
int k; cin >> k;
bad_digits[k] = true;
}
vector<bool> vis(n+1, false);
vector<int> par(n+1, -1), digits(n+1, -1);
queue<int> Q;
for(int i=1;i<=9;i++) {
int x = i % n;
if(!bad_digits[i] && !vis[x]) {
    Q.push(x);
    vis[x] = 1;
    digits[x] = i;
}
}
while(!Q.empty()) {
int x = Q.front();
Q.pop();
for(int i=0;i<=9;i++) {
    int nxt_number = (10*x + i) % n;
    if(!bad_digits[i] && !vis[nxt_number]) {
        Q.push(nxt_number);
        par[nxt_number] = x;
        digits[nxt_number] = i;
        vis[nxt_number] = 1;
    }
}
}
cout << "Case " << cs++ << ": ";
if(vis[0]) {
vector<int> path;
int cur = 0;
while(cur != -1) {
    path.push_back(digits[cur]);
    cur = par[cur];
}
reverse(path.begin(), path.end());
for(auto x : path) cout << x;
cout << "\n";
}
else cout << -1 << "\n";
}
}  