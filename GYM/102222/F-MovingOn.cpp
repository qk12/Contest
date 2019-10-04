#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dis[205][205];
int ans[21000];
int n, q;
struct node
{
    int u, v; //起点、终点
    int id;
    int r;
} a[21000];
bool cmp(const node &x, const node &y)
{
    if (x.r == y.r)
        return x.id < y.id;
    return x.r < y.r;
}
void updata(int k)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = (i == j) ? 0 : INF;
        for (int i = 0; i < n; ++i)
        {
            a[i].u = i + 1;
            a[i].id = 0;
            scanf("%d", &a[i].r);
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &dis[i][j]);
            }
        for (int i = n; i < n + q; ++i)
        {
            scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].r);
            a[i].id = i - n + 1;
        }
        sort(a, a + n + q, cmp);
        for (int i = 0; i < n + q; ++i)
        {
            if (a[i].id > 0)
            {
                ans[a[i].id] = dis[a[i].u][a[i].v];
            }
            else
            {
                updata(a[i].u);
            }
        }
        printf("Case #%d:\n", k);
        for (int i = 1; i <= q; ++i)
        {
            if (ans[i] == INF)
                printf("0\n");
            else
                printf("%d\n", ans[i]);
        }
    }
    return 0;
}
