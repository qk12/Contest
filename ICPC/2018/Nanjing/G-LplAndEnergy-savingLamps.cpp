#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
ll a[maxn << 2];
inline void pushup(int rt) { a[rt] = min(a[lson], a[rson]); }
void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%lld", &a[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson), build(Rson);
    pushup(rt);
}
void update(int x, int l, int r, int rt)
{
    if (l == r)
    {
        a[rt] = INF;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, Lson);
    else
        update(x, Rson);
    pushup(rt);
}

bool flag;
P query(int x, int y, int val, int l, int r, int rt)
{
    if (l == r)
    {
        flag = true;
        return P{l, a[rt]};
    }
    int m = (l + r) >> 1;
    if (x <= m && a[lson] <= val)
        return query(x, y, val, Lson);
    if (y > m && a[rson] <= val)
        return query(x, y, val, Rson);
    return P{0, 0};
}
int rep[maxn], rem[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    int cnt = 0, day = 1, now = 0;
    for (; day <= 100000; ++day)
    {
        now += m;
        int pos = 1;
        while (pos <= n)
        {
            flag = false;
            P res = query(pos, n, now, 1, n, 1);
            if (flag)
            {
                ++cnt;
                pos = res.first;
                now -= res.second;
                update(pos, 1, n, 1);
                ++pos;
            }
            else
                break;
        }
        rep[day] = cnt;
        rem[day] = now;
        if (cnt == n)
            break;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int d;
        scanf("%d", &d);
        d = min(d, day);
        printf("%d %d\n", rep[d], rem[d]);
    }
    return 0;
}
