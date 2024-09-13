struct st {
int a, b, cost;
} e[N];
const int INF = 2e9;
int32_t main() {
int n, m;
cin >> n >> m;
for(int i = 0; i < m; i++) 
cin >> e[i].a >> e[i].b >> e[i].cost;
int s;
cin >> s;//is there any negative cycle 
//which is reachable from s?
vector<int> d (n, INF);//for finding any 
//cycle(not necessarily from s) set d[i] = 0 for all i
d[s] = 0;
vector<int> p (n, -1);
int x;
for (int i=0; i<n; ++i) {
x = -1;
for (int j=0; j<m; ++j) {
  if (d[e[j].a] < INF) {
    if (d[e[j].b] > d[e[j].a] + e[j].cost) {
      d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
      //for overflow
      p[e[j].b] = e[j].a;
      x = e[j].b;
    }
  }
}
}
if (x == -1) cout << "No negative cycle from "<<s;
else {
int y = x; //x can be on any cycle or reachable from some cycle
for (int i=0; i<n; ++i) y = p[y];
vector<int> path;
for (int cur=y; ; cur=p[cur]) {
  path.push_back (cur);
  if (cur == y && path.size() > 1) break;
}
reverse (path.begin(), path.end());
cout << "Negative cycle: ";
for (int i=0; i<path.size(); ++i) cout << path[i] << ' ';
}
return 0;
}
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}