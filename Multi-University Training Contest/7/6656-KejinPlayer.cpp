#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 5e5 + 5;
ll sum[maxn], dp[maxn];
// dp[i] 表示从i级升到i+1级的花费
// 1/p次中有1次升级,那么剩下 1/p - 1次会掉级，所以
// dp[i] = (a[i] + (1/p - 1) * (sum[i - 1] - sum[x[i] - 1] + a[i]) )
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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        sum[0] = dp[0] = 0;
        ll r, s, x, a;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld%lld%lld", &r, &s, &x, &a);
            ll p = r * mod_pow(s, mod - 2) % mod;
            dp[i] = (a + (1 - p + mod) % mod * (a + sum[i - 1] - sum[x - 1] + mod) % mod * mod_pow(p, mod - 2) % mod) % mod;
            sum[i] = (sum[i - 1] + dp[i] + mod) % mod; //前缀和
        }
        while (q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            ll ans = (sum[r - 1] - sum[l - 1] + mod) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}