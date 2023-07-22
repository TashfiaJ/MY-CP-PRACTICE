// it will return true if ncr is odd

bool nCr(ll n, ll r)
{
    return !(r&(n-r));
}

// only 0c1=0 and then it will be even
