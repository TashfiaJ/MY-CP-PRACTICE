#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-7

int main ()
{
    ll t, tc=1; cin >> t;
    while(t--)
    {
        double l, n, c, ans; cin >> l >> n >> c;
        double l_prime = (1+(n*c))*l;
        double a = l/2, high = a, low=0;
        while(high-low>EPS)
        {
           double h = (low+high)/2.0;
           double r = (h/2) + ((l*l)/(8*h));
           double theta = 2*asin(a/r);
           double theta_h = r*theta;
           if(theta_h>=l_prime)
           {
               high = h;
           }
           else
           {
               low = h;
           }
        }
        cout << "Case " <<tc++ <<": "<<setprecision(6) << fixed << low << '\n'; //high or low. both are correct
    }
}
