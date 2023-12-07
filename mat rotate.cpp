#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int m, n, r, shift;
    cin >> m >> n >> r;
    int mat[m][n], ans[m][n];
    int a[m*n], b[m*n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    int tot = m * n;
    int i = 0, j = 0, row = m, col = n, c = 1, d = 0;
    int lim = 2 * (row + col) - 4;
    a[0] = mat[0][0];
    for(int k = 1; k < tot; k++, c++){
        if(c == lim){
            d++;
            i = d;
            j = d;
            c = 1;
            row--;
            col--;
            lim = 2 * (row + col) - 4;
        }
        else if(i == d && j == d){
            j++;
        }
        else if(i == d && j < col - 1){
            j++;
        }
        else if(i == d && j == col - 1){
            i++;
        }
        else if(j == col - 1 && i < row - 1){
            i++;
        }
        else if(j == col - 1 && i == row - 1){
            --j;
        }
        else if(j < col - 1 && i == row - 1  && j != d){
            --j;
        }
        else if(j == d && i == row - 1){
            --i;
        }
        else if(j == d && i < row - 1){
            --i;
        }
        a[k] = mat[i][j];
        // cout << k << " " << a[k] << endl;
    }
    for(int i = 0; i < m*n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    shift = r % tot;
    //cout << shift << endl;
    for(int i = 0; i < tot; i++){
        b[i] = a[shift % tot];
        shift++;
    }
    for(int i = 0; i < m*n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    i = 0, j = 0, row = m, col = n, c = 1, d = 0;
    lim = 2 * (row + col) - 4;
    ans[0][0] = b[0];
    for(int k = 1; k < tot; k++, c++){
        if(c == lim){
            d++;
            i = d;
            j = d;
            c = 1;
            row--;
            col--;
            lim = 2 * (row + col) - 4;
        }
        else if(i == d && j == d){
            j++;
        }
        else if(i == d && j < col - 1){
            j++;
        }
        else if(i == d && j == col - 1){
            i++;
        }
        else if(j == col - 1 && i < row - 1){
            i++;
        }
        else if(j == col - 1 && i == row - 1){
            --j;
        }
        else if(j < col - 1 && i == row - 1  && j != d){
            --j;
        }
        else if(j == d && i == row - 1){
            --i;
        }
        else if(j == d && i < row - 1){
            --i;
        }
        ans[i][j] = b[k];
        // cout << k << " " << a[k] << endl;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1, case_number = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ":\n";
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