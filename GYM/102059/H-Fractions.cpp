#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll upper(ll a, ll b)
{
    return a / b + ((a % b) ? 1LL : 0LL);
}

int main()
{
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    ll cnt = 0;
    for (ll i = 1; i <= 998; ++i)
        for (ll j = 1; j <= 998; ++j)
        {
            if (i + j > 999)
                continue;
            if (gcd(i, j) == 1LL)
            {
                ll mink = max(upper(a, i), upper(c, j));
                ll maxk = min(b / i, d / j);
                if (maxk >= mink)
                    cnt += (maxk - mink) + 1LL;
            }
        }
    printf("%lld\n", cnt);
    return 0;
}