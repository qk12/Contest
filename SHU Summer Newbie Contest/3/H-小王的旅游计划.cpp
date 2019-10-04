#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Edge
{
    int from, to, dist;
    bool operator<(const Edge &rhs) const
    {
        if (dist == rhs.dist)
            return to > rhs.to;
        return dist < rhs.dist;
    }
} edges[700005];

const int max_v = 2e5 + 5;
int fa[max_v];
int sz[max_v];
void init(int n)
{
    for (int i = 0; i <= n; ++i)
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

int ans[max_v];
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    init(n);
    int a, b, v;
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &a, &b, &v);
        edges[cnt++] = {a, b, v};
    }
    int t;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &t);
        edges[cnt++] = {i, -1, t};
    }
    sort(edges, edges + cnt);
    for (int i = 0; i < cnt; ++i)
    {
        if (edges[i].to == -1)
            ans[edges[i].from] = sz[find(1)];
        else
            unite(edges[i].from, edges[i].to);
    }
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}