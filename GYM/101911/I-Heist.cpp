#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[1005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    ll ans = a[n] - a[1] + 1 - n;
    printf("%lld\n", ans);
    return 0;
}