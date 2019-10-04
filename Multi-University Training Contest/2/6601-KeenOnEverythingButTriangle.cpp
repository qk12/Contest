#include <bits/stdc++.h>
using namespace std;

#define Lson l, m, lson[x], lson[y]
#define Rson m + 1, r, rson[x], rson[y]

const int maxn = 1e5 + 5;
int a[maxn], rt[maxn];
int cnt;
int lson[maxn << 5], rson[maxn << 5], sum[maxn << 5];
void update(int pos, int l, int r, int &x, int y)
{
    lson[++cnt] = lson[y], rson[cnt] = rson[y], sum[cnt] = sum[y] + 1, x = cnt;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (pos <= m)
        update(pos, Lson);
    else
        update(pos, Rson);
}
int query(int l, int r, int x, int y, int k)
{
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    int s = sum[lson[y]] - sum[lson[x]];
    if (s >= k)
        return query(Lson, k);
    else
        return query(Rson, k - s);
}

vector<int> v;
inline int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int kth(int l, int r, int k, int n)
{
    return v[query(1, n, rt[l - 1], rt[r], k) - 1];
}

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) != EOF)
    {
        v.clear(), cnt = 0;
        rt[0] = sum[0] = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i), v.push_back(a[i]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; ++i)
            update(getid(a[i]), 1, n, rt[i], rt[i - 1]);
        int l, r;
        while (q--)
        {
            scanf("%d%d", &l, &r);
            if (r - l + 1 < 3)
            {
                printf("-1\n");
                continue;
            }
            vector<int> t;
            bool flag = false;
            for (int i = r - l + 1, j = 0; i >= 1; --i, ++j)
            {
                t.push_back(kth(l, r, i, n));
                if (t.size() >= 3)
                {
                    if (t[j - 2] < t[j - 1] + t[j])
                    {
                        printf("%lld\n", 1LL * t[j] + t[j - 1] + t[j - 2]);
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
                printf("-1\n");
        }
    }
    return 0;
}