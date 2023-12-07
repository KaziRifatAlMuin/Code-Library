/* Find Your Life Partner */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

#define MOD 17
#define Shift 7
#define A 5

#define times 10000

vector <int> full;
int sum=0;
map <int, int> cse;

int random (int a,int  b,int mod)
{
    static int seed = sum;
    seed=(a*seed+b)%mod;
    return seed;
}

void randomise()
{
    int t = times;
    while (t--) {
        int k=1;
        while (__gcd(k,(int) full.size())==1) {
            k= random(A+rand(),Shift,MOD);
        }
        int a= random(k,Shift,full.size());
        int b= random(k,Shift,full.size());
        swap(full[a],full[b]);
    }
}
void gen (vector<int> total,vector <int > weight)
{
    for (int i=0;i<total.size();i++) {
        for (int j=0;j<weight[i];j++) {
            full.push_back(total[i]);
        }
    }
    randomise();
}

void choose (vector<int> total)
{
    int t = times;
    while (t--) {
        int b= random(A,Shift,MOD);
        cse[full[b]]++;
    }
    for (auto x : cse) {
        cout<<x.first<<" "<<x.second<<endl;
    }
}



void solve()
{
    vector<int> total = {19,21,31,39,57,60,79,80,81,82,84,87,89,93,95,108,109};
    vector<int> weight(total.size());
    for(int i = 0; i < total.size(); i++){
        cout << total[i] << " : ";
        cin >> weight[i];
    }
    for (auto i: weight) sum+=i;
    cout<<sum<<endl;
    gen(total,weight);
    choose(total);
}

int main()
{
   // FAST_IO;
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

