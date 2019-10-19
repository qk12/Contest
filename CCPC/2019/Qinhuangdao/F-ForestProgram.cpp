#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;
const int maxn = 3e5 + 5;

vector<int> circle_edge_num;
vector<int> G[maxn];
vector<int> edge_id[maxn];
bool vis[maxn];
int from[maxn];
int depth[maxn];
int bfs_u[maxn];
int edge_vis[500005];

ll mod_pow(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res %= mod;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        edge_id[u].push_back(i);
        edge_id[v].push_back(i);
    }
    int edge_total = m;
    for (int start = 1; start <= n; ++start)
    {
        if (vis[start])
            continue;
        vis[start] = true;
        bfs_u[0] = start;
        depth[0] = 0;
        from[start] = -1;

        int tail = 0;
        int head = 0;

        while (head <= tail)
        {
            int u = bfs_u[head];
            int dep = depth[u], from2 = from[u];
            int gusiz = G[u].size();
            ++head;
            // printf("%d from %d\n",u,from);
            for (int i = 0; i < gusiz; ++i)
            {
                int v = G[u][i];
                int eid = edge_id[u][i];
                if (v == from2)
                    continue;
                if (vis[v] && edge_vis[eid] == 0)
                {
                    int depv = depth[v];
                    edge_vis[eid] = 1;
                    int u1 = u, v1 = v, depu = dep;

                    while (depv > depu)
                    {
                        //  printf("v1 %d u1 %d\n",v1,u1);
                        v1 = from[v1];
                        --depv;
                    }
                    while (depu > depv)
                    {
                        // printf("v1 %d u1 %d\n",v1,u1);
                        u1 = from[u1];
                        --depv;
                    }
                    while (u1 != v1)
                    {
                        --depv, --depu;
                        u1 = from[u1], v1 = from[v1];
                        // printf("v1 %d u1 %d\n",v1,u1);
                    }
                    int len = dep - depu + depth[v] - depv + 1;
                    circle_edge_num.push_back(len);
                    edge_total -= len;
                }
                else if (!vis[v])
                {
                    from[v] = u;
                    vis[v] = true;
                    depth[v] = dep + 1;
                    bfs_u[++tail] = v;
                }
            }
        }
    }
    //printf("nmsl");
    ll ans = 1, siz = circle_edge_num.size();
    for (int i = 0; i < siz; ++i)
    {
        //printf("circle len %d \n",circle_edge_num[i]);
        ans = (ans * (mod_pow(2LL, (ll)circle_edge_num[i]) - 1LL)) % mod;
    }
    ans = (ans * mod_pow(2LL, (ll)edge_total)) % mod;
    printf("%lld\n", ans);
    return 0;
}