const int N = 105;
const ll mod  = 998244353;
ll fac[N],invfact[N];
ll power(ll x, ll y) 
{ 
    ll res = 1; 
    x = x % mod; 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % mod; 
        y = y >> 1; 
        x = (x * x) % mod; 
    } 
 
    return res; 
} 
 
ll modInverse(ll n) 
{ 
    return power(n, mod - 2); 
} 
  
void comp()
{
    fac[0] = 1, invfact[0] = 1; 
    
    for (ll i = 1; i < N; i++){ 
        fac[i] = (fac[i - 1] * i) % mod;
        invfact[i] = modInverse(fac[i]);
    } 
}
 
ll NCR(ll n, ll r, ll p=mod) 
{
    if(r < 0 || n < 0)
        assert(false);
 
    if( n < r ) return 0;
 
    if (r == 0 || r == n) 
        return 1; 
    
    return ( fac[n] * invfact[r]  % mod) * invfact[n - r] % mod;  
}
