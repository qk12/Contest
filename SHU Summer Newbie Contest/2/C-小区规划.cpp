#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int max_v = 15;

int dis[max_v][max_v];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                dis[i][j] = INF;
            else
                dis[i][j] = 0;
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
            ans += dis[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << dis[i][j] << ' ';
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}
