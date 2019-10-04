#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mm(ll x, ll m)
{
    return x < m ? x : x % m + m;
}
ll phi(ll n)
{
    ll res = n;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n != 1)
        res = res / n * (n - 1);
    return res;
}
ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = mm(res * x, mod);
        x = mm(x * x, mod), n >>= 1;
    }
    return res;
}

ll dfs(ll a, ll b, ll m)
{
    if (m == 1)
        return 1;
    if (b == 0)
        return 1;
    ll temp = phi(m);
    ll x = dfs(a, b - 1, temp);
    return mod_pow(a, x, m);
}

int main()
{
    int T;
    scanf("%d", &T);
    ll a, b, m;
    while (T--)
    {
        scanf("%lld%lld%lld", &a, &b, &m);
        printf("%lld\n", dfs(a, b, m) % m);
    }
    return 0;
}