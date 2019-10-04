#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            if (gcd(i, m) == 1)
                ans = (ans + (ll)i * (i + 1) % mod) % mod;
        cout << ans << endl;
    }
    return 0;
}