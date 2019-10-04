#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll mod_pow(ll a, ll b, ll mod)
{
    a %= mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res %= mod;
}

int main()
{
    int T;
    cin >> T;
    string s;
    while (T--)
    {
        cin >> s;
        ll n = 0;
        for (int i = 0; i < s.length(); ++i)
            n = (n * 10 + s[i] - '0') % (mod - 1);
        cout << mod_pow(2, n - 1, mod) << endl;
    }
    return 0;
}