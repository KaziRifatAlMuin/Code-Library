int midx = x2 + x1;
int midy = y2 + y1;
ans.push_back({midx, midy});
sort(ans.begin(), ans.end());
ll res = 0, cur = 0;
for(int i = 1; i < ans.size(); i++) {
auto [x1, y1] = ans[i - 1];
auto [x2, y2] = ans[i];
if(x1 == x2 && y1 == y2) {
cur++;
}
else {
res += (cur * (cur + 1)) / 2;
cur = 0;
}
}
res += (cur * (cur + 1)) / 2;
cout << res << "\n";
