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
const ll inf = 1e18;
const ll md = 1000000007;
const ll N = 2e5+5;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

void solve()
{
    ll a[20][20];
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<20;j++)
            cin >> a[i][j];
    }
    ll mx=0;
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<20;j++)
        {   
            if(j+3<20)
            mx=max(mx,a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
            if(i+3<20)
            mx=max(mx,a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
            if(i+3<20 && j+3<20)
            mx=max(mx,a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]);
            if(i+3<20 && j-3>=0)
            mx=max(mx,a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3]);
        }
    }
    cout<<mx;   
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
    }
}
