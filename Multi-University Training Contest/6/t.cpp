#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define mes(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;
const int maxn = 2e3 + 10;
struct Node
{
    ll Max, lsum, rsum, sum;
} node[maxn << 2];

struct A
{
    int x, y;
    ll w;
    bool operator<(A const &b) const
    {
        return x > b.x;
    }
} a[maxn];
vector<int> y;

void build(int l, int r, int rt)
{
    node[rt].Max = node[rt].lsum = node[rt].rsum = node[rt].sum = 0;
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
}

void pushup(int rt)
{
    node[rt].Max = max(node[rt << 1].Max, node[rt << 1 | 1].Max);
    node[rt].Max = max(node[rt].Max, node[rt << 1].rsum + node[rt << 1 | 1].lsum);
    node[rt].lsum = max(node[rt << 1].lsum, node[rt << 1].sum + node[rt << 1 | 1].lsum);
    node[rt].rsum = max(node[rt << 1 | 1].rsum, node[rt << 1 | 1].sum + node[rt << 1].rsum);
    node[rt].sum = node[rt << 1].sum + node[rt << 1 | 1].sum;
}

void update(int pos, ll c, int l, int r, int rt)
{
    if (l == r)
    {
        node[rt].sum += c;
        if (node[rt].sum > 0)
        {
            node[rt].lsum = node[rt].Max = node[rt].rsum = node[rt].sum;
        }
        else
        {
            node[rt].lsum = node[rt].Max = node[rt].rsum = 0;
        }
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        update(pos, c, l, mid, rt << 1);
    else
        update(pos, c, mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        y.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].w);
            y.push_back(a[i].y);
        }
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        sort(a + 1, a + 1 + n);
        ll ans = 0;
        a[0].x = inf;
        a[0].y = inf;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].x != a[i - 1].x)
            { //相等的就跳过
                build(1, n, 1);
                for (int j = i; j <= n; j++)
                { //暴力枚举所有的横坐标x的左右区间
                    int id = lower_bound(y.begin(), y.end(), a[j].y) - y.begin() + 1;
                    update(id, a[j].w, 1, n, 1);
                    if (a[j].x == a[j + 1].x && j != n)
                        continue; //相等的就跳过
                    ans = max(ans, node[1].Max);
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}