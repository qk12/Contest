#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
struct BIT
{
    ll n, bit[maxn];
    int lowbit(int x) { return x & -x; }
    void add(int pos, ll x)
    {
        while (pos <= n)
            bit[pos] += x, pos += lowbit(pos);
    }
    ll query(int pos) //区间[1,pos]的和
    {                 //[x,y]: sum(y) - sum(x - 1);
        ll res = 0;
        while (pos > 0)
            res += bit[pos], pos -= lowbit(pos);
        return res;
    }
} B1, B2;
ll a[maxn];

int main()
{
    ll n, q;
    scanf("%lld%lld", &n, &q);
    B1.n = B2.n = n;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        B1.add(i, a[i]);
        B2.add(i, a[i] * (n - i + 1));
    }
    while (q--)
    {
        static int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 2)
        {
            ll temp = r - a[l];
            a[l] = r;
            B1.add(l, temp);
            B2.add(l, temp * (n - l + 1));
        }
        else
        {
            ll ans1 = B1.query(r) - B1.query(l - 1);
            ll ans2 = B2.query(r) - B2.query(l - 1);
            ll x = n - r;
            printf("%lld\n", ans2 - ans1 * x);
        }
    }
    return 0;
}