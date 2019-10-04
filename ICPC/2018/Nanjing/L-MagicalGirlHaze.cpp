// 分层图最短路
//在一张图上，有k次机会可以通过一条边而不需要计算权值（免费过路）
//求从起点到终点的最短路线
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Edge
{
    int from, to;
    ll dist;
    Edge() {}
    Edge(int u, int v, ll d) : from(u), to(v), dist(d) {}
};
struct HeapNode
{
    ll d;
    int k, u;
    bool operator<(const HeapNode &rhs) const { return d > rhs.d; }
};
const int maxn = 1e5 + 5;
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[maxn]; // 每个节点出发的边编号（从0开始编号）
    bool vis[maxn][12];  // 是否已永久标号
    ll dis[maxn][12];    // s到各点的距离
    void init(int V)
    {
        this->n = V;
        for (int i = 0; i < n; ++i)
            G[i].clear(); // 清空邻接表
        edges.clear();    // 清空边表
    }
    void AddEdge(int from, int to, int dist)
    { // 如果是无向图，每条无向边需调用两次AddEdge
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s, int k)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= k; ++j)
                dis[i][j] = 1e18;
        memset(vis, 0, sizeof(vis));
        priority_queue<HeapNode> q;
        q.push({0, 0, s});
        dis[s][0] = 0;
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u, t = x.k;
            if (vis[u][t])
                continue;
            vis[u][t] = true;
            for (auto &id : G[u])
            {
                Edge &e = edges[id];
                if (dis[e.to][t] > dis[u][t] + e.dist)
                { //没消耗免费过路权
                    dis[e.to][t] = dis[u][t] + e.dist;
                    q.push({dis[e.to][t], t, e.to});
                }
                if (t + 1 <= k)
                { //消耗了免费过路权
                    if (dis[e.to][t + 1] > dis[u][t])
                    {
                        dis[e.to][t + 1] = dis[u][t];
                        q.push({dis[e.to][t + 1], t + 1, e.to});
                    }
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
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        D.init(n);
        int u, v, w;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            D.AddEdge(u - 1, v - 1, w);
        }
        D.dijkstra(0, k);
        ll res = 1e18;
        //dis[i][j]表示到第i个点时，消耗了j次乘车权后的最短路线
        //到了终点时，可能有：用了0次、用了1次....用了k次
        for (int i = 0; i <= k; ++i)
            res = min(res, D.dis[n - 1][i]);
        printf("%lld\n", res);
    }
    return 0;
}