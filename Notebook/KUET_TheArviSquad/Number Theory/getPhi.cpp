ll getPhi(ll n) {
    ll ans = 1LL*n;
    for(ll i=0;(1LL*primes[i]*primes[i])<=n;i++) {
        if(n%primes[i]==0) {
            ans -= (ans/primes[i]);
            while(n%primes[i]==0) n /= primes[i];
        }
    }
    if(n>1) ans -= (ans/n);
    return ans;
}
int phi[N + 10];
void sievePhi(){
    for(int i=1;i<=N;i++)
        phi[i] = i;
    for(int i=2;i<=N;i++){
        if(phi[i] == i){
            for(int j=i; j<= N; j += i){
                phi[j] -= (phi[j]/i);
            }
        }
    }
}