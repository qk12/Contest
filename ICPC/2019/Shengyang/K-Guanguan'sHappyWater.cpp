#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll a[150];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll k, n;
        scanf("%lld%lld", &k, &n);
        for (int i = 1; i <= k * 2; ++i)
            scanf("%lld", &a[i]);
        ll sum = 0;
        if (n <= k * 2)
        {
            int sum = 0;
            for (int i = 1; i <= n; ++i)
                sum = (sum + a[i]) % mod;
        }
        else
        {
            for (int i = 1; i <= k * 2; ++i)
                sum = (sum + a[i]) % mod;
            sum = (sum + a[k * 2] * ((n - 2 * k) % mod) % mod) % mod;
        }
        printf("%lld\n", sum);
    }
    return 0;
}