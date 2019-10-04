#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int maxn = 1005;
int cnt[maxn];
bool vis[maxn];
P ans[maxn];
vector<int> G[maxn];

void dfs(int u, int d)
{
    vis[u] = true;
    ans[u] = make_pair(d, cnt[d]);
    ++cnt[d];
    for (auto &v : G[u])
    {
        if (!vis[v])
            dfs(v, d + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}