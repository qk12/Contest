#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int dp[maxn][maxn]; //dp[i][j]代表从i到j位置满足等间距的数目的个数
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        for (int j = i + 1; j <= n; ++j)
            dp[i][j] = 2;
    }
    sort(a + 1, a + 1 + n);
    int ans = 2;
    for (int i = 2; i <= n; ++i)
    {
        int k = i - 1;
        for (int j = i + 1; j <= n; ++j)
        {
            int t = a[i] - (a[j] - a[i]);
            while (a[k] > t && k >= 1)
                --k;
            if (a[k] == t)
            {
                dp[i][j] = max(dp[i][j], dp[k][i] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}