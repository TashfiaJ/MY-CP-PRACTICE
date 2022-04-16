#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll t, tc=1;
    cin >> t;
    while(t--){
        
        double ab, ac, bc, ratio;
        cin >> ab >> ac >> bc >> ratio;
        
        double new_ = ratio / (1+ratio);
        
        new_ = ab * sqrt(ratio);
    
        cout << "Case "<<tc++<<": "<<fixed << setprecision(6) << new_ << '\n';
         
   
}}
