bool isPowerOfTwo(unsigned long long n)
{
    if(!n) return false;
    return !(n & (n-1));
}
