#include<bits/stdc++.h>
using namespace std;
#define ll long long

double pi = 2*acos(0.0);

int main()
{
    ll t, tc=1;
    cin >> t;
     while(t--)
     {
         double r;
         ll n; cin >> r >> n;
         cout<<"Case "<<tc++<<": ";
         double ans = (r*(sin(pi/n)))/(1+(sin(pi/n)));
         cout<< fixed << setprecision(6) << ans << '\n';
     }
}
