#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
int a[maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    ll sum = 0;
    for (int i = 1; i <= m; ++i)
        sum += a[i];
    ll ans = (ll)(a[m]) * m - sum;
    for (int i = m + 1; i <= n; ++i)
    {
        sum = sum - a[i - m] + a[i];
        ans = min(ans, (ll)(a[i]) * m - sum);
    }
    printf("%lld\n", ans);
    return 0;
}
