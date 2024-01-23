const int N = 1005, inf = 1e9;
string s[N];
int d[N][N];
pair<int, int> par[N][N];
int di[] = {0, -1, 0, +1, -1, -1, +1, +1};
int dj[] = {+1, 0, -1, 0, +1, -1, -1, +1};
int n, m;

bool is_valid(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  pair<int, int> start, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'A') {
        start = make_pair(i, j);
      }
      if (s[i][j] == 'B') {
        end = make_pair(i, j);
      }
    }
  }
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = inf;
    }
  }
  q.push(start);
  d[start.first][start.second] = 0;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int nxt_i = i + di[k];
      int nxt_j = j + dj[k];
      if (is_valid(nxt_i, nxt_j) and s[nxt_i][nxt_j] != '#' and d[i][j] + 1 < d[nxt_i][nxt_j]) {
        d[nxt_i][nxt_j] = d[i][j] + 1;
        par[nxt_i][nxt_j] = make_pair(i, j);
        q.push(make_pair(nxt_i, nxt_j));
      }
    }
  }
  int ans = d[end.first][end.second];
  if (ans == inf) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    cout << ans << '\n';
    vector<pair<int, int>> path;
    auto cur = end;
    while (cur != start) {
      path.push_back(cur);
      cur = par[cur.first][cur.second];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for (int k = 0; k + 1 < path.size(); k++) {
      int di = path[k].first - path[k + 1].first;
      int dj = path[k].second - path[k + 1].second;
      if (di == +1) {
        cout << 'U';
      }
      else if (di == -1) {
        cout << 'D';
      }
      else if (dj == +1) {
        cout << 'L';
      }
      else {
        cout << 'R';
      }
    }
    cout << '\n';
  }
  return 0;
}