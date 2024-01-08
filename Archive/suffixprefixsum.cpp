#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

void test() 
{
  #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  #endif
}
 
void solve();

int main()
{
    FAST;
    //test();
    int t = 1, case_number = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

void solve()
{
    unordered_map <ll,ll> suff,pre;
    ll sum=0, half, n;
    cin>>n;
    vector <ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        suff[v[i]]++;
    }
    if(sum & 1){
        cout<<"NO\n";
        return;
    }
    half = sum/2;
    for(int i=0;i<n;i++){
        sum-=v[i];
        suff[v[i]]--;
        pre[v[i]]++;
        if(half<sum){
            if(suff[sum-half]>0){
                cout<<"YES\n";
                return;
            }
        }
        else{
            if(pre[half-sum]>0){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}