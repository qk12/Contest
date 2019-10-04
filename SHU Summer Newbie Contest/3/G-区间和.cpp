#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int maxn = 1e5 + 5;
ll bit[maxn];
int n, q;
inline int lowbit(int x) { return x & -x; }
void add(int pos, int x)
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

int main()
{
    scanf("%d%d", &n, &q);
    int x;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x), add(i, x);
    int l, r;
    while (q--)
    {
        scanf("%d%d", &l, &r);
        printf("%lld\n", query(r) - query(l - 1));
    }
    return 0;
}
