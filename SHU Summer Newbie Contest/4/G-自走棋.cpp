#include <iostream>
using namespace std;

const int maxm = 1e4 + 5;
int n, m;
int V[12][1005];
long long dp[maxm];
int cnt[12];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &cnt[i]);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &V[n][cnt[i]]);
    int v;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &v);
        for (int j = 1; j <= n; ++j)
            V[i][j] += v * j;
    }
    for (int k = 1; k <= n; ++k)              //枚举k个组
        for (int j = m; j >= 0; --j)          //枚举容量
            for (int i = 1; i <= cnt[k]; ++i) //枚举各组中物品的序号
            {
                if (j >= i)
                    dp[j] = max(dp[j], dp[j - i] + V[k][i]);
            }
    printf("%lld\n", dp[m]);
    return 0;
}