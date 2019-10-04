#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mat[100005][105], up[105];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, K;
        scanf("%d%d%d", &n, &m, &K);
        memset(mat, 0, sizeof(mat));
        memset(up, 0, sizeof(up));
        int x, y;
        for (int i = 0; i < K; ++i)
        {
            scanf("%d%d", &x, &y);
            mat[x][y] = 1;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                if (mat[i][j])
                    up[j] = i;
            for (int j = 1; j <= m; ++j)
            {
                int h = i;
                for (int k = j; k >= 1; --k)
                {
                    h = min(h, i - up[k]);
                    ans += h;
                }
            }
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}