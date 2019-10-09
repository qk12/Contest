#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main()
{
    int r, s, p;
    scanf("%d%d%d", &r, &s, &p);
    int x0 = r, y0 = s + 1;
    int x, y, dis;
    while (p--)
    {
        scanf("%d%d", &x, &y);
        if (y >= s + 1)
            ++y;
        dis = abs(x0 - x) + abs(y0 - y);
        ++mp[dis];
    }
    long long last = 0;
    for (auto &it : mp)
    {
        int t = it.first, cnt = it.second;
        if (t <= last)
            last += cnt;
        else
        {
            last = t - 1;
            last += cnt;
        }
    }
    printf("%lld\n", last + 1);
    return 0;
}