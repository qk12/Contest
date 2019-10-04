#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int last[maxn], dp[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    while (T--)
    {
        scanf("%d", &n);
        dp[0] = -1;
        memset(last, 0, sizeof(last));
        int c;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &c);
            dp[i] = dp[i - 1] + 1;
            if (last[c] != 0)
                dp[i] = min(dp[i], dp[last[c]] + 1);
            last[c] = i;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}