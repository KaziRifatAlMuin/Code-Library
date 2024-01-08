#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

const int N = 1e3 + 10;
int graph1[N][N]; 
// space complexity too high O(N^2) 
// N = 10^6 not possible, max : 10^4 x 10^4

void solve()
{
    int n, m;
    cin >> n >> m;

    vector <int> graph2[N]; // N vectors
    // graph2[i] is list of connected vertices with vertex i;

    for(int i = 1; i <= m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << graph1[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for(int x = 1; x <= n; x++){
        cout << x << " : ";
        for(auto y : graph2[x]){
            cout << y << " ";
        }
        cout << "\n";
    }
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
    