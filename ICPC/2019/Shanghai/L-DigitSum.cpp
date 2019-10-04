#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[20];
ll dp[20][60];
int base;
ll dfs(int pos, int state, bool lead, bool limit)
{
    if (pos == -1)
        return state;
    if (!limit && !lead && dp[pos][state] != -1)
        return dp[pos][state];
    int up = limit ? a[pos] : base - 1;
    ll res = 0;
    for (int i = 0; i <= up; ++i)
    {
        if (i == 0 && lead)
            res += dfs(pos - 1, 0, lead && i == 0, limit && i == up);
        else
            res += dfs(pos - 1, state + i, lead && i == 0, limit && i == up);
    }
    if (!limit && !lead)
        dp[pos][state] = res;
    return res;
}
ll solve(ll x)
{
    memset(dp, -1, sizeof(dp));
    int pos = 0;
    do
        a[pos++] = x % base;
    while (x /= base);
    return dfs(pos - 1, 0, true, true);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        static int n;
        scanf("%d%d", &n, &base);
        printf("Case #%d: %lld\n", k, solve(n));
    }
    return 0;
}