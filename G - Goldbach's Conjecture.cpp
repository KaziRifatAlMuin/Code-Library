/*
    Author : RifatALmuiN
    Problem : G - Goldbach's Conjecture
    Source : https://vjudge.net/contest/548702
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
int const MAX = 1000007;
int mark[MAX] = {0} ; // 0 if prime, 1 if not prime
vector <int> prime;

void sieve(int n)
{
    int i, j, limit = sqrt(n*1.0) + 2;
    mark[0] = 1, mark[1] = 1;
    for(i = 4; i <= n; i += 2)
        mark[i]=1;
    prime.push_back(2);
    for(i = 3;  i <= n; i += 2){
        if(!mark[i]){ //prime, !0 = 1
            prime.push_back(i);
            if(i <= limit){
                for(j = i*i; j <= n; j += i*2){
                    mark[j] = 1; //not prime
                }
            }
        }
    }
}

void solve()
{
    sieve(MAX);
    int n,a,b,i;
    while(1){
        cin>>n;
        if(!n) break;
        for(i=1; i<n; i++){
            if(!mark[n-prime[i]]){
                a = prime[i];
                b = n - prime[i];
                break;
            }
        }
        cout<<n<<" = "<<a<<" + "<<b<<endl;
    }
}

int main()
{
    FAST_IO;
//   #ifndef ONLINE_JUDGE
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
//   #endif
    int t = 1, case_number = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

