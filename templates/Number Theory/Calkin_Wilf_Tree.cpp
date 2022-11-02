// Given (a/b), find the height 
// it can be solved using euclidian algo

void cwt()
{
    ll a, b;
    cin >> a >> b;
    ll height=0;
    while(a&&b)
    {
        if(a>=b)
        {   
           height+=(a/b);
           a%=b;
        }
        else
        {    
            height+=(b/a);
            b%=a;
        }
    }
    cout << height;
}
//https://codeforces.com/contest/343/problem/A
