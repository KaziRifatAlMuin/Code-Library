#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

ll ncr[100][100];

void nCr()
{
    ncr[0][0] = 1, ncr[1][0] = 1, ncr[1][1] = 1;
    for(int i = 2; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(j > i) ncr[i][j] = 0;
            else if(j == i || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
}


void solve()
{ 
    ll r, c;
    cin >> r >> c;
    cout << ncr[r+c-2][c-1] << endl;
}

int main()
{
    FAST_IO

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //int case_number = 1;
    cin >> t;

    nCr();

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
