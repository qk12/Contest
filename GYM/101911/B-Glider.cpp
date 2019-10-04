#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
ll l[maxn], r[maxn], dis[maxn], sum[maxn];

int main()
{
    int n;
    ll h;
    scanf("%d%lld", &n, &h);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld", &l[i], &r[i]);
        if (i >= 2)
            dis[i - 1] = dis[i - 2] + l[i] - r[i - 1];
        sum[i] = sum[i - 1] + r[i] - l[i];
    }
    dis[n] = 1e18;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int j = lower_bound(dis + i, dis + n + 1, h + dis[i - 1]) - dis;
        ll temp = sum[j] - sum[i - 1];
        ans = max(ans, h + temp);
    }
    printf("%lld\n", ans);
    return 0;
}