#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int maxn = 2e5 + 10;
int a[maxn], ans[maxn];

set<P> s;

int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        s.insert(P(a[i], i));
    }
    int day = 1;
    while (!s.empty())
    {
        P p = *s.begin();
        s.erase(s.begin());
        ans[p.second] = day;
        auto it = s.lower_bound(P(p.first + d + 1, 0));
        while (it != s.end())
        {
            p = *it;
            s.erase(it);
            ans[p.second] = day;
            it = s.lower_bound(P(p.first + d + 1, 0));
        }
        ++day;
    }
    printf("%d\n", day - 1);
    for (int i = 0; i < n - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n - 1]);
    return 0;
}