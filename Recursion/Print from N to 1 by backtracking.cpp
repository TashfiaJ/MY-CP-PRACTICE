// print from N to 1 by backtracking
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second

void rec(int i, int n)
{
    if(i>n)return; 
    rec(i+1, n);
    cout << i << '\n';
}

void solve()
{
    ll n;
    cin >> n;
    rec(1,n);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll T; 
    T=1;
    //cin >> T;
    while(T--)
    {   
        solve();
    }
}
