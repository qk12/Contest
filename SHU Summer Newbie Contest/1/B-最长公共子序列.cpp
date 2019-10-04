#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int nxt[maxn][26];
int now[26];
void init(char s[], int len)
{
    memset(now, -1, sizeof(now));
    for (int i = len; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            nxt[i][j] = now[j];
        now[s[i] - 'a'] = i;
    }
}
char s[maxn], t[1005];
int dp[1005];
int n, m;

int main()
{
    scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
    init(s, n);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (dp[j - 1] == -1)
                continue;
            int cur = nxt[dp[j - 1]][t[i] - 'a'];
            if (cur == -1)
                continue;
            if (dp[j] == -1)
                dp[j] = cur;
            else
                dp[j] = min(dp[j], cur);
            ans = max(ans, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}