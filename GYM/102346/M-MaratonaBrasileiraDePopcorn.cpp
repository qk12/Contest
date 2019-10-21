#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];

int n, c, t;
bool check(int m)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > m)
            return false;
        if (sum + a[i] <= m)
            sum += a[i];
        else
            ++cnt, sum = a[i];
    }
    return cnt <= c;
}

int main()
{
    scanf("%d%d%d", &n, &c, &t);
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        l = max(l, a[i]);
        r += a[i];
    }
    ++r;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    int ans = (l / t) + (l % t ? 1 : 0);
    printf("%d\n", ans);
    return 0;
}