#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
typedef long long int ll;
typedef vector <int> vi;
typedef vector <long long int> vll;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;
typedef map <int,int> mii;
typedef map <long long int, long long int> mll;
long long int const MOD = 1000000007;

double d;


int f(double a, double b, double c)
{
    if((a+b)+c==d || (a+b)-c==d || (a+b)*c==d || (a+b)/c==d)
        return 0;
    else if(abs(a-b)+c==d || abs(a-b)-c==d || abs(a-b)*c==d || abs(a-b)/c==d)
        return 0;
    else if((a*b)+c==d || (a*b)-c==d || (a*b)*c==d || (a*b)/c==d)
        return 0;
    else if((a/b)+c==d || (a/b)-c==d || (a/b)*c==d || (a/b)/c==d)
        return 0;

    else if(a+(b+c)==d || a+(b-c)==d || a+(b*c)==d || a+(b/c)==d)
        return 0;
    else if(a-(b+c)==d || a-(b-c)==d || a-(b*c)==d || a-(b/c)==d)
        return 0;
    else if(a*(b+c)==d || a*(b-c)==d || a*(b*c)==d || a*(b/c)==d)
        return 0;
    else if(a/(b+c)==d || a/(b-c)==d || a/(b*c)==d || a/(b/c)==d)
        return 0;
    return 1;
}

void solve()
{
    double a = 1, b = 1, c = 1;
    cin >> d;
    for(a = 1; a <= 100; a++){
        for(b = 1; b <= 100; b++){
            for(c = 1; c <= 100; c++){
                if(a == d || b == d || c == d) 
                    continue;
                else if(a == b || a == c || b == c) 
                    continue;
                else if(a + b == d || a + c == d || b + c == d) 
                    continue;
                else if(a - b == d || a - c == d || b - c == d || b - a == d || c - a == d || c - b == d ) 
                    continue;
                else if(a * b == d || a * c == d || b * c == d)
                    continue;
                else if(a / b == d || a / c == d || b / c == d || b / a == d || c / a == d || c / b == d ) 
                    continue;

                else if((a+b)+c==d || (a+b)-c==d || (a+b)*c==d || (a+b)/c==d)
                    continue;
                else if(abs(a-b)+c==d || abs(a-b)-c==d || abs(a-b)*c==d || abs(a-b)/c==d)
                    continue;
                else if((a*b)+c==d || (a*b)-c==d || (a*b)*c==d || (a*b)/c==d)
                    continue;
                else if((a/b)+c==d || (a/b)-c==d || (a/b)*c==d || (a/b)/c==d)
                    continue;

                else if(a+(b+c)==d || a+(b-c)==d || a+(b*c)==d || a+(b/c)==d)
                    continue;
                else if(a-(b+c)==d || a-(b-c)==d || a-(b*c)==d || a-(b/c)==d)
                    continue;
                else if(a*(b+c)==d || a*(b-c)==d || a*(b*c)==d || a*(b/c)==d)
                    continue;
                else if(a/(b+c)==d || a/(b-c)==d || a/(b*c)==d || a/(b/c)==d)
                    continue;

                else{
                    if(f(a,c,b) && f(b,a,c) && f(b,c,a) && f(c,a,b) && f(c,b,a)){
                        int x = a, y = b, z = c;
                        cout << x << " " << y << " " << z << endl;
                        return;
                    }
                    else{
                        continue;
                    }
                }
            }
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
    int t = 1, case_number = 1;
    cin >> t;
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
