#include <bits/stdc++.h>
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

void factor(ll n, map<int,int> &mp) {
    if(n < 0) n *= -1;
    for(int i=0;(1LL * i * i) <= n; i++) {
        if(n % primes[i] == 0) {
            while(n % primes[i] == 0) {
                mp[primes[i]]++;
                n /= primes[i];
            }
        }
    }
    if(n > 1) mp[n] = 1; 
}