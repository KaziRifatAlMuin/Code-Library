#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

int n, m;
vector<vector<char>>grid;
vector<vector<bool>>visited;

// U, R, D, L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; // relative change in coordinates

bool isSafe(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == true || grid[x][y] == '#'){
        return false;
    }
    return true;
}

void dfs(int curr_x, int curr_y)
{
    visited[curr_x][curr_y] = true;
    for(int i = 0; i < 4; i++){
        int new_x = curr_x + dx[i];
        int new_y = curr_y + dy[i];
        if(isSafe(new_x, new_y) == true){
            dfs(new_x, new_y);
        }
    }
}

void solve()
{
    int ans = 0;
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' and visited[i][j] == false){
                ++ans;
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    FAST_IO

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

/*


Coded by RifatALmuiN

Input
_______________________________

_______________________________


Output
_______________________________

_______________________________


*/
    