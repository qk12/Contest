#include <bits/stdc++.h>
using namespace std;

const int max_v = 105;
struct Edge
{
    int from, to, dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
    bool operator<(const Edge &rhs) const { return dist < rhs.dist; }
};
struct Kruskal
{
    int n;
    int fa[max_v];
    vector<Edge> edges;
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < n; ++i)
            fa[i] = i;
        edges.clear();
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y) { fa[find(x)] = find(y); }
    bool same(int x, int y) { return find(x) == find(y); }
    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge{from, to, dist});
    }
    int kruskal()
    {
        sort(edges.begin(), edges.end());
        int res = 0, cnt = 0;
        for (auto &e : edges)
        {
            if (!same(e.from, e.to))
            {
                unite(e.from, e.to);
                ++cnt;
                res += e.dist;
            }
        }
        return cnt == n - 1 ? res : -1;
    }
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        static int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
    }
    return 0;
}