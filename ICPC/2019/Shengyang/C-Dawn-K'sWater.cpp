#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxm = 10005;
int dp[maxm];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        dp[0] = 0;
        for (int i = 1; i < maxm; ++i)
            dp[i] = INF;
        for (int i = 0; i < n; ++i)
        {
            static int w, v;
            scanf("%d%d", &v, &w);
            for (int j = w; j <= 10000; ++j)
                dp[j] = min(dp[j], dp[j - w] + v);
        }
        int ans = INF, w = 0;
        for (int i = m; i <= 10000; ++i)
            if (ans >= dp[i])
            {
                ans = dp[i], w = i;
            }
        printf("%d %d\n", ans, w);
    }
    return 0;
}