#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200;
int le[maxn], ri[maxn];
map<ll, int> mp;
int tot = 0;

void init()
{
    tot = 1;
    le[0] = ri[0] = -1;
    mp.clear();
}
int search(ll size)
{
    if (size == 1)
        return 0;
    if (mp.find(size) != mp.end())
        return mp[size];

    ll lsz = size / 2;
    ll rsz = size - lsz;
    int left = search(rsz);
    int right = search(lsz);
    int u = tot;
    ++tot;
    le[u] = left;
    ri[u] = right;
    mp[size] = u;
    return u;
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
        int P = search(n);
        printf("%d\n", tot);
        for (int i = 0; i < tot; ++i)
        {
            printf("%d %d\n", le[i], ri[i]);
        }
        printf("%d\n", P);
    }
    return 0;
}