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
    ll n;
    cin >> n;
    n--;
    ll a = n/3, b=n/5, c=n/15;
    ll sa = (a*(6+((a-1)*3)))/2, sb = (b*(10+((b-1)*5)))/2, sc = (c*(30+((c-1)*15)))/2;
    cout<<sa+sb-sc<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}

