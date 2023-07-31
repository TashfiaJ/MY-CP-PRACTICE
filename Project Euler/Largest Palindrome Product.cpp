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

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

bool isPalindrome(ll n)
{
    ll reverse=0, t=n;
    while(t)
    {
        reverse=(reverse*10)+t%10;
        t/=10;
    }
    return reverse==n;
}

void solve()
{   
    ll n,ans=0; cin >> n;
    for(ll i=999;i>=100;i--)
    {
        for(ll j=999;j>=100;j--)
        {
            if((i*j)<n)
            {
                if (isPalindrome((i*j)))
                {
                    ans=max(ans,i*j);
                }
            }
        }
    }
    cout<<ans<<'\n';
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

