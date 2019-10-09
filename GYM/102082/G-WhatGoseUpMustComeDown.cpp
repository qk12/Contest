#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn], L[maxn], R[maxn];

struct BIT
{
    ll n = 1e5, bit[maxn];
    void init() { memset(bit, 0, sizeof(bit)); }
    int lowbit(int x) { return x & -x; }
    void add(int pos, ll x)
    {
        while (pos <= n)
            bit[pos] += x, pos += lowbit(pos);
    }
    ll query(int pos)
    {
        ll res = 0;
        while (pos > 0)
            res += bit[pos], pos -= lowbit(pos);
        return res;
    }
} B;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        B.add(a[i], 1);
        L[i] = i - B.query(a[i]);
    }
    B.init();
    for (int i = n; i >= 1; --i)
    {
        B.add(a[i], 1);
        R[i] = n - i + 1 - B.query(a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += min(L[i], R[i]);
    printf("%lld\n", ans);
    return 0;
}