#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 5e4 + 5;
P a[maxn];

int main(
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) //不存在包含关系
    {
        scanf("%d%d", &a[i].X, &a[i].Y);
    }
    set<P> s; //ss;
    s.insert({0, INF});
    s.insert({INF, 0});
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        P &point = a[i];
        //if (ss.find(point) != ss.end()) //判断是否是重复点
        //continue;
        //ss.insert(point);
        auto p = s.lower_bound(point);
        auto q = p;
        --q;
        if (point.Y > p->Y && point.X > q->X)
        {
            ll dx = point.X - q->X;
            ll dy = point.Y - p->Y;
            ans += dx + dy;
            s.insert(point);
        }
    }
    printf("%lld\n", ans);
}