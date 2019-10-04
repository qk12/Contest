#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
vector<P> G[maxn], rG[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; ++i)
        G[i].clear(), rG[i].clear();
}
inline void add_edge(int u, int v, int w)
{
    G[u].push_back(P{v, w});
    rG[v].push_back(P{u, w});
}
int d[maxn];
bool inq[maxn];
void spfa(int s) //反向求最短路
{
    memset(d, 0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (auto &e : rG[u])
        {
            int v = e.first, w = e.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                inq[v] = 1;
                q.push(v);
            }
        }
    }
}
struct HeapNode
{
    int v;
    ll g, f;
    HeapNode(int v, ll g, ll f) : v(v), g(g), f(f) {}
    bool operator<(const HeapNode &rhs) const
    {
        return rhs.f < f || (rhs.f == f && rhs.g < g);
    }
};
bool A_star(int s, int t, int k, int T)
{
    if (s == t)
        ++k;
    if (d[s] == INF)
        return false;
    priority_queue<HeapNode> q;
    int cnt = 0;
    q.push(HeapNode{s, 0, d[s]});
    while (!q.empty())
    {
        HeapNode tmp = q.top();
        q.pop();
        int u = tmp.v;
        ll g = tmp.g;
        if (u == t)
            ++cnt;
        if (cnt == k)
            return tmp.g <= T;
        for (auto &e : G[u])
        {
            int v = e.first, w = e.second;
            q.push(HeapNode{v, g + w, g + w + d[v]});
        }
    }
    return false;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init(n);
        int s, t, k, T;
        scanf("%d%d%d%d", &s, &t, &k, &T);
        --s, --t;
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u - 1, v - 1, w);
        }
        spfa(t);
        if (A_star(s, t, k, T))
            printf("yareyaredawa\n");
        else
            printf("Whitesnake!\n");
    }
    return 0;
}
