#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define lll __int128_t
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define debug(x)       { cerr << #x << " = " << x << endl; }
double pi = 2*acos(0.0);
const ll inf = 1LL<<60; //1.15e18
const ll md = 1000000007;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

int bigmod(int a, int b)
{
    int ans =1;
    while(b>0)
    {
        if(b&1)
        {
            ans = (ans*1ll*a)%mod;
        }
        a= (a*1ll*a)%mod;
        b>>=1;
    }
    return ans;
}
 
inline int add(int x, int y)
{
    return (x+y>=mod ? x+y-mod : x+y);
}
 
inline int sub(int x, int y)
{
    return (x-y<0 ? x-y+mod : x-y);
}
 
inline int gun(int x, int y)
{
    return ((x*1ll*y)%mod);
}
 
inline int vag(int x, int y)
{
    return (x*1ll* bigmod(y,mod - 2))%mod;
}

void solve()
{
    
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
}

// to run in command prompt, g++ A.cpp && .\a.exe < in.txt
// g++ filename.cpp ->compile
// ./a.out -> run
