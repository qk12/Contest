#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int dp[maxn][maxn];
char s[maxn], ans[maxn];
int mod, len;

int dfs(int pos, int state)
{
    if (pos == len)
        return state == 0;
    if (dp[pos][state] != -1)
        return dp[pos][state];
    int res = 0;
    if (s[pos] != '?')
    {
        ans[pos] = s[pos];
        res = dfs(pos + 1, (state * 10 + s[pos] - '0') % mod);
    }
    else
    {
        for (int i = 0; i <= 9; ++i)
        {
            if (pos == 0 && i == 0)
                continue;
            ans[pos] = i + '0';
            res = dfs(pos + 1, (state * 10 + i) % mod);
            if (res == 1)
                return dp[pos][state] = res;
        }
    }
    return dp[pos][state] = res;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%s%d", s, &mod);
    len = strlen(s);
    if (dfs(0, 0))
        printf("%s\n", ans);
    else
        printf("*\n");
    return 0;
}