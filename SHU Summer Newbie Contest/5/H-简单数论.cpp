#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T = 1;
    ll n, mod, k;
    while (T--)
    {
        map<ll, int> cnt;
        map<ll, int> cnt2;
        scanf("%lld%lld%lld", &n, &mod, &k);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll a;
            scanf("%lld", &a);
            ll cur = (a * a % mod * a % mod - k * a % mod) % mod;
            cur = (cur + mod) % mod;
            ans += cnt[cur] - cnt2[a];
            cnt[cur]++;
            cnt2[a]++;
        }
        for (auto &[key, value] : cnt2)
            if (key * key % mod * 3 % mod == k)
                ans += 1LL * value * (value - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}