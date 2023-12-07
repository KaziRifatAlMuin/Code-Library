/* RifatALmuiN */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
const long long int MOD = 1000000007;

string s;

char check(int i)
{
    for(i; i<s.length(); i++){
        if(s[i]!='?'){
            return s[i];
        }
    }
}

void solve()
{
    int i;
    cin >> s;
    for(i=0; i<s.length();i++){
        if(s[i]=='?'){
            if(i==0){
                s[i] = '0';
            }
            else if(i == s.length()-1){
                s[i] = '1';
            }
            else{
                char a = check(i);
                char b = s[i-1];
                if(a==b) s[i] = check(i);
                else{
                    if(check(i)=='1') s[i] = '1';
                    else s[i] = '0';
                }
            }
        }
    }
    cout << s << endl;
}

int main()
{
    FAST_IO;
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