const int N = 5000;
string a, b;
int dp[N+5][N+5];
int edit_distance(int i,int j) {
    if(i == a.size()) {
        if(j == b.size()) return 0;
        else return b.size() - j;
    }
    if(j == b.size()) {
        return a.size() - i;
    }
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = INT_MAX;
    if(a[i] == b[j]) ans = min(ans, edit_distance(i+1,j+1));
    ans = min(ans, 1 + edit_distance(i, j+1));
    ans = min(ans, 1 + edit_distance(i+1, j));
    ans = min(ans, 1 + edit_distance(i+1, j+1));
    return ans;
}
void solve() {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << edit_distance(0,0) << "\n";
} 
void solve1() {
    string a, b; 
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        }
    }
    cout << dp[n][m] << "\n";
} 