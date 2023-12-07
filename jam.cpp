#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, red = 0, blue = 0, eat = 0, l, r;
    cin >> n;
    int lim = 2 * n;
    int jar[lim];
    l = n-1, r = n;
    for(int i = 0; i < lim; i++){
        cin >> jar[i];
        jar[i] == 1 ? red++ : blue++; 
        // 1 = red, 2 = blue
    }
    while(red != blue && eat != lim){
        eat++;
        if(red > blue){
            if(l >= 0 && jar[l] == 1){
                l--;
                red--;
            }
            else if(r < lim && jar[r] == 1){
                r++;
                red--;
            }
            else{
                if(l >= 0){
                    l--;
                    blue--;
                }
                else if(r < lim){
                    r++;
                    blue--;
                }
                else{
                    break;
                }
            }
        }
        else{
            if(l >= 0 && jar[l] == 2){
                l--;
                blue--;
            }
            else if( r < lim && jar[r] == 2){
                r++;
                blue--;
            }
            else{
                if(l >= 0){
                    l--;
                    red--;
                }
                else if(r < lim){
                    r++;
                    red--;
                }
                else{
                    break;
                }
            }
        }
    }
    cout << eat << endl;
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