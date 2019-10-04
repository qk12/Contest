#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll f(ll n, ll m)
{
    ll cnt = 0, i = n;
    while (cnt < m)
    {
        ++i;
        if (gcd(i, n) == 1) //++i一定在前面
            ++cnt;
    }
    return i;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll k, m;
        scanf("%lld%lld", &k, &m);
        ll ans = -1;
        for (int i = 1; i <= 1000; ++i)
        {
            ll n = i ^ k;
            if (n == 0)
                continue;
            if ((f(n, m) - n) == i)
            {
                if (ans == -1)
                    ans = n;
                else if (ans > n)
                    ans = n;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}