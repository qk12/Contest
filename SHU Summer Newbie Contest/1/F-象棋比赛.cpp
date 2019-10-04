#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int max_v = 1005;

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
    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, 0, 0});
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
};

char maze[35][35];
char newmaze[35][35];
int score[35];
int n;
void getscore()
{
    for (int i = 0; i < n; ++i)
    {
        score[i] = 0;
        for (int j = 0; j < n; ++j)
        { //为了防止平局造成非整数的流量将分数扩大一倍
            if (newmaze[i][j] == '1')
                score[i] += 2;
            else if (newmaze[i][j] == 'd')
                ++score[i];
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", maze[i]);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int ii = 0; ii < n; ii++)
        {
            for (int jj = 0; jj < n; jj++)
                newmaze[ii][jj] = maze[ii][jj];
        }
        for (int j = 0; j < n; j++) //设该选手剩余比赛全部获胜
        {
            if (newmaze[i][j] == '.')
            {
                newmaze[i][j] = '1';
                newmaze[j][i] = '0';
            }
        }
        getscore();
        bool ok = true;
        for (int j = 0; j < n; j++)
        {
            if (score[j] > score[i])
                ok = false;
        }
        if (!ok)
            continue;
        Dinic D;
        //选手编号：1~n，比赛编号：n~n+n*n
        int S = n + n * n + 1, T = S + 1;
        //每个选手向汇点 T 连边，容量为每个选手与该选手的分差
        for (int j = 0; j < n; j++)
            D.AddEdge(j, T, score[i] - score[j]);
        int tot = 0;
        //分配剩下与这位选手无关的比赛的胜负情况
        for (int ii = 0; ii < n; ii++)
        {
            for (int jj = 0; jj < ii; jj++)
            {
                if (newmaze[ii][jj] == '.')
                {
                    //源点 S 向比赛连边，容量为 2
                    D.AddEdge(S, n + ii * n + jj, 2);
                    tot += 2;
                    //每场比赛向对应的两个选手连边，容量为 ∞
                    D.AddEdge(n + ii * n + jj, ii, INF);
                    D.AddEdge(n + ii * n + jj, jj, INF);
                }
            }
        }
        //如果最大流等于剩余比赛数量（的两倍），说明存在可行的分配方案
        //即该选手有机会成为冠军
        if (D.max_flow(S, T) == tot)
            ans.push_back(i);
    }
    bool first = true;
    for (auto &u : ans)
        if (first)
        {
            printf("%d", u + 1);
            first = false;
        }
        else
            printf(" %d", u + 1);
    return 0;
}