#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;
const int maxn = 305;
int dis[maxn][maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dis[i][j] = (i == j) ? 0 : INF;
        for (int i = 0; i < m; ++i)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            dis[u][v] = w;
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int k = 0; k < 6; ++k)
        {
            static int s, t;
            scanf("%d%d", &s, &t);
            printf("%d\n", -dis[t][s]);
            dis[s][t] = min(dis[s][t], -dis[t][s]);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][s] + dis[s][t] + dis[t][j]);
        }
    }
    return 0;
}