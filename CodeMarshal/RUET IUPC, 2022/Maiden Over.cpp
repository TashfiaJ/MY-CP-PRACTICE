#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second

void solve(ll i)
{   
    ll o;
    cin >> o;
    ll ans=o;
    while(o--)
    {   
        bool flag=true;
        for(ll i=0;i<6;i++)
        {
            ll b; cin >> b;
            if(b!=0)
            {
                flag=false;
            }
        }
        if(!flag)ans--;
    }
    cout << "Case "<<i<<": "<<ans<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll T; T=1; 
    cin >> T;
    for(ll i=1;i<=T;i++)
    {
        solve(i);
    }
}
