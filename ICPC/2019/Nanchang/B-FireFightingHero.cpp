#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int max_v = 1005;
struct Edge
{
    int from, to, dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct HeapNode
{
    ll dist, u;
    bool operator<(const HeapNode &rhs) const { return dist > rhs.dist; }
};
struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool vis[max_v];
    ll dis[max_v];
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i <= n; ++i)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        G[from].push_back(edges.size() - 1);
    }
    void dijkstra(int s)
    {
        for (int i = 0; i <= n; ++i)
            dis[i] = (ll)1e18, vis[i] = false;
        priority_queue<HeapNode> q;
        q.push({0, s});
        dis[s] = 0;
        while (!q.empty())
        {
            auto x = q.top();
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
                }
            }
        }
    }
} D;

bool fighter[max_v];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int V, E, S, K, C;
        scanf("%d%d%d%d%d", &V, &E, &S, &K, &C);
        D.init(V);
        memset(fighter, 0, sizeof(fighter));
        for (int i = 0; i < K; ++i)
        {
            static int x;
            scanf("%d", &x);
            fighter[x - 1] = true;
        }
        while (E--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            D.AddEdge(u - 1, v - 1, w);
            D.AddEdge(v - 1, u - 1, w);
        }
        D.dijkstra(S - 1);
        int hero = *max_element(D.dis, D.dis + V);
        for (int i = 0; i < V; ++i)
            if (fighter[i])
            {
                D.AddEdge(i, V, 0);
                D.AddEdge(V, i, 0);
            }
        D.dijkstra(V);
        int fft = *max_element(D.dis, D.dis + V);
        if (fft * C < hero)
            printf("%d\n", fft);
        else
            printf("%d\n", hero);
    }
    return 0;
}