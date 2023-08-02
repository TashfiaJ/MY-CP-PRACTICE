#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define lll __int128_t
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
const ll inf = 1LL<<60; //1.15e18
const ll md = 1000000007;
const ll N = 1e6+5;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

vector<ll>prime(N,1), primes;

void sieve()
{
    primes.push_back(2);
    for(ll i=4;i<N;i+=2)
    {
        prime[i]=0;
    }
    for(ll i=3;i<N;i+=2)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<N;j+=i)prime[j]=0;
        }
    }
    for(ll i=3;i<N;i++)
    {
        if(prime[i])primes.push_back(i);
    }
}

void solve()
{
    ll n; cin >> n;
    cout<<primes[n-1]<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    sieve();
    while(T--)
    {
        solve();
    }
    return 0;
}

