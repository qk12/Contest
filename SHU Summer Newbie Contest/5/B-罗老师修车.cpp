#include <bits/stdc++.h>
using namespace std;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;

struct tree
{
    int min, max, min2;
} st[maxn << 2];

tree get(const tree &a, const tree &b)
{
    tree res;
    res.min = min(a.min, b.min);
    res.max = max(a.max, b.max);
    if (a.min < b.min)
        res.min2 = min(a.min2, b.min);
    else if (a.min > b.min)
        res.min2 = min(a.min, b.min2);
    else
        res.min2 = a.min;
    return res;
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &st[rt].min);
        st[rt].max = st[rt].min;
        st[rt].min2 = INF;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson), build(Rson);
    st[rt] = get(st[lson], st[rson]);
}
void update(int x, int val, int l, int r, int rt)
{
    if (l == r)
    {
        st[rt].min = st[rt].max = val;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, val, Lson);
    else
        update(x, val, Rson);
    st[rt] = get(st[lson], st[rson]);
}
tree query(int x, int y, int l, int r, int rt)
{
    if (x <= l && y >= r)
        return st[rt];
    int m = (l + r) >> 1;
    if (y <= m)
        return query(x, y, Lson);
    if (x > m)
        return query(x, y, Rson);
    return get(query(x, y, Lson), query(x, y, Rson));
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    int op, i, j;
    while (m--)
    {
        scanf("%d%d%d", &op, &i, &j);
        if (op == 0)
            update(i, j, 1, n, 1);
        else if (op == 1)
        {
            if (j - i + 1 < 3)
                printf("llsml!\n");
            else
            {
                tree ans = query(i, j, 1, n, 1);
                // cout << ans.min << ' ' << ans.min2 << ' ' << ans.max << endl;
                if (ans.min + ans.min2 <= ans.max)
                    printf("llsml!\n");
                else
                    printf("llsnb!\n");
            }
        }
    }
    return 0;
}