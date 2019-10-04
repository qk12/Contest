#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, p, q, m;
unsigned int SA, SB, SC;
stack<ll> s;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

ll gen()
{
    ll ans = 0;
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for (int i = 1; i <= n; ++i)
    {
        if (rng61() % (p + q) < p)
        {
            if (s.empty())
                s.push(rng61() % m + 1);
            else
                s.push(max((rng61() % m + 1), (unsigned int)s.top()));
        }
        else
        {
            if (!s.empty())
                s.pop();
        }
        if (!s.empty())
            ans ^= 1LL * (i * s.top());
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        while (!s.empty())
            s.pop();
        ll ans = gen();
        printf("Case #%d: %lld\n", k, ans);
    }
    return 0;
}