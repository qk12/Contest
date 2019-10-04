#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
    int T;
    scanf("%d", &T);
    int n, x;
    while (T--)
    {
        scanf("%d", &n);
        ll ans = 1;
        while (n--)
        {
            scanf("%d", &x);
            ans = ans * (x + 1) % mod;
        }
        printf("%lld\n", (ans - 1) % mod);
    }
    return 0;
}