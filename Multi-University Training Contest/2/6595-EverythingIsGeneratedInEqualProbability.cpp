#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;
ll mod_pow(ll x, ll n)
{
    ll res = 1;
    if (n == 0)
        return res %= mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod, n >>= 1;
    }
    return res;
}

int main()
{
    ll n;
    while (~std::scanf("%lld", &n))
    {
        printf("%lld\n", (n * n - 1) * mod_pow(9, mod - 2) % mod);
    }
    return 0;
}