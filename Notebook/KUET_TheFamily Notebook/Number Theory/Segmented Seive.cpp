#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result) ? cout << "YES\n" : cout << "NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;

int const N = 1e6 + 7;
bool isPrime[N + 1];
vector<ll> primes;

void sieve()
{
    for (int i = 2; i <= N; i++)
        isPrime[i] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

void SegmentedSeive(ll L, ll R)
{
    int dummy[R - L + 1];
    for (int i = 0; i <= (R - L); i++)
    {
        dummy[i] = 1;
    }
    for (auto pr : primes)
    {
        ll firstMultiple = (L / pr) * pr;
        if (firstMultiple < L)
            firstMultiple += pr;

        for (ll j = max(firstMultiple, pr * pr); j <= R; j += pr)
        {
            dummy[j - L] = 0;
        }
    }
    // Print all primes in L to R
    for (ll i = L; i <= R; i++)
    {
        if (dummy[i - L])
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}