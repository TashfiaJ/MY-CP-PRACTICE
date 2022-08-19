const ll MAXN=200009;
ll spf[MAXN+7];

// smallest prime factor of any number
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
 
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
 
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// prime factorization of a number
vector<ll>p;
ll l=1;
while(num!=1)
     {   
        if(spf[num]>l){
        p.push_back(spf[num]);
        l=spf[num];}
         num/=spf[num];
     }
