#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    cout << min(a / x, b / y) << endl;
    return 0;
}