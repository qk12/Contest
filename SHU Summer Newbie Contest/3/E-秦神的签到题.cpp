#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
int pos[maxn];

int main()
{
    int n, x;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        ans = (ans + 1LL * (i - pos[x]) * (n - i + 1) % mod * x % mod) % mod;
        pos[x] = i;
    }
    printf("%lld\n", ans);
    return 0;
}
