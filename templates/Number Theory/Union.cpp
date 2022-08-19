            ll sz;
            ll lm=1 << sz;
            ll cpn=0;
            for(ll i=1;i<lm;i++)
            {   
                ll mul=1, cc=0;
                for(ll j=0;j<sz;j++)
                {
                    if(i & (1 << j))
                    {
                        cc++;
                        mul*=p[j];
                    }
                }
                // n(aUbUc)=n(a)+n(b)+n(c)-n(a intersection b)-n(b intersection c)-n(a intersection c)+n(a intersect b intersect c)
                // odd positive, even negative
                if(cc % 2 == 1)
                {
                    cpn += gun[mul];
                }
                else
                {
                    cpn -= gun[mul];
                }
            }
