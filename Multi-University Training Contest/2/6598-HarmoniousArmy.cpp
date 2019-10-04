//具体来说，要把这些东西分成两个部分，相当于在图中求最小割
//这样点要么和源点在一个部分，要么和汇点在一个部分，恰好对应分成两个部分

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int max_v = 2e5 + 5;

struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[max_v];
    bool vis[max_v];
    int d[max_v];
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
    int dfs(int x, int a)
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
            flow += dfs(s, INF);
        }
        return flow;
    }
} D;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        D.init(n + 2);
        int s = 0, t = n + 1;
        ll res = 0;
        int u, v, a, b, c;
        while (m--)
        {
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &c);
            res += (a + b + c) * 2;
            D.addedge(u, v, a / 2 + c / 3);
            D.addedge(v, u, a / 2 + c / 3);
            D.addedge(s, u, a + a / 4 + c / 3);
            D.addedge(s, v, a + a / 4 + c / 3);
            D.addedge(u, t, a / 4 + c + c / 3);
            D.addedge(v, t, a / 4 + c + c / 3);
        }
        printf("%lld\n", (res - D.max_flow(s, t)) / 2);
    }
}