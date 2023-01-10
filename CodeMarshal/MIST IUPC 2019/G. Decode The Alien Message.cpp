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
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    bool found=false;
    for(ll i=0;i<n;i++)
    {
        if(a[i]%2 && found)cout<<0;
        else if(a[i]%2==0)
        {
            found=true;
            cout<<1;
        }

    }
    cout<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    cin >> T;
    for(int i=1;i<=T;i++)
    {   
        cout<<"Case "<<i<<": ";
        solve();
    }
}
