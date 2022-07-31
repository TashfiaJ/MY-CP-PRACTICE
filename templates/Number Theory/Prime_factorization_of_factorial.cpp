const ll N  = 105;

ll prime[N];
vector<ll>primes;

void SieveOfEratosthenes()
{
    
    memset(prime, 1, sizeof(prime));

    for(ll i = 4; i<N; i+=2)
        prime[i]=0;

    for (ll p = 3; p*p <N ; p+=2) {
        
        if (prime[p]) {
            for (ll i = p * p; i<N; i += p)
                prime[i] = 0;
        }
    }
    for (ll p = 2; p<N; p++){
        if (prime[p])
            primes.push_back(p);}
}

void factFactorize (ll n) {
   
    for (ll i = 0; i<N && primes[i] <= n; i++ ) {
        ll x = n;
        ll freq = 0;
 
        while ( x / primes[i] ) {
            freq += x / primes[i];
            x = x / primes[i];
        }
 
        
        cout << primes[i] << " (" << freq << ")";
        if(n/primes[i+1])cout << " * ";
    }
}
