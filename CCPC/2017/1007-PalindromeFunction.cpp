#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
int a[40], temp[40];
ll dp[40][40][40][40];

ll dfs(int pos, int start, bool ok, bool limit, int k)
{
    if (pos == -1)
        return ok ? k : 1;
    if (!limit && dp[pos][ok][start][k] != -1)
        return dp[pos][ok][start][k];
    int up = limit ? a[pos] : k - 1;
    ll res = 0;
    for (int i = 0; i <= up; ++i)
    {
        temp[pos] = i;
        if (start == pos && i == 0)
            res += dfs(pos - 1, start - 1, ok, limit && i == up, k);
        else if (ok && pos < (start + 1) / 2)
            res += dfs(pos - 1, start, temp[start - pos] == i, limit && i == up, k);
        else
            res += dfs(pos - 1, start, ok, limit && i == up, k);
    }
    if (!limit)
        dp[pos][ok][start][k] = res;
    return res;
}
ll solve(int n, int k)
{
    int pos = 0;
    do
        a[pos++] = n % k;
    while (n /= k);
    return dfs(pos - 1, pos - 1, true, true, k);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int T;
    scanf("%d", &T);
    int L, R, l, r;
    for (int k = 1; k <= T; ++k)
    {
        scanf("%d%d%d%d", &L, &R, &l, &r);
        printf("Case #%d: ", k);
        ll ans = 0;
        for (int i = l; i <= r; ++i)
        {
            ans += solve(R, i) - solve(L - 1, i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}