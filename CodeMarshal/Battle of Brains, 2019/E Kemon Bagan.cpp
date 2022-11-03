#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n, s;
        cin >> n >> s;
        double angle=360.0/n;
        angle/=2;
        double r=(s/2.0)/sin(angle*pi/180);
        r*=r;
        double ca=pi*r;        
        double pa=n*s*sqrt(r-((s/2.0)*(s/2.0)))/2;
        double ans=ca-pa;
        cout << "Case " << i << ": " << fixed << setprecision(2) << ans << '\n';
    }
}
