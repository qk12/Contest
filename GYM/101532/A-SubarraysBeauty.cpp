#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn];
ll base[30];
int vis[maxn][30];

int main()
{
    base[1] = 1;
    for (int i = 2; i <= 24; ++i)
        base[i] = base[i - 1] * 2;

    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
            int pos = 0;
            while (a[i])
            {
                vis[i][++pos] = a[i] % 2;
                a[i] /= 2;
            }
        }
        ll ans = 0;
        for (int pos = 1; pos <= 22; ++pos)
        {
            ll len = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (vis[i][pos])
                    ++len;
                else
                {
                    ans += (len * (len + 1)) / 2 * base[pos];
                    len = 0;
                }
            }
            ans += (len * (len + 1)) / 2 * base[pos];
        }
        printf("%lld\n", ans);
    }
    return 0;
}