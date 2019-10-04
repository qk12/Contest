#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], x[maxn], y[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        x[1] = a[1], y[n] = a[n];
        for (int i = 2; i <= n; ++i)
            x[i] = max(a[i], x[i - 1]);
        for (int i = n - 1; i >= 1; --i)
            y[i] = min(a[i], y[i + 1]);
        int cnt = 0;
        for (int i = 2; i < n; ++i)
            if (x[i - 1] <= a[i] && a[i] <= y[i + 1])
                ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}