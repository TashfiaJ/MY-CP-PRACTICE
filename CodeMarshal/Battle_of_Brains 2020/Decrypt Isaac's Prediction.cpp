#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second

void solve()
{
    ll k, x, y, z;
    cin >> k >> x >> y >> z;
    ll ini = 10;
    while(k>1)
    {
        ini*=10;
        k--;
    }
    ini*=(x*y);
    ini/=(z-y);
    ll ans=0;
    while(ini)
    {
        ans+=(ini%10);
        ini/=10;
    }
    cout << "Winning percentage of Drump is: " << ans << "%\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1;
    cin >> T;
    while(T--)
    {
        solve();
    }
}
