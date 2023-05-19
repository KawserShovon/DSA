
ll M;
ll mod(ll x)
{
    return (((x%M)+M)%M);
}

ll mul(ll a, ll b)
{
    return mod(mod(a)*mod(b));
}

ll modPow(int x, int y)
{
    if(y==0) return 1LL;
    if(y==1) return mod(x);

    ll res = 1;

    while(y)
    {
        if(y%2==1)
        {
            res = mul(res,x);
        }
        x = mul(x,x);
        y /= 2;
    }

    return res;
}
