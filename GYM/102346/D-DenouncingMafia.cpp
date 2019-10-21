#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int maxn = 1e5 + 5;
set<P> SET;
vector<int> G[maxn];
int max_child[maxn];
int node_depth[maxn];

int dfs(int u)
{
    int id = -1, depth = 1;
    for (auto &v : G[u])
    {
        int temp = dfs(v);
        if (id == -1 || temp > depth)
        {
            id = v;
            depth = temp;
        }
    }
    max_child[u] = id;
    node_depth[u] = depth;
    return depth + 1;
}

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 2; i <= N; ++i)
    {
        int v;
        cin >> v;
        G[v].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= N; ++i)
    {
        SET.insert(P(node_depth[i], i));
    }
    int ans = 0;
    for (int i = 0; i < K; ++i)
    {
        auto it = SET.rbegin();
        int u = it->second;
        ans += it->first;
        while (u != -1) //如果u不是叶子结点
        {
            SET.erase(P(node_depth[u], u));
            u = max_child[u];
        }
    }
    printf("%d\n", ans);
    return 0;
}