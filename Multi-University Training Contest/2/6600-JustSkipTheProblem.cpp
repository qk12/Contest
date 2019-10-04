#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e6 + 3;
ll a[mod];

int main()
{
    a[0] = 1;
    for (int i = 1; i < mod; ++i)
        a[i] = a[i - 1] * i % mod;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", n < mod ? a[n] : 0LL);
    }
    return 0;
}