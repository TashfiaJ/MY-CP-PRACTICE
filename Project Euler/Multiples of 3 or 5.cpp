#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x,y;
    cin >> x >> y;
    ll a=999/x,b=999/y,lcm=(x*y)/__gcd(x,y);
    a=x*((a*(a+1))/2);
    b=y*((b*(b+1))/2);
    ll lcm1=999/lcm;
    lcm=lcm*((lcm1*(lcm1+1))/2);
    cout<<a+b-lcm;
}
