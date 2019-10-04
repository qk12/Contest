#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200;
int l[maxn], r[maxn], tot;
map<ll, int> mp;

void get(ll num)
{
    if (mp.find(num) != mp.end())
        return;
    if (num == 1LL)
    {
        ++tot;
        l[tot] = r[tot] = -1;
        mp[num] = tot;
        return;
    }
    ll mid = num / 2;
    get(num - mid);
    get(mid);
    ++tot;
    l[tot] = mp[num - mid];
    r[tot] = mp[mid];
    mp[num] = tot;
}
void init()
{
    tot = -1;
    l[0] = r[0] = -1;
    mp.clear();
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        ll n;
        scanf("%lld", &n);
        get(n);
        printf("%d\n", tot + 1);
        for (int i = 0; i < tot; ++i)
            printf("%d %d\n", l[i], r[i]);
        printf("%d\n", tot);
    }
    return 0;
}