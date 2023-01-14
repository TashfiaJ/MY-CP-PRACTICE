#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

void solve()
{  
    ll n,ans=0;
    cin>>n;
    while(n--)
    {
        ll x;
        cin>>x;
        ll temp=x;
        temp=0;
        ll c=1;
        while(x)
        {
            ll y=x%10;
            if(y>7)y--;
            temp+=(y*c);
            x/=10;
            c*=9;
        }
        ans+=temp;
    }
    cout<<ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; 
    T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
    }
}
