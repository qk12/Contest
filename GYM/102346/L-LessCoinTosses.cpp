#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans <<= 1;
        }
        n >>= 1;
    }
    cout << ans << endl;
    return 0;
}