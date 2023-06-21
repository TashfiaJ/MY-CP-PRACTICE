// common problem -> cycle detect and finding starting point in a linked list
// problem link: https://codeforces.com/problemset/problem/1137/D

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
const ll inf = 1LL<<60; //1.15e18
const ll md = 1000000007;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll query(string s)
{
    cout<<"next";
 
    for(auto c: s) cout<<" "<<c;
    cout<<'\n';
   cout.flush();
 
    int k;
    cin>>k;
 
    for(int i = 0; i < k; i++) cin>>s;
 
    return k;
}

void solve()
{   
     while(1)
    {
        ll k = query("13");
        k = query("1");
 
        if(k == 2) break;
    }

    while(1)
    {
        ll k = query("0123456789");
 
        if(k == 1) break;
    }
    cout<<"done";
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
