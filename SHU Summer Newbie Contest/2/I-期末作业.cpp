#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    if (n == 0)
        return res %= mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod, n >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, p;
        cin >> n >> p;
        ll ans = 0;
        ll m = min(n, p);
        for (int i = 0; i < m; ++i)
            ans = max(ans, (mod_pow(2, i, p) + mod_pow(2, n - 1 - i, p)) % p);
        cout << ans << endl;
    }
    return 0;
}
