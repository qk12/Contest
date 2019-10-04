#include <bits/stdc++.h>
using namespace std;

const int N = 20;
bool vis[21];
int dp[21][1 << N];
int a[21], b[21], need[21];
int n;

bool ok(int x, int state)
{
    if (vis[x])
        return false;
    return (state & need[x]) == need[x];
}

int dfs(int t, int now)
{
    if (dp[t][now] != -1)
        return dp[t][now];
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ok(i, now))
        {
            vis[i] = true;
            res = max(dfs(t + 1, now | (1 << i)) + (t + 1) * a[i] + b[i], res);
            vis[i] = false;
        }
    }
    return dp[t][now] = res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int s;
        scanf("%d%d%d", &a[i], &b[i], &s);
        for (int j = 0; j < s; ++j)
        {
            int x;
            scanf("%d", &x);
            need[i] |= (1 << (x - 1));
        }
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}
