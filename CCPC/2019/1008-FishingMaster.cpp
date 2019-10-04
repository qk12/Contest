#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
ll t[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    int n, k;
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &t[i]);
        ll ans = k, cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            cnt += t[i] / k;
            ans += t[i];
            t[i] = k - t[i] % k;
        }
        sort(t + 1, t + n + 1);
        for (int i = 1; i <= n - cnt - 1; ++i)
            ans += t[i];
        printf("%lld\n", ans);
    }
    return 0;
}