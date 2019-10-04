#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
char s[maxn];
int dp[maxn][26]; //dp[i][j]表示到第i位，j字母出现的次数

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        scanf("%s", s + 1);
        memset(dp, 0, sizeof(dp));

        ++dp[1][s[1] - 'a'];
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < 26; ++j)
                dp[i][j] = dp[i - 1][j];
            ++dp[i][s[i] - 'a'];
        }

        int l, r;
        char ch;
        while (q--)
        {
            scanf("%d%d %c", &l, &r, &ch);
            int id = ch - 'a';
            int x = dp[n][id] * ((l - 1) / n) + dp[(l - 1) % n][id];
            int y = dp[n][id] * (r / n) + dp[r % n][id];
            printf("%d\n", y - x);
        }
    }
    return 0;
}
