#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int bad[maxn], a[maxn], cnt[maxn];
struct node
{
    int x, y;
} s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        s[i].x = s[i].y = 1;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i + 1] >= a[i])
            s[i].x = s[i + 1].x + 1;
        else
            s[i].y = s[i + 1].y + 1;
    }
    for (int k = 2; k <= n; ++k)
    {
        int i = 1;
        while (i <= n)
        {
            int p = max(s[i].x, s[i].y);
            if (p < k)
            {
                bad[k] += min(n, i + k - 1) - i + 1 - p;
                i += k;
            }
            else
            {
                i += p;
            }
            ++cnt[k];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        printf("%d %d\n", cnt[x], bad[x]);
    }
    return 0;
}