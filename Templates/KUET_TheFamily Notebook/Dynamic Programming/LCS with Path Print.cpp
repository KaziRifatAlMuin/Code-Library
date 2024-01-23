string a, b;
int dp[N+5][N+5];
int lcs(int i,int j) {
    if(i == a.size() || j == b.size()) return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    if(a[i] == b[j]) ans = 1 + lcs(i+1, j+1);
    ans = max(ans, lcs(i+1, j));
    ans = max(ans, lcs(i, j+1));
    return ans;
}
void path_print(int i,int j) {
    if(i == a.size() || j == b.size()) return ;
    if(a[i] == b[j]) {
        cout << a[i];
        path_print(i+1, j+1);
        return;
    }
    int x = lcs(i+1, j);
    int y = lcs(i, j+1);
    if(x >= y) {
        path_print(i+1, j);
    }
    else {
        path_print(i, j+1);
    }
}
void solve() {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    path_print(0, 0);
} 
// itterative version 
void solve1() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    string ans = "";
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            ans = ans + a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}