#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
ll F[maxn];
void init(ll p)
{
    F[0] = 1;
    for (int i = 1; i <= p; ++i)
        F[i] = F[i - 1] * i % mod;
}
ll inv(ll n, ll p)
{
    if (n == 1)
        return 1;
    return inv(p % n, p) * (p - p / n) % p;
}
ll lucas(ll n, ll m, ll p)
{
    ll res = 1;
    while (n && m)
    {
        ll a = n % p, b = m % p;
        if (a < b)
            return 0;
        res = res * F[a] % p * inv(F[b] * F[a - b] % p, p) % p;
        n /= p, m /= p;
    }
    return res;
}
ll solve(ll x, ll y, ll z)
{
    return lucas(x + y + z, x, mod) * lucas(y + z, z, mod) % mod;
}

int main()
{
    init(3e5);

    int L, W, H;
    int x1, y1, z1, x2, y2, z2;
    cin >> L >> W >> H;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    ll ans = solve(L, W, H);
    ans -= solve(x1, y1, z1) * solve(L - x1, W - y1, H - z1) % mod;
    ans -= solve(x2, y2, z2) * solve(L - x2, W - y2, H - z2) % mod;
    ans = (ans % mod + mod) % mod;

    int x = abs(x1 - x2), y = abs(y1 - y2), z = abs(z1 - z2);
    if ((x1 >= x2 && y1 >= y2 && z1 >= z2))
    {
        ans += solve(x2, y2, z2) * solve(x, y, z) % mod * solve(L - x1, W - y1, H - z1) % mod;
    }
    else if (x1 <= x2 && y1 <= y2 && z1 <= z2)
    {
        ans += solve(x1, y1, z1) * solve(x, y, z) % mod * solve(L - x2, W - y2, H - z2) % mod;
    }
    ans = (ans % mod + mod) % mod;

    cout << ans << endl;
    return 0;
}