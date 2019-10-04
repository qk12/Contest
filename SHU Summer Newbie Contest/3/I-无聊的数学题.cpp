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

ll l, r, k;
vector<ll> d;
ll solve(ll n)
{
    if (n <= 0)
        return 0;
    ll ans = 0;
    for (int i = 0; i < (1 << d.size()); i++)
    {
        int cnt = __builtin_popcount(i);
        ll cur = 1;
        for (int j = 0; j < d.size(); j++)
        {
            if (i >> j & 1)
                cur *= d[j];
        }
        if (!(cnt & 1))
            ans += n / cur;
        else
            ans -= n / cur;
    }
    return ans;
}
int main()
{
    cin >> l >> r >> k;
    k <<= 1;
    r -= k;
    if (l > r)
    {
        cout << 0 << endl;
        return 0;
    }
    for (ll i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
            d.push_back(i);
        while (k % i == 0)
            k /= i;
    }
    if (k != 1)
        d.push_back(k);
    sort(d.begin(), d.end());
    cout << solve(r) - solve(l - 1) << endl;
    return 0;
}