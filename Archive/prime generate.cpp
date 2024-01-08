/*
    Author : RifatALmuiN
    Problem : PRIME1 - Prime Generator
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;



void solve()
{
    vector<int> primes;
    primes.push_back(2);

    for (int i = 3; i <= 32000; i+=2) {
        bool isprime = true;
        int cap = sqrt(i) + 1;

        vector<int>::iterator p;
        for (p = primes.begin(); p != primes.end(); p++) {
            if (*p >= cap) break;
            if (i % *p == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) primes.push_back(i);
    }
    int M, N;
    cin >> M >> N;
    if (M < 2) M = 2;
    int cap = sqrt(N) + 1;

    set<int> notprime;
    notprime.clear();

    vector<int>::iterator p;
    for (p = primes.begin(); p != primes.end(); p++) {

        if (*p >= cap) break;
        int start;

        if (*p >= M) start = (*p)*2;
        else start = M + ((*p - M % *p) % *p);

        for (int j = start; j <= N; j += *p) {
            notprime.insert(j);
        }
    }

    for (int i = M; i <= N; i++) {
        if (notprime.count(i) == 0) {
            cout << i << endl;
        }
    }
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
        cout<<endl;
    }
    return 0;
}

