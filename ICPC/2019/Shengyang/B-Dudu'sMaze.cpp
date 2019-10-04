#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
vector<int> edges[maxn];
bool monster[maxn];

int fa[maxn], sz[maxn];
void init(int n)
{
    for (int i = 0; i < n; ++i)
        fa[i] = i, sz[i] = 1;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
    {
        sz[x] += sz[y];
        fa[y] = x;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        init(n);
        for (int i = 0; i < n; ++i)
            edges[i].clear(), monster[i] = false;
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edges[u - 1].push_back(v - 1);
            edges[v - 1].push_back(u - 1);
        }
        for (int i = 0; i < k; ++i)
        {
            int u;
            scanf("%d", &u);
            monster[u - 1] = true;
        }
        for (int u = 0; u < n; ++u)
        {
            if (monster[u])
                continue;
            for (auto &v : edges[u])
            {
                if (monster[v])
                    continue;
                unite(u, v);
            }
        }
        int d0 = find(0);
        double res = 0;
        for (int u = 0; u < n; ++u)
        {
            if (!monster[u])
                continue;
            bool ok = false;
            for (auto &v : edges[u])
                if (find(v) == d0)
                {
                    ok = true;
                    break;
                }
            if (!ok)
                continue;
            ll sum = 0;
            for (auto &v : edges[u])
            {
                if (monster[v])
                    continue;
                int d = find(v);
                if (d != d0)
                    sum += sz[d];
            }
            res = max(res, double(sum) / edges[u].size());
        }
        printf("%.6f\n", res + sz[d0]);
    }
    return 0;
}