#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int mod = 1e9 + 7;
ll mod_pow(ll x, ll n)
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
    ll a, b;
    cin >> a >> b;
    ll ans = mod_pow(mod_pow(a, 2 * b - 1), mod - 2);
    ans = ans * mod_pow(2, mod - 2) % mod;
    ll temp1 = 1, temp2 = 1;
    for (ll i = 2 * b - 2; i >= 2; i -= 2)
    {
        temp1 = temp1 * (i - 1) % mod;
        temp2 = temp2 * i % mod;
    }
    ans = ans * temp1 % mod * mod_pow(temp2, mod - 2) % mod;
    cout << ans << endl;
    return 0;
}