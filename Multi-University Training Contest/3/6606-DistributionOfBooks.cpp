#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
ll a[maxn], pre[maxn], sum[maxn];
int dp[maxn << 2]; //dp[i]表示前i个数最多能分成的段

void build(int l, int r, int rt)
{
    dp[rt] = 0;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}
void update(int x, int val, int l, int r, int rt)
{
    if (l == r)
    {
        dp[rt] = max(dp[rt], val);
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, val, Lson);
    else
        update(x, val, Rson);
    dp[rt] = max(dp[lson], dp[rson]);
}

ll query(int x, int y, int l, int r, int rt)
{
    if (x <= l && y >= r)
        return dp[rt];
    int m = (l + r) >> 1;
    ll res = -INF;
    if (x <= m)
        res = max(res, query(x, y, Lson));
    if (y > m)
        res = max(res, query(x, y, Rson));
    return res;
}

int sz;
int n, k;

inline int getid(ll x)
{
    return lower_bound(sum, sum + sz, x) - sum + 1;
}

bool check(ll x)
{
    build(1, sz, 1);
    for (int i = 1; i <= n; ++i)
    {
        int id = getid(a[i] - x); //找到满足条件的最左边界
        int val = query(id, sz, 1, sz, 1) + 1;
        id = getid(pre[i]);
        update(id, val, 1, sz, 1);
        if (val >= k)
            return true;
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        a[0] = 0;
        ll l = 0, r = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", a + i);
            if (a[i] < 0)
                l += a[i]; //左边界
            else
                r += a[i]; //右边界
            a[i] += a[i - 1];
            sum[i] = a[i];
        }
        ++r;
        sort(sum + 1, sum + 1 + n);
        sz = unique(sum + 1, sum + n + 1) - sum - 1;
        while (l < r)
        {
            ll m = l + (r - l) / 2;
            if (check(m))
                r = m;
            else
                l = m + 1;
        }
        printf("%lld\n", l - 1);
    }
    return 0;
}
