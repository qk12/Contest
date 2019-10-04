#include <bits/stdc++.h>
using namespace std;
int soty[2005];
#define LL long long
#define ls p << 1
#define rs p << 1 | 1
struct fuck
{
    int x, y, w;
} sp[2002];
bool cmp(fuck a, fuck b)
{
    return a.x < b.x;
}
int cnty;
int idy(int x) { return lower_bound(soty + 1, soty + cnty + 1, x) - soty; }
struct ed
{
    LL ll, lr, lm, sum;
} tree[2003 * 3];
inline void up(int p)
{
    tree[p].sum = tree[ls].sum + tree[rs].sum;
    tree[p].ll = max(tree[ls].ll, tree[ls].sum + tree[rs].ll);
    tree[p].lr = max(tree[rs].lr, tree[rs].sum + tree[ls].lr);
    tree[p].lm = max(tree[ls].lr + tree[rs].ll, max(tree[ls].lm, tree[rs].lm));
}
void add(int l, int r, int p, int pos, LL x)
{
    if (l == r)
    {
        tree[p].lm += x;
        tree[p].sum = tree[p].ll = tree[p].lr = tree[p].lm;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        add(l, mid, ls, pos, x);
    else
        add(mid + 1, r, rs, pos, x);
    up(p);
}
long long dp[2005];
int main()
{
    int te;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> te;
    while (te--)
    {
        int n;
        cin >> n;
        cnty = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> sp[i].x >> sp[i].y >> sp[i].w;
            soty[++cnty] = sp[i].y;
        }
        sort(sp + 1, sp + 1 + n, cmp);
        sort(soty + 1, soty + 1 + cnty);
        cnty = unique(soty + 1, soty + 1 + cnty) - soty - 1;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != 1 && sp[i].x == sp[i - 1].x)
                continue;
            memset(tree, 0, sizeof tree);
            for (int j = i; j <= n; j++)
            {
                add(1, cnty, 1, idy(sp[j].y), sp[j].w);
                if (j == n || sp[j].x != sp[j + 1].x)
                {
                    //cout << i << " " << j << "\n";
                    ans = max(ans, tree[1].lm);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}