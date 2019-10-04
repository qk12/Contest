#include <bits/stdc++.h>
using namespace std;

#define lson pos << 1
#define rson pos << 1 | 1
#define Lson L, mid, lson
#define Rson mid + 1, R, rson

typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn << 2];

inline void pushup(int pos) { a[pos] = a[lson] + a[rson]; }
void build(int L, int R, int pos)
{
    if (L == R)
    {
        scanf("%lld", &a[pos]);
        return;
    }
    int mid = (L + R) >> 1;
    build(Lson), build(Rson);
    pushup(pos);
}
void update(int x, int val, int L, int R, int pos)
{
    if (L == R)
    {
        a[pos] = val;
        return;
    }
    int mid = (L + R) >> 1;
    if (x <= mid)
        update(x, val, Lson);
    else
        update(x, val, Rson);
    pushup(pos);
}
ll query(int x, int y, int L, int R, int pos)
{
    if (x <= L && y >= R)
        return a[pos];
    int mid = (L + R) >> 1;
    ll res = 0;
    if (x <= mid)
        res += query(x, y, Lson);
    if (y > mid)
        res += query(x, y, Rson);
    return res;
}

int main()
{
    int n, m;
    int x, val, l, r;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while (m--)
    {
        scanf("%d%d%d%d", &x, &val, &l, &r);
        update(x, val, 1, n, 1);
        printf("%lld\n", query(l, r, 1, n, 1));
    }
    return 0;
}