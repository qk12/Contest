#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int a[20][10];
ll mod_pow(ll a, ll b)
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

//A*B = X mod (1e9+7)
//A = X*(inv[B]) mod (1e9+7)
int n, x;
ll ans;
unordered_map<ll, int> mp;
void dfs(int s, int e, bool flag, ll state)
{
    if (s == e)
    {
        if (flag)
            ++mp[state];
        else
            ans += mp[x * mod_pow(state, mod - 2) % mod];
    }
    else
    {
        for (int j = 1; j <= 6; ++j)
        {
            dfs(s + 1, e, flag, state * a[s + 1][j] % mod);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= 6; ++j)
                cin >> a[i][j];
        int m = n / 2;
        dfs(0, m, true, 1);
        dfs(m, n, false, 1);
        cout << ans << endl;
        ans = 0;
        mp.clear();
    }
    return 0;
}