#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int a[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    int n, m;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        int id = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            if (a[i] != -1)
                id = i;
        }
        for (int i = id + 1; i <= n; ++i)
            a[i] = (a[i - 1] + 1) % m;
        for (int i = id - 1; i >= 1; --i)
            a[i] = (a[i + 1] - 1 + m) % m;
        for (int i = 1; i <= n - 1; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    return 0;
}
