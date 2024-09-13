int dp[N+5][N+5];
string a, b;
int lcs(int i,int j) {
    if(i == a.size() || j == b.size()) return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    if(a[i] == b[j]) ans = 1  + lcs(i+1, j+1);
    ans = max(ans, lcs(i+1, j));
    ans = max(ans, lcs(i, j+1));
    return ans;
}
string ans = "";
set<string> st_string;
void printAll(int i,int j) {
    if(i == a.size() || j == b.size()) {
        if(ans.size()) st_string.insert(ans);
        return;
    }
    if(a[i] == b[j]) {
        ans.push_back(a[i]);
        printAll(i+1, j+1);
        ans.pop_back();
    }
    else {
        if(lcs(i+1, j) > lcs(i, j+1)) printAll(i+1, j);
        else if(lcs(i, j+1) > lcs(i+1, j)) printAll(i, j+1);
        else {
            printAll(i+1, j);
            printAll(i, j+1);
        }
    }
}