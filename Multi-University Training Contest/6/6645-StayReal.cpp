#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
ll h[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll sum1 = 0, sum2 = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", h + i);
        sort(h, h + n);
        for (int i = n - 1; i >= 0; i -= 2)
            sum1 += h[i];
        for (int i = n - 2; i >= 0; i -= 2)
            sum2 += h[i];
        printf("%lld %lld\n", sum1, sum2);
    }
    return 0;
}