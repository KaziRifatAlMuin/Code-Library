/* FIND YOUR PARTNER */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

#define times 10000
int MOD, Shift, A;
int sum = 0;
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

int random (int a, int  b, int mod)
{
    static int seed = sum;
    seed = (a*seed+b)%mod;
    return seed;
}

void randomise(vector<int>* l,int Times)
{
    while (Times--) {
        int k=1;
        while (__gcd(k,(int)l->size())==1) {
            k= random(A+rand(),Shift,l->size());
        }
        int a= random(k,Shift,l->size());
        int b= random(k,Shift,l->size());
        swap((*l)[a],(*l)[b]);
    }
}

void gen (vector<int>* l,vector<int> total,vector <int> weight)
{
    for (int i=0;i<total.size();i++) {
        for (int j=0;j<weight[i];j++) {
            l->push_back(total[i]);
        }
    }
    randomise(l,times);
}

vector <int> roll;
vector <double> per;

void choose (vector<int> *l,int Times,vector<int> total)
{
    map <int, int> a, c;
    int maxi = 0;
    while (Times--) {
        int b = random(A,Shift,MOD);
        a[(*l)[b]]++;
    }
    for(auto x : a){
        c[x.second] = x.first;
        maxi = max(maxi, x.second);
    }
    for(auto x : c){
        roll.push_back(x.second);
        per.push_back(x.first*100.0/maxi);
    }
}

int main()
{
    sieve(MAX);
    vector<int> total= {19,21,31,39,57,60,79,80,81,82,84,87,89,93,95,108,109};
    vector<int> weight(total.size());
    cout << "Enter your preference between 100 to 2300 serially For the given Roll:\n\n";
    for(int i = 0; i < total.size(); i++){
        printf("Roll %3d : ",total[i]);
        cin>>weight[i];
    }
    int i = 0;
    for (auto i: weight) sum+=i;
    int upper = sum - 10, lower = sum - 1000;
    cout << "\nChoose 3 Prime numbers from below : \n\n";
    while(prime[i]<upper){
        if(prime[i]>lower) cout<<prime[i]<<" ";
        i++;
    }
    cout << "\n\nWrite Here : ";
    int ara[3];
    cin>>ara[0]>>ara[1]>>ara[2];
    sort(ara, ara+3);
    MOD = ara[2], Shift = ara[1], A = ara[0];

    vector<int> full;

    gen(&full,total,weight);
    choose(&full,times,total);

    cout << "\nYour Matching Results Are : \n" << endl;

    for(int i=total.size()-1; i>=0; i--){
        if(roll[i]<1 || roll[i]>120 || per[i]<0.01) continue;
        printf("%3d Matched %5.2lf%%\n", roll[i], per[i]);
    }
    return 0;
}

