/*
    Author : RifatALmuiN
    Problem : C. Strongly Composite
*/
 
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
#define PB push_back
const int N = 1e5+7;
 
vector<bool> isP;
vector<ll> prime;
 
void genP(int n)
{
    isP.resize(n+2,0);
    isP[1]=1;
    int sq=sqrt(n);
    for(int i=2;i<=n;i++){
        if(isP[i]==1) 
            continue;
        prime.PB(i);
        for(ll j=i*1ll*i;j<=n;j+=i){
            isP[j]=1;
        }
    }
}
 
map<int, int> cnt;
 
void pFct(int n)
{
    vector<int> res;
    for(int i=0;prime[i] * prime[i]<=n;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                cnt[prime[i]]++;
            }
        }
    }
    if(n!=1) cnt[n]++;
}   

void solve()
{
    cnt.clear();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        pFct(x);
    }
    int res = 0, sum = 0;
    for (auto x : cnt) {
        res += (x.second / 2);
        sum += (x.second % 2);
    }
    res += (sum / 3);
    cout << res<< "\n";
}

int main()
{
    FAST_IO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1, case_number = 1;
    genP(N);
    cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}