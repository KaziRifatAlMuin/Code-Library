#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7 ; //For big mod
ll powmod(ll a,ll b){ll res=1;a%=MOD;if(b<0) return 0;for(; b; b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const double PI = acos(-1.0);
const int N     = 1e5+1; //CHECK here for every problem
const int mod   = 1e9+7;

void solve()
{
    int n, m;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    int mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            mat[i][j] = ara[i] % 10;
            ara[i] /= 10;
        }
    }
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s == "row"){
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < n; i++){
                swap(mat[a-1][i],mat[b-1][i]);
            }
        }
        else if(s == "col"){
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < n; i++){
                swap(mat[i][a-1],mat[i][b-1]);
            }
        }
        else if(s == "inc"){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = (mat[i][j] + 1) % 10;
                }
            }
        }
        else if(s == "dec"){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 0) mat[i][j] = 9;
                    else mat[i][j]--;
                }
            }
        }
        else if(s == "transpose"){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i < j) swap(mat[i][j],mat[j][i]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
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
    cin >> t;
    while(t--)
    {
        cout << "Case #" << case_number++ << "\n";
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