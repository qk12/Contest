#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int l[maxn], s[maxn], v[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n + 1; ++i)
            scanf("%d", l + i);
        for (int i = 0; i < n + 1; ++i)
            scanf("%d", s + i);
        for (int i = 0; i < n + 1; ++i)
            scanf("%d", v + i);
        double ans = 0;
        long long sum = 0;
        for (int i = 0; i < n + 1; ++i)
        {
            if (i)
                sum += l[i];
            ans = max(ans, (sum + s[i]) * 1.0 / v[i]);
        }
        printf("%.10f\n", ans);
    }
    return 0;
}