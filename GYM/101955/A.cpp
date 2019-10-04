#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll n, ll k)
{
    int pos = 1;
    for (ll i = 2; i <= n; ++i)
    {
        pos = (pos + k) % i;
    }
    return pos;
}

int main()
{
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--)
    {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        printf("%d\n", ++kase);
    }
    return 0;
}