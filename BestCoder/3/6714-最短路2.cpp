#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int max_v = 1005;
int ans[max_v][max_v];

struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct HeapNode
{
    int dist, u;
    bool operator<(const HeapNode &rhs) const { return dist > rhs.dist; }
};
struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool vis[max_v];
    int dis[max_v];
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s)
    {
        for (int i = 0; i < n; ++i)
            dis[i] = INF;
        memset(vis, 0, sizeof(vis));
        priority_queue<HeapNode> q;
        q.push({0, s});
        dis[s] = 0;
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (vis[u])
                continue;
            vis[u] = true;
            for (auto &id : G[u])
            {
                Edge &e = edges[id];
                if (dis[e.to] > dis[u] + e.dist)
                {
                    dis[e.to] = dis[u] + e.dist;
                    q.push({dis[e.to], e.to});
                    if (dis[e.to] == e.dist)
                        ans[s][e.to] = 0;
                    else
                        ans[s][e.to] = max(ans[s][e.to], 0);
                }
            }
        }
    }
} D;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(ans, 0, sizeof(0));
        int u, v, w;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            D.AddEdge(u - 1, v - 1, w);
            D.AddEdge(v - 1, u - 1, w);
        }
        for (int i = 0; i < n; ++i)
            D.dijkstra(i);
        //ll ans = 0;
    }
    return 0;
}