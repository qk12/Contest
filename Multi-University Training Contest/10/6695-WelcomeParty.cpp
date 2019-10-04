#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
struct node
{
    ll a, b;
} pos[maxn];
bool cmp(const node &a, const node &b)
{
    return a.a > b.a;
}
multiset<ll> s;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        s.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld%lld", &pos[i].a, &pos[i].b);
            s.insert(pos[i].b);
        }
        sort(pos, pos + n, cmp);
        multiset<ll>::iterator it;
        ll ans = 1e18 + 10, b = -1;
        for (int i = 0; i < n; ++i)
        {
            s.erase(s.find(pos[i].b));
            ll p = pos[i].a, p1 = 0, p2 = 0;
            if (b != -1)
            {
                ans = min(ans, abs(b - p));
            }
            if (!s.empty())
            {
                it = s.lower_bound(p);
                if (it == s.end())
                {
                    --it;
                }
                p1 = p2 = *it;
                if (it != s.begin())
                {
                    --it;
                    p2 = *it;
                }
            }
            if (b > p1)
                p1 = b;
            if (b > p2)
                p2 = b;
            ans = min(ans, min(abs(p1 - p), abs(p2 - p)));
            b = max(b, pos[i].b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
