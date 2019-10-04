#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 2e5 + 5;
int ans[maxn];
bool vis[maxn];
struct node
{
    int val, id, page;
    bool operator<(const node &a) const
    {
        if (val == a.val)
            return id < a.id;
        return val < a.val;
    }
} query[maxn * 2];

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0, a;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        query[cnt++] = {a, -1, i};
    }
    vis[0] = vis[n + 1] = true;
    int q, x;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &x);
        query[cnt++] = {x, i, -1};
    }
    int cur = 1;
    sort(query, query + cnt);
    for (int i = 0; i < cnt; ++i)
    {
        if (query[i].id == -1)
        {
            int p = query[i].page;
            vis[p] = true;
            if (!vis[p - 1] && !vis[p + 1])
                ++cur;
            if (vis[p - 1] && vis[p + 1])
                --cur;
        }
        else
            ans[query[i].id] = cur;
    }
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}