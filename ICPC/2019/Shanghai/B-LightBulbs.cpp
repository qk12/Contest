#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int maxn = 2005;
P p[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        static int n, m;
        scanf("%d%d", &n, &m);
        int tot = 0;
        while (m--)
        {
            static int l, r;
            scanf("%d%d", &l, &r);
            p[tot++] = P(l, 1);
            p[tot++] = P(r + 1, -1);
        }
        sort(p, p + tot);
        int pos = 0, ans = 0, cnt = 0;
        for (int i = 0; i < tot; ++i)
        {
            if (pos != p[i].first)
            {
                if (cnt % 2 == 1) //覆盖奇数次
                    ans += p[i].first - pos;
                pos = p[i].first;
            }
            cnt += p[i].second;
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}