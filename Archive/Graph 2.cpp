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

    vector <pair<int, int>> graph2[N]; // N vectors of pairs
    // graph2[i] is list of connected vertices with vertex i and weight wti;

    for(int i = 1; i <= m; i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;

        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});
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
            cout << "(" << y.first << "," << y.second << ") ";
        }
        cout << "\n";
    }

    // i, j connected ?, i, j -> wt ?
    int i = 2, j = 3;
    if(graph1[i][j] >= 1){
        cout << "[" << i << "," << j << "] Connected and weight : ";
        cout << graph1[i][j] << endl;
    }

    // for(int child : graph2[i]){ // O(N)
    //     if(child == j){
    //         // connected
    //     }
    // }

    for(auto child : graph2[i]){ // O(N)
        if(child.first == j){
            cout << "[" << i << "," << j << "] Connected and weight : ";
            cout << child.second << endl; //for wt
        }
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
    