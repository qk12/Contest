#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int max_v = 4100;
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;       //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<Edge> edges;   //边表。edge[e]和edge[e^1]互为反向弧
    vector<int> G[max_v]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    bool vis[max_v];      //BFS使用
    int d[max_v];         //从起点到i的距离
    int cur[max_v];       //当前弧下标
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
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) //从上次考虑的弧
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
    int max_flow(int s, int t)
    {
        this->s = s, this->t = t;
        int flow = 0;
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
    int n, m, k, kase = 0;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        D.init(n + m + 4);
        int s = 0, t = n + m + 1;
        int S = n + m + 2, T = n + m + 3;
        D.addedge(t, s, INF);
        D.addedge(s, T, l * n);
        D.addedge(S, t, l * m);
        for (int i = 1; i <= n; ++i)
            D.addedge(s, i, r - l), D.addedge(S, i, l);
        for (int i = 1; i <= m; ++i)
            D.addedge(n + i, t, r - l), D.addedge(n + i, T, l);
        for (int i = 0, u, v; i < k; ++i)
        {
            scanf("%d%d", &u, &v);
            D.addedge(u, n + v, 1);
        }
        int flow = D.max_flow(S, T);
        printf("Case %d: ", ++kase);
        if (flow == (n + m) * l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}