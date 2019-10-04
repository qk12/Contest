#include <bits/stdc++.h>
using namespace std;

typedef long long ll; //long long类型的无穷大为1e18
const int max_v = 1e4 + 5;

struct Edge
{
    int from, to;
    ll dist;
    Edge() {}
    Edge(int u, int v, ll d) : from(u), to(v), dist(d) {}
};
struct HeapNode
{
    ll dist;
    int u;
    bool operator<(const HeapNode &rhs) const { return dist > rhs.dist; }
};
struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool vis[max_v];
    ll dis[max_v];
    int p[max_v];
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
            dis[i] = 1e18; //注意
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
                    p[e.to] = id;
                    q.push({dis[e.to], e.to});
                }
            }
        }
    }
} D1, D2;

namespace Flow
{
struct Edge
{
    int from, to;
    ll cap, flow;
    Edge(int u, int v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool vis[max_v];
    ll d[max_v];
    int cur[max_v];
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, int cap)
    {
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, 0, 0);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool bfs()
    {
        memset(vis, 0, sizeof(vis)), memset(d, 0, sizeof(d));
        queue<int> q;
        q.push(s);
        d[s] = 0, vis[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, ll a)
    {
        if (x == t || a == 0)
            return a;
        ll flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    ll max_flow(int s, int t)
    {
        this->s = s, this->t = t;
        ll flow = 0;
        while (bfs())
        {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, 1e18);
        }
        return flow;
    }
} D;
} // namespace Flow

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Edge> edges;
        D1.init(n), D2.init(n);
        int u, v, w;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            D1.AddEdge(u, v, w);
            D2.AddEdge(v, u, w);
            edges.emplace_back(u, v, w);
        }
        D1.dijkstra(0);
        D2.dijkstra(n - 1);
        Flow::D.init(n);
        for (auto &e : edges)
        {
            if (D1.dis[e.from] + D2.dis[e.to] + e.dist == D1.dis[n - 1])
                Flow::D.addedge(e.from, e.to, e.dist);
        }
        printf("%lld\n", Flow::D.max_flow(0, n - 1));
    }
    return 0;
}