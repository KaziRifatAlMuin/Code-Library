#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q; cin >> q;
  vector<int> ans(q + 1);
  vector<pair<int, int>> Q[n + 1];
  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }
  // build a segment tree where every value is 0
  map<int, int> last_id;
  for (int i = 1; i <= n; i++) {
    upd(i, 1); // add 1 to the ith index
    if (last_id.find(a[i]) != last_id.end()) {
      upd(last_id[a[i]], -1); // add -1 to the last index having value a[i]
    }
    last_id[a[i]] = i;
    for (auto x: Q[i]) {
      int l = x.first, id = x.second;
      ans[id] = query(l, i); // sum of l to the ith index
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}